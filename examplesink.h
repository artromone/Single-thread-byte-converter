#ifndef EXAMPLESINK_H
#define EXAMPLESINK_H
#include <iostream>
#include "sink.h"
class ExampleSink: public Sink
{
public:
  void writeData(const std::string &data) override
  {
    std::cout << data << std::endl;
  }
};
#endif
