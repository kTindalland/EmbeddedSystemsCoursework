#include <gtest/gtest.h>
/* Include any code headers that need testing. */
#include <StringUtils.h>

TEST(StringLengthTests, sunnyDay) {
	// Arrange
	int result;
	char twoLength[2] = {'A', 'B'};
		
	// Act
	result = StringLength(twoLength);

	// Assert
	ASSERT_EQ(result, 2);
}

TEST(StringLengthTests, lowerRange) {
	// Arrange
	int result;
	char noLength[0];
		
	// Act
	result = StringLength(noLength);

	// Assert
	ASSERT_EQ(result, 0);
}