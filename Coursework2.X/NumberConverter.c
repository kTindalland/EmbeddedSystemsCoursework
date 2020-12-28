#include "NumberConverter.h"

/* Doubles will only convert the first digit after the decimal point. */
/* Converter will only handle numbers between 9999 and -99. */

// Ignore conversion warnings
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"

char nbrcnvt_convert_digit(unsigned short digit ) {
	if (digit >= 0 && digit <= 9) {
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

	units = number % 10;
	tens = ((number - units) % 100) / 10;
	hundreds = ((number - units - (tens * 10)) % 1000) / 100;
	thousands = ((number - units - (tens * 10) - (hundreds * 100)) % 10000) / 1000;

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

void nbrcnvt_convert_double(double number, char* output) {
	int decimal;
	int thousands;
	int hundreds;
	int tens;
	int units;
	int count = 0;
	int zero_flag = 0;

	if (number < 0) {
		output[count] = '-';
		count++;
		number = number * -1;
	}

	units = (int)number % 10;
	tens = (((int)(number - units)) % 100) / 10;
	hundreds = ((int)(number - units - (tens * 10)) % 1000) / 100;
	thousands = ((int)(number - units - (tens * 10) - (hundreds * 100)) % 10000) / 1000;

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

	output[count] = '.';
	count++;

	decimal = (int)(number * 10) % 10;
	output[count] = nbrcnvt_convert_digit(decimal);
	count++;

	output[count] = '\0';
}

int nbrcnvt_check_length_int(int number) {
	if (number < 0 && number > -10) {
		return 3; /* -X\0 */
	}
	else if (number < -9 && number >= -50) {
		return 4; /* -XX\0 */
	}
	else if (number >= 0 && number <= 9) {
		return 2; /* X\0 */
	}
	else if (number >= 10 && number <= 99) {
		return 3;
	}
	else if (number >= 100 && number <= 999) {
		return 4;
	}
	else if (number >= 1000 && number <= 9999) {
		return 5;
	}
	else { /* Default */
		return -1;
	}
}

int nbrcnvt_check_length_double(double number) {
	if (number < 0 && number > -10) {
		return 5; /* -X.X\0 */
	}
	else if (number < -9) {
		return 6; /* -XX.X\0 */
	}
	else if (number >= 0 && number <= 9) {
		return 4; /* X.X\0 */
	}
	else if (number >= 10 && number <= 99) {
		return 5;
	}
	else if (number >= 100 && number <= 999) {
		return 6;
	}
	else if (number >= 1000 && number <= 9999) {
		return 7;
	}
	else { /* Default */
		return -1;
	}
}
