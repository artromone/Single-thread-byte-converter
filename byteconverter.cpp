#include <stdexcept>
#include <iostream>
#include "byteconverter.h"
namespace
{
  std::uint8_t getType(std::uint8_t byte)
  {
    return (byte & 0b11000000) >> 6;
  }
  std::uint8_t getData(std::uint8_t byte)
  {
    return byte & 0b00111111;
  }
  std::string convertByteToString(std::uint8_t byte)
  {
    std::uint8_t type = getType(byte);
    std::uint8_t data = getData(byte);
    std::string result;
    switch (type)
    {
      case 0b00:
        result = std::to_string(static_cast<unsigned int>(data));
        break;
      case 0b01:
        result = std::to_string(static_cast<int>(data));
        break;
      case 0b10:
        result = static_cast<char>(0b000000 + data);
        break;
      default:
        result = "Unknown type";
        break;
    }
    return result;
  }
}
ByteConverter::ByteConverter(Source *source, Sink *sink):
  source_(source),
  sink_(sink),
  isRunning_(false)
{
  if (!source_ || !sink_)
  {
    throw std::runtime_error("Invalid pointers: source_ or sink_");
  }
}
void ByteConverter::start()
{
  isRunning_ = true;
  thread_ = std::thread(&ByteConverter::run, this);
}
void ByteConverter::run()
{
  while (isRunning_)
  {
    if (!source_->hasDataNext())
    {
      continue;
    }
    try
    {
      std::uint8_t byte = source_->read();
      std::string convertedData = convertByteToString(byte);
      sink_->writeData(convertedData);
    }
    catch (const std::exception &ex)
    {
      std::cerr << "Error occurred while data processing: " << ex.what() << "\n";
    }
  }
}
void ByteConverter::stop()
{
  isRunning_ = false;
  if (thread_.joinable())
  {
    thread_.join();
  }
}
