#include <gtest/gtest.h>
/* Include any code headers that need testing. */
#include <RealTimeClockConversions.h>

unsigned char readCH_result;

unsigned char readCH() {
	return readCH_result;
}

TEST(ConvertSecsTests, nominalData) {
	// Arrange
	readCH_result = 0x00;
	unsigned char result;
	int seconds = 30;

	// Act
	result = convertSecs(seconds);
	result = result & 0x7F; // Remove the Clock halt bit.

	// Assert
	ASSERT_EQ(result, 0x30);

}

TEST(ConvertSecsTests, checkClockHalt) {
	// Arrange
	readCH_result = 0x01;
	unsigned char result;
	int seconds = 30;

	// Act
	result = convertSecs(seconds);

	// Assert
	ASSERT_EQ(result, 0xB0);
}

TEST(ConvertSecsTests, erroneous) {
	// Arrange
	readCH_result = 0x01;
	unsigned char result;
	int seconds = 70;

	// Act
	result = convertSecs(seconds);

	// Assert
	ASSERT_EQ(result, RTC_ERROR);
}

TEST(ConvertMinsTests, nominalData) {
	// Arrange
	unsigned char result;
	int minutes = 30;

	// Act
	result = convertMins(minutes);

	// Assert
	ASSERT_EQ(result, 0x30);
}

TEST(ConvertMinsTests, erroneous) {
	// Arrange
	unsigned char result;
	int minutes = 70;

	// Act
	result = convertMins(minutes);

	// Assert
	ASSERT_EQ(result, RTC_ERROR);
}

TEST(ConvertHoursTests, nominalDataAM) {
	// Arrange
	unsigned char result;
	int hours = 9;
	int is24hr = 0; // AM

	// Act
	result = convertHours(hours, is24hr);

	// Assert
	ASSERT_EQ(result, 0x89);
}

TEST(ConvertHoursTests, nominalDataPM) {
	// Arrange
	unsigned char result;
	int hours = 9;
	int is24hr = 1; // PM

	// Act
	result = convertHours(hours, is24hr);

	// Assert
	ASSERT_EQ(result, 0xA9);
}

TEST(ConvertHoursTests, nominalData24hr) {
	// Arrange
	unsigned char result;
	int hours = 15;
	int is24hr = -1; // 24hr

	// Act
	result = convertHours(hours, is24hr);

	// Assert
	ASSERT_EQ(result, 0x15);
}

TEST(ConvertHoursTests, erroneousDataPM) {
	// Arrange
	unsigned char result;
	int hours = 50;
	int is24hr = 1; // PM

	// Act
	result = convertHours(hours, is24hr);

	// Assert
	ASSERT_EQ(result, RTC_ERROR);
}

TEST(ConvertHoursTests, erroneousDataAM) {
	// Arrange
	unsigned char result;
	int hours = 50;
	int is24hr = 0; // PM

	// Act
	result = convertHours(hours, is24hr);

	// Assert
	ASSERT_EQ(result, RTC_ERROR);
}

TEST(ConvertHoursTests, erroneousData24hr) {
	// Arrange
	unsigned char result;
	int hours = 50;
	int is24hr = -1; // PM

	// Act
	result = convertHours(hours, is24hr);

	// Assert
	ASSERT_EQ(result, RTC_ERROR);
}
