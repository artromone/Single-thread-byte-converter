#ifndef BYTECONVERTERTEST_H
#define BYTECONVERTERTEST_H
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "source.h"
#include "sink.h"
#include "byteconverter.h"
class MockSource: public Source
{
public:
  MOCK_CONST_METHOD0(hasData, bool());
  MOCK_METHOD0(readByte, std::uint8_t());
  bool hasDataNext() const override
  {
    return hasData();
  }
  std::uint8_t read() override
  {
    return readByte();
  }
};
class MockSink: public Sink
{
public:
  MOCK_METHOD1(writeData, void( const std::string&));
};
TEST(ByteConverterTest, ConvertBytes)
{
  std::vector< std::uint8_t > inputData = {0b00001011, 0b01000100, 0b10011100};
  std::vector< std::string > expectedOutput = {"k", "4", "Unknown type"};
  MockSource source;
  MockSink sink;
  EXPECT_CALL(source, hasData()).Times(static_cast<int>(inputData.size()) + 1)
    .WillRepeatedly(::testing::Return(true));
  EXPECT_CALL(source, readByte()).Times(static_cast<int>(inputData.size()))
    .WillRepeatedly(::testing::Invoke([&]()
                                      {
                                        static std::size_t index = 0;
                                        return inputData[index++];
                                      })
    );
  EXPECT_CALL(sink, writeData(::testing::_)).Times(static_cast<int>(inputData.size()))
    .WillRepeatedly(::testing::Return());
  ByteConverter converter(&source, &sink);
  converter.start();
  std::this_thread::sleep_for(std::chrono::milliseconds(10));
  converter.stop();
}
#endif
