#ifndef BYTECONVERTER_H
#define BYTECONVERTER_H
#include <thread>
#include "source.h"
#include "sink.h"
class ByteConverter
{
public:
  explicit ByteConverter(Source *source, Sink *sink);
  void start();
  void stop();
private:
  Source *source_;
  Sink *sink_;
  bool isRunning_;
  std::thread thread_;
  void run();
};
#endif
