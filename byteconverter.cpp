#include <stdexcept>
#include "byteconverter.h"
ByteConverter::ByteConverter(Source *source, Sink *sink):
  source_(source),
  sink_(sink),
  isRunning_(false)
{
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
    if (!source_ || !sink_)
    {
      throw std::runtime_error("Invalid pointers: source_ or sink_");
    }
    if (source_->hasDataNext())
    {
      std::this_thread::yield();
      continue;
    }
    std::uint8_t byte = source_->read();
    //std::string convertedData = convertByteToString(byte);
    //sink_->writeData(convertedData);
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
