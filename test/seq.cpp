#include "gtest/gtest.h"
#include <conduit/seq.hpp>

using namespace conduit;

auto test1() -> seq<int> {
  co_yield 1;
  co_yield 2;
  co_yield 3;
}

TEST(Seq, Next) {
  auto values = test1();

  int i = 1;
  while (values.next()) {
    EXPECT_EQ(i, values.get());
    ++i;
  }
  EXPECT_EQ(i, 4);
}

TEST(Seq, foreach) {
  int i = 1;
  for (auto x : test1()) {
    EXPECT_EQ(i, x);
    ++i;
  }
  EXPECT_EQ(i, 4);
}