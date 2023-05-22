#ifndef SOURCE_H
#define SOURCE_H
#include <cstdint>
class Source
{
public:
  bool empty();
  std::uint8_t read();
};
#endif
