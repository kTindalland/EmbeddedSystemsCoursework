#include <gtest/gtest.h>
/* Include any code headers that need testing. */
#include <ThermometerInterface.h>
#include <ThermometerDriver.h>

unsigned char fake_msb;
unsigned char fake_lsb;

void ThermMeasureTemp() { };

void ThermGetTemp(unsigned char* msb, unsigned char* lsb) {
	*msb = fake_msb;
	*lsb = fake_lsb;
};

TEST(ThermometerConversionTests, Test1) {
	// Arrange
	fake_msb = 0x00;
	fake_lsb = 0xA2;

	// Act
	double temp = IThermGetTemperature();

	// Assert
	ASSERT_EQ(temp, 10.125);
}