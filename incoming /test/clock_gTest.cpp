/*
 * clock_gTest.cpp
 */

#include "../src/clock.h"

#include "gtest/gtest.h"


TEST(Coder, sizeof)
{
	EXPECT_EQ(true, true);
}


int main(int argc, char **argv)
{
  printf("Running main() from clock_gTest.cpp\n");

  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
