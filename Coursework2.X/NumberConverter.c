#include "NumberConverter.h"

/* Doubles will only convert the first digit after the decimal point. */
/* Converter will only handle numbers between 9999 and -99. */

// Ignore conversion warnings
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"

char nbrcnvt_convert_digit(unsigned short digit ) {
	if (digit <= 9) {
		return 48 + digit; /* ASCII 0 character is code 48. */
	}
	else { /* Invalid. */
		return 69; /* ASCII code for E. Represents Error. */
	}
}

#pragma GCC diagnostic pop

void nbrcnvt_convert_integer(signed short number, char* output) {
	unsigned char thousands;
	unsigned char hundreds;
	unsigned char tens;
	unsigned char units;
	unsigned char count = 0;
	unsigned char zero_flag = 0;

	if (number < 0) {
		output[count] = '-';
		count++;
		number = number * -1;
	}

    // Gets the values in individual digits
	units = number % 10;
	tens = ((number - units) % 100) / 10;
	hundreds = ((number - units - (tens * 10)) % 1000) / 100;
	thousands = ((number - units - (tens * 10) - (hundreds * 100)) % 10000) / 1000;

    // Number convert each digit
	if (thousands != 0) {
		zero_flag = 1;
		output[count] = nbrcnvt_convert_digit(thousands);
		count++;
	}

	if (zero_flag || hundreds != 0) {
		zero_flag = 1;
		output[count] = nbrcnvt_convert_digit(hundreds);
		count++;
	}

	if (zero_flag || tens != 0) {
		output[count] = nbrcnvt_convert_digit(tens);
		count++;
	}

	output[count] = nbrcnvt_convert_digit(units);
	count++;

	output[count] = '\0';



}
