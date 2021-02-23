#include "gtest/gtest.h"
#include "linked_list.hpp"

#include <random>

namespace {

class Linked_list : public ::testing::Test {
 public:
    Linked_list() : _list(), gen(rd()), dis(1, 100) {}

 protected:
    virtual void SetUp() {}
    virtual void TearDown() {}

    LinkedList _list;

    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> dis;
};

TEST_F(Linked_list, ten) {
    for (uint8_t i = 0; i < 10; ++i) _list.push_back(dis(gen));

    ASSERT_TRUE(10 == _list.size());
}
TEST_F(Linked_list, thousand) {
    for (uint16_t i = 0; i < 1000; ++i) _list.push_back(dis(gen));

    ASSERT_TRUE(1000 == _list.size());
}
TEST_F(Linked_list, million) {
    for (uint32_t i = 0; i < 1000000; ++i) _list.push_back(dis(gen));

    ASSERT_TRUE(1000000 == _list.size());
}
}
