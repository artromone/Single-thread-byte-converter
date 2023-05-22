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
  //
}
