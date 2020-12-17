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
	result = StringCopy(from, to, 1);

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
	Concatenate(a, b, result, 6);

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
	Concatenate(a, b, result, 3);

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
	Concatenate(a, b, result, 0);

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
	result = Concatenate(a, b, combined, 3);

	// Assert
	ASSERT_EQ(result, 0);
}

TEST(ConcatenateTests, largeResult){
	// Arrange
	char a[2] = {'A', '\0'};
	char b[2] = {'B', '\0'};
	char result[3];
	char expected[3] = {'A', 'B', '\0'};
		
	// Act
	Concatenate(a, b, result, 3);

	// Assert
	ASSERT_STREQ(result, expected);
}

TEST(ConvertTime12ToStringTests, sunnyDay){
	// Arrange
	char result[11];
	int secs = 15;
	int mins = 40;
	int hours = 9;
	int pm = 1;

	char* expected = "09:40:15 PM";
		
	// Act
	int resultNo = ConvertTime12ToString(result, secs, mins, hours, pm, 11);

	// Assert
	EXPECT_STREQ(result, expected);
	ASSERT_EQ(resultNo, 1);
}

TEST(ConvertTime12ToStringTests, lowerBounds){
	// Arrange
	char result[11];
	int secs = -1;
	int mins = 40;
	int hours = 9;
	int pm = 1;
		
	// Act
	int resultNo = ConvertTime12ToString(result, secs, mins, hours, pm, 11);

	// Assert
	ASSERT_EQ(resultNo, 0);
}

TEST(ConvertTime12ToStringTests, upperBounds){
	// Arrange
	char result[11];
	int secs = 60;
	int mins = 40;
	int hours = 9;
	int pm = 1;
		
	// Act
	int resultNo = ConvertTime12ToString(result, secs, mins, hours, pm, 11);

	// Assert
	ASSERT_EQ(resultNo, 0);
}

TEST(ConvertTime12ToStringTests, underLength){
	// Arrange
	char result[11];
	int secs = 60;
	int mins = 40;
	int hours = 9;
	int pm = 1;
		
	// Act
	int resultNo = ConvertTime12ToString(result, secs, mins, hours, pm, 9);

	// Assert
	ASSERT_EQ(resultNo, 0);
}

TEST(ConvertTime12ToStringTests, overLength){
	// Arrange
	char result[11];
	int secs = 60;
	int mins = 40;
	int hours = 9;
	int pm = 1;
		
	// Act
	int resultNo = ConvertTime12ToString(result, secs, mins, hours, pm, 14);

	// Assert
	ASSERT_EQ(resultNo, 0);
}

TEST(ConvertTime24ToStringTests, sunnyDay){
	// Arrange
	char result[8];
	int secs = 15;
	int mins = 40;
	int hours = 9;

	char* expected = "09:40:15";
		
	// Act
	int resultNo = ConvertTime24ToString(result, secs, mins, hours, 8);

	// Assert
	EXPECT_STREQ(result, expected);
	ASSERT_EQ(resultNo, 1);
}

TEST(ConvertTime24ToStringTests, lowerBounds){
	// Arrange
	char result[8];
	int secs = -1;
	int mins = 40;
	int hours = 9;
		
	// Act
	int resultNo = ConvertTime24ToString(result, secs, mins, hours, 8);

	// Assert
	ASSERT_EQ(resultNo, 0);
}

TEST(ConvertTime24ToStringTests, upperBounds){
	// Arrange
	char result[8];
	int secs = 60;
	int mins = 40;
	int hours = 9;
		
	// Act
	int resultNo = ConvertTime24ToString(result, secs, mins, hours, 8);

	// Assert
	ASSERT_EQ(resultNo, 0);
}

TEST(ConvertTime24ToStringTests, underLength){
	// Arrange
	char result[8];
	int secs = 60;
	int mins = 40;
	int hours = 9;
		
	// Act
	int resultNo = ConvertTime24ToString(result, secs, mins, hours, 5);

	// Assert
	ASSERT_EQ(resultNo, 0);
}

TEST(ConvertTime24ToStringTests, overLength){
	// Arrange
	char result[8];
	int secs = 60;
	int mins = 40;
	int hours = 9;
		
	// Act
	int resultNo = ConvertTime24ToString(result, secs, mins, hours, 14);

	// Assert
	ASSERT_EQ(resultNo, 0);
}

TEST(ConvertDateToStringTests, sunnyDay){
	// Arrange
	char result[10];
	int date = 19;
	int month = 4;
	int year = 2093;
		
	// Act
	int resultNo = ConvertDateToString(result, date, month, year, 10);

	// Assert
	EXPECT_STREQ(result, "19/04/2093");
	ASSERT_EQ(resultNo, 1);
}

TEST(ConvertDateToStringTests, sunnyDayDoubleDigitMonth){
	// Arrange
	char result[10];
	int date = 19;
	int month = 11;
	int year = 2093;
		
	// Act
	int resultNo = ConvertDateToString(result, date, month, year, 10);

	// Assert
	EXPECT_STREQ(result, "19/11/2093");
	ASSERT_EQ(resultNo, 1);
}

TEST(ConvertDateToStringTests, sunnyDayEarlierYear){
	// Arrange
	char result[10];
	int date = 19;
	int month = 4;
	int year = 2003;
		
	// Act
	int resultNo = ConvertDateToString(result, date, month, year, 10);

	// Assert
	EXPECT_STREQ(result, "19/04/2003");
	ASSERT_EQ(resultNo, 1);
}

TEST(ConvertDateToStringTests, lowerBounds){
	// Arrange
	char result[10];
	int date = -3;
	int month = 4;
	int year = 2093;
		
	// Act
	int resultNo = ConvertDateToString(result, date, month, year, 10);

	// Assert
	ASSERT_EQ(resultNo, 0);
}

TEST(ConvertDateToStringTests, upperBounds){
	// Arrange
	char result[10];
	int date = 34;
	int month = 4;
	int year = 2093;
		
	// Act
	int resultNo = ConvertDateToString(result, date, month, year, 10);

	// Assert
	ASSERT_EQ(resultNo, 0);
}

TEST(ConvertDateToStringTests, underLength){
	// Arrange
	char result[10];
	int date = 3;
	int month = 4;
	int year = 2093;
		
	// Act
	int resultNo = ConvertDateToString(result, date, month, year, 9);

	// Assert
	ASSERT_EQ(resultNo, 0);
}

TEST(ConvertDateToStringTests, overLength){
	// Arrange
	char result[10];
	int date = 3;
	int month = 4;
	int year = 2093;
		
	// Act
	int resultNo = ConvertDateToString(result, date, month, year, 11);

	// Assert
	ASSERT_EQ(resultNo, 0);
}
