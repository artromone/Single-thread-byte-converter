#ifndef TESTSOURCE_H
#define TESTSOURCE_H
#include <vector>
#include "source.h"
class ExampleSource: public Source
{
public:
  explicit ExampleSource(const std::vector< std::uint8_t > &data):
    data_(data),
    index_(0)
  {
  }
  bool hasDataNext() const override
  {
    return index_ < data_.size();
  }
  std::uint8_t read() override
  {
    std::uint8_t byte = data_[index_];
    ++index_;
    return byte;
  }
private:
  std::vector< std::uint8_t > data_;
  std::size_t index_;
};
#endif
