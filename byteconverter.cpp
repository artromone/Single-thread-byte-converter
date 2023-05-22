#include "byteconverter.h"
ByteConverter::ByteConverter(Source *source, Sink *sink):
  source_(source),
  sink_(sink),
  isRunning_(false)
{
}
void ByteConverter::start()
{
  thread_ = std::thread(&ByteConverter::run, this);
  isRunning_ = true;
}
void ByteConverter::run()
{
  while (isRunning_)
  {
    if (source_->empty())
    {
      std::this_thread::yield();
      continue;
    }
    std::uint8_t byte = source_->read();
    //std::string convertedData = convertByteToString(byte);
    //sink_->writeData(convertedData);
  }
}
