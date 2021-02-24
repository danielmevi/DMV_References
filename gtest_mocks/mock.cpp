/***********************************************************************
 * @name ss_mocks.cpp
 * @Author Daniel Medina - dmedinav
 *
 ************************************************************************/

#include <string>
#include <cstring>

// Interface definition mocked

///////////////////////////////////////////////////////////////////////////////
// Mock Interface instrumentation
///////////////////////////////////////////////////////////////////////////////
int SetModelSignalValue(const uint8_t name[], uint32_t const data,
                                 uint8_t const src)
{
  std::string string_name{reinterpret_cast<const char*>(name)};
  return Mocks::g_MockObjPtr->SetModelSignalValue(string_name, data, src);
}

int  SetModelSignalBuffer(const uint8_t name[], const uint8_t data[],
                                  size_t const size_val, uint8_t const src,
                                  uint8_t const prof_num)
{
  std::string const string_name{reinterpret_cast<const char*>(name)};
  std::string const string_value{reinterpret_cast<const char*>(data), size_val};
  return Mocks::g_MockObjPtr->SetModelSignalBuffer(
      string_name, string_value, size_val, src, prof_num);
}

int32_t Post_Command_Func(uint8_t* http_received_data,
                          const uint8_t* http_send_data, size_t const data_size,
                          const uint8_t* http_send_account,
                          const uint8_t* http_send_vehicle,
                          const uint8_t* http_send_user)
{
  // Returning Zero ASCII to caller
  http_received_data[0] = 48;
  http_received_data[1] = 48;
  http_received_data[2] = 48;

  std::string const send_data{reinterpret_cast<const char*>(http_send_data)};
  std::string const send_account{
      reinterpret_cast<const char*>(http_send_account)};
  std::string const send_vehicle{
      reinterpret_cast<const char*>(http_send_vehicle)};
  std::string const send_user{reinterpret_cast<const char*>(http_send_user)};

  auto const mock_return_code{
      jlr::Mocks::g_MockObjPtr->Post_Command_Func(http_received_data,
                                                  send_data,
                                                  data_size,
                                                  send_account,
                                                  send_vehicle,
                                                  send_user)};

  switch (mock_return_code)
  {
    case 0:
      // case no received data
      return 0;
      break;
    case 1:
    {
      // case wrong json format
      std::string const json_data{
          "JSONDATA"};
      std::memcpy(http_received_data, json_data.c_str(), json_data.size());
      http_received_data[json_data.size()] = '\0';
      return json_data.size();
      break;
    }
    case 200:
    {
      std::string const json_data{"{\"domainName\":\"Domain\"}"};
      std::memcpy(http_received_data, json_data.c_str(), json_data.size());
      http_received_data[json_data.size()] = '\0';
      return json_data.size();
      break;
    }
    case 404:
    {
      std::string const error_data{
          "JSONERROR"};
      std::memcpy(http_received_data, error_data.c_str(), error_data.size());
      http_received_data[error_data.size()] = '\0';
      return error_data.size();
      break;
    }
    case 4040:
    {
      // Case for errorCode not registered
      std::string const error_data{
          "OTHERJSONERROR"}"};
      std::memcpy(http_received_data, error_data.c_str(), error_data.size());
      http_received_data[error_data.size()] = '\0';
      return error_data.size();
      break;
    }
    default:
      break;
  }

  return 0;
}
