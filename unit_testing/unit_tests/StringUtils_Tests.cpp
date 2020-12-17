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
	int result;
		
	// Act
	result = StringCopy(from, to);

	// Assert
	EXPECT_STREQ(from, to);
	ASSERT_EQ(result, 1);
}

TEST(StringCopyTests, fromSmallerThanTo) {
	// Arrange
	char from[1] = {'A'};
	char to[3] = {'A', 'B', 'C'};
	int result;		

	// Act
	result = StringCopy(from, to);

	// Assert
	EXPECT_STREQ(from, to);
	ASSERT_EQ(result, 1);
}

TEST(StringCopyTests, fromBiggerThanTo){
	// Arrange
	char from[3] = {'A', 'B', 'C'};
	char to[1] = {'A'};
	int result;
		
	// Act
	result = StringCopy(from, to);

	// Assert
	ASSERT_EQ(result, 0);
}

TEST(StringCopyTests, emptyArrayFrom){
	// Arrange
	char from[0];
	char to[1] = {'A'};
	int result;
		
	// Act
	result = StringCopy(from, to);

	// Assert
	ASSERT_EQ(result, 0);
}

TEST(ConcatenateTests, sunnyDay){
	// Arrange
	char a[3] = {'H', 'E', 'L'};
	char b[2] = {'L', 'O'};
	char result[6];
	char* expected = "HELLO";
		
	// Act
	Concatenate(a, b, result);

	// Assert
	ASSERT_STREQ(result, expected);
}

TEST(ConcatenateTests, oneEmptyString){
	// Arrange
	char a[0];
	char b[2] = {'L', 'O'};
	char result[2];
	char* expected = "LO";
		
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
	char* expected = "";
		
	// Act
	Concatenate(a, b, result);

	// Assert
	ASSERT_STREQ(result, expected);
}

TEST(ConcatenateTests, smallResult){
	// Arrange
	char a[1] = {'A'};
	char b[1] = {'B'};
	char combined[1];
	int result;

	// Act
	result = Concatenate(a, b, combined);

	// Assert
	ASSERT_EQ(result, 0);
}

TEST(ConcatenateTests, largeResult){
	// Arrange
	char a[1] = {'A'};
	char b[1] = {'B'};
	char result[3];
	char* expected = "AB";
		
	// Act
	Concatenate(a, b, result);

	// Assert
	ASSERT_STREQ(result, expected);
}

