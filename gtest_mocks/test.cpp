/***********************************************************************
 * @name TrxProfile-test.cpp
 * @Author Daniel Medina - dmedinav

 ************************************************************************/
#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "ss_mocks.h"

#include <libgen.h>
#include <unistd.h>
#include <cstring>
#include <string>
#include <sstream>
#include <gsl/gsl>


using ::testing::_;
using ::testing::Mock;
using ::testing::Return;
using ::testing::StrictMock;

std::unique_ptr<StrictMock<Mocks>> Mocks::g_MockObjPtr{};


class TestUpdateName
{
protected:
  ~TestUpdateName() = default;

  void SetUp()
  {
    using namespace smartsettings::ethapi;
    vsomeip_app = vsomeip::runtime::get()->create_application("AppService");
  }
  void TearDown()
  {
  }
};


ADD_GENERIC_MOCKTEST(OffboardJson);
ADD_CUSTOM_MOCKTEST(PrsnlProfileUpdateNameTest, TestUpdateName);

TEST_F(OffboardJson, BasicJason)
{

  std::string const test_data({10, 0, 0, 0});
  EXPECT_CALL(*jlr::Mocks::g_MockObjPtr,
              SetModelSignalBuffer("X", test_data, 4, 3, 0xFF))
      .Times(1);

  std::string const test_data2({5, 0, 0, 0});
  EXPECT_CALL(
      *jlr::Mocks::g_MockObjPtr,
      SetModelSignalBuffer("Y", test_data2, 4, 3, 0xFF))
      .Times(1);

  JsonGetDataReceived = nlohmann::json::parse(
      "{"
      "\"domainName\":\"X\","
      "\"domains\":[],"
      "\"settings\":"
      "["
      "{"
      "\"name\":\"X\","
      "\"value\": 10"
      "},"
      "{"
      "\"name\":\"Y\","
      "\"value\":5"
      "}"
      "]"
      "}");

  Run(0);
}

