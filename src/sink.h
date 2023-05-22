#ifndef SINK_H
#define SINK_H
class Sink
{
public:
  virtual void writeData(const std::string &data) = 0;
};
#endif
