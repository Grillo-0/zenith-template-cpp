#include "../MyProject.hpp"
#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(MyProject, MAC) {
	int x = 6;
	int y = 5;
	int sum = 11;
	EXPECT_EQ(sum, MAC(x, y));
}
