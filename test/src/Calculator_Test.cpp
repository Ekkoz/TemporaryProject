#include "gtest/gtest.h"
#include "Calculator.h"

TEST(Calculator, Addition) {
	Calculator calc;

	EXPECT_EQ(2, calc.sum(1, 1));
}
