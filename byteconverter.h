#ifndef BYTECONVERTER_H
#define BYTECONVERTER_H
#include "source.h"
#include "sink.h"
class ByteConverter
{
private:
  Source *source_;
  Sink *sink_;
};
#endif
