#ifndef SOURCE_H
#define SOURCE_H
#include <cstdint>
#include <atomic>
class Source
{
public:
  virtual ~Source() = default;
  virtual bool hasDataNext() const = 0;
  virtual std::uint8_t read() = 0;
};
#endif
