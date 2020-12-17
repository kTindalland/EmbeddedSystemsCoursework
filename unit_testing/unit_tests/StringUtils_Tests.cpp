#include <gtest/gtest.h>
/* Include any code headers that need testing. */
#include <StringUtils.h>

TEST(StringLengthTests, sunnyDay) {
	// Arrange
	int result;
	char twoLength[3] = {'A', 'B', '\0'};
		
	// Act
	result = StringLength(twoLength);

	// Assert
	ASSERT_EQ(result, 2);
}

TEST(StringLengthTests, lowerRange) {
	// Arrange
	int result;
	char noLength[1] = {'\0'};
		
	// Act
	result = StringLength(noLength);

	// Assert
	ASSERT_EQ(result, 0);
}

TEST(StringCopyTests, sunnyDay) {
	// Arrange
	char from[5] = {'A', 'B', 'C', 'D', '\0'};
	char to[5];
	int result;
		
	// Act
	result = StringCopy(from, to, 4);

	// Assert
	EXPECT_STREQ(from, to);
	ASSERT_EQ(result, 1);
}

TEST(StringCopyTests, fromSmallerThanTo) {
	// Arrange
	char from[2] = {'A', '\0'};
	char to[4] = {'A', 'B', 'C', '\0'};
	int result;		

	// Act
	result = StringCopy(from, to, 1);

	// Assert
	EXPECT_STREQ(to, "A");
	ASSERT_EQ(result, 1);
}

TEST(StringCopyTests, fromBiggerThanTo){
	// Arrange
	char from[4] = {'A', 'B', 'C', '\0'};
	char to[2] = {'A', '\0'};
	int result;
		
	// Act
	result = StringCopy(from, to, 1);

	// Assert
	ASSERT_EQ(result, 1);
}

TEST(StringCopyTests, emptyArrayFrom){
	// Arrange
	char from[0];
	char to[2] = {'A', '\0'};
	int result;
		
	// Act
	result = StringCopy(from, to);

	// Assert
	ASSERT_EQ(result, 0);
}

TEST(ConcatenateTests, sunnyDay){
	// Arrange
	char a[4] = {'H', 'E', 'L', '\0'};
	char b[3] = {'L', 'O', '\0'};
	char result[6];
	char expected[6] = {'H', 'E', 'L', 'L', 'O', '\0'};
		
	// Act
	Concatenate(a, b, result);

	// Assert
	ASSERT_STREQ(result, expected);
}

TEST(ConcatenateTests, oneEmptyString){
	// Arrange
	char a[0];
	char b[3] = {'L', 'O', '\0'};
	char result[3];
	char expected[3] = {'L', 'O', '\0'};
		
	// Act
	Concatenate(a, b, result);

	// Assert
	ASSERT_STREQ(result, expected);
}

TEST(ConcatenateTests, twoEmptyStrings){
	// Arrange
	char a[0];
	char b[0];
	char result[0];
	char expected[0];
		
	// Act
	Concatenate(a, b, result);

	// Assert
	ASSERT_STREQ(result, expected);
}

TEST(ConcatenateTests, smallResult){
	// Arrange
	char a[2] = {'A', '\0'};
	char b[2] = {'B', '\0'};
	char combined[3];
	int result;

	// Act
	result = Concatenate(a, b, combined);

	// Assert
	ASSERT_EQ(result, 0);
}

TEST(ConcatenateTests, largeResult){
	// Arrange
	char a[2] = {'A', '\0'};
	char b[2] = {'B', '\0'};
	char result[3];
	char expected[3] = {'A', 'B', '\0'};
		
	// Actl
	Concatenate(a, b, result);

	// Assert
	ASSERT_STREQ(result, expected);
}

