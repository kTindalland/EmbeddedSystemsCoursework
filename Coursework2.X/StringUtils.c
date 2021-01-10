#include "NumberConverter.h"
#include "StringUtils.h"

// Returns the length of a string.
unsigned char StringLength(char s[]) {
	// Get char array length.
	unsigned char count = 0;

	for (unsigned char i = 0; s[i] != '\0'; i++) {
		count++;
	}

	return count;
}
