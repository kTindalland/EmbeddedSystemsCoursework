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

TEST(StringCopyTests, sunnyDay) {
	// Arrange
	char from[4] = {'A', 'B', 'C', 'D'};
	char to[4];
		
	// Act
	StringCopy(from, to);

	// Assert
	ASSERT_EQ(from, to);
}

TEST(StringCopyTests, clearingString) {
	// Arrange
	char from[0];
	char to[3] = {'A', 'B', 'C'};
		
	// Act
	StringCopy(from, to);

	// Assert
	ASSERT_EQ(from, to);
}
