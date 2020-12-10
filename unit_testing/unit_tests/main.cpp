#include <gtest/gtest.h>
/* Include any code headers that need testing. */
#include <RealTimeClockConversions.h>

uch readCH() {
	return 0x01;
}

TEST(RealTimeClockConversions, test_convertSecs_nominalData) {
    // Arrange
    unsigned char result;
    int seconds = 30;

    // Act
    result = convertSecs(seconds);
    result = result & 0x7F; // Remove the Clock halt bit.

    // Assert
    ASSERT_EQ(result, 0x30);

}
