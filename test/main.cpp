#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <thread>
#include "../src/source.h"
#include "../src/sink.h"
#include "../src/byteconverter.h"
class MockSource: public Source
{
public:
  MOCK_CONST_METHOD0(hasDataNext, bool());
  MOCK_METHOD0(read, std::uint8_t());
};
class MockSink: public Sink
{
public:
  MOCK_METHOD1(writeData, void(const std::string&));
};
TEST(ByteConverterTest, ConvertBytes)
{
  std::vector< std::uint8_t > inputData = {0b10000011, 0b01000100, 0b10011100};
  std::vector< std::string > expectedOutput = {"d", "4", "Unknown type"};
  MockSource source;
  MockSink sink;
  int size = static_cast<int>(inputData.size());
  EXPECT_CALL(source, hasDataNext())
    .Times(size)
    .WillRepeatedly(::testing::Return(true));
  EXPECT_CALL(source, read())
    .Times(size)
    .WillOnce(::testing::Return(inputData[0]))
    .WillOnce(::testing::Return(inputData[1]))
    .WillOnce(::testing::Return(inputData[2]));
  EXPECT_CALL(sink, writeData(::testing::_))
    .Times(size)
    .WillOnce(::testing::Invoke([&](const std::string &data)
      {
        EXPECT_EQ(data, expectedOutput[0]);
      }))
    .WillOnce(::testing::Invoke([&](const std::string &data)
      {
        EXPECT_EQ(data, expectedOutput[1]);
      }))
    .WillOnce(::testing::Invoke([&](const std::string &data)
      {
        EXPECT_EQ(data, expectedOutput[2]);
      }));
  ByteConverter converter(&source, &sink);
  converter.start();
  std::this_thread::sleep_for(std::chrono::milliseconds(10));
  converter.stop();
}
int main(int argc, char *argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
