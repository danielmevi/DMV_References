/***********************************************************************
 * @name ss_mocks.h
 * @Author Daniel Medina - dmedinav
 *
 * Mocks for free functions
 ************************************************************************/

#ifndef SS_MOCKS_H
#define SS_MOCKS_H

#include "gmock/gmock.h"

#include <string>

using ::testing::StrictMock;

// Gmock infrastructure

class Mocks
{
public:
  ////////////////////////////////////////////////////////////////////////////
  // Mock Interface instrumentation
  ////////////////////////////////////////////////////////////////////////////

  MOCK_METHOD8(Get_Command_Func,
               uint32_t(uint8_t*, std::string const, std::string const,
                        std::string const, std::string const, std::string const,
                        std::string const, std::string const));

  // Mock pointer cross tests and mock implementation
  static std::unique_ptr<StrictMock<Mocks>> g_MockObjPtr;
};

///////////////////////////////////////////////////////////////////////////////
// MockTest Base
///////////////////////////////////////////////////////////////////////////////
class EmptyPolicy
{
protected:
  ~EmptyPolicy() = default;
  void SetUp() {}
  void TearDown() {}
};

template <class CustomPolicy = EmptyPolicy>
class MockTest : public testing::Test, public CustomPolicy
{
private:
  void SetUp() override
  {
    jlr::Mocks::g_MockObjPtr = std::make_unique<StrictMock<jlr::Mocks>>();
    CustomPolicy::SetUp();
  }

  void TearDown() override
  {
    jlr::Mocks::g_MockObjPtr.reset(nullptr);
    CustomPolicy::TearDown();
  }
};

#define ADD_GENERIC_MOCKTEST(Name) \
  class Name : public MockTest<>   \
  {                                \
  }

#define ADD_CUSTOM_MOCKTEST(Name, Policy) \
  class Name : public MockTest<Policy>    \
  {                                       \
  }


#endif
