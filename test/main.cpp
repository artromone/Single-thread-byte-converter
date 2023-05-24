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
  std::vector<std::pair<std::string, std::uint8_t>> testData = {
    {"d", 0b10000011},
    {"4", 0b01000100},
    {"Unknown type", 0b10011100}
  };
  int size = static_cast< int >(testData.size());
  MockSource source;
  MockSink sink;
  EXPECT_CALL(source, hasDataNext())
    .Times(::testing::AtLeast(size))
    .WillRepeatedly(::testing::InvokeWithoutArgs([&]()
      {
        static int callCount = 0;
        return (++callCount <= size);
      }));
  EXPECT_CALL(source, read())
    .Times(size)
    .WillRepeatedly(::testing::Invoke([&testData]()
      {
        static size_t index = 0;
        return testData[index++].second;
      }));
  EXPECT_CALL(sink, writeData(::testing::_))
    .Times(size)
    .WillRepeatedly(::testing::Invoke([&](const std::string &data)
      {
        static size_t index = 0;
        EXPECT_EQ(data, testData[index++].first);
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
