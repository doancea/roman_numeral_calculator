#include<numeral_compressor.h>
#include<string.h>
#include<stdio.h>

void compressNumerals(char numerals[]) {
	int repeats = 0;
	int position = strlen(numerals) - 1;

	for(position; position >= 0; position-- ) {
		if(numerals[position] == 'I') {
			repeats++;
		}
	}

	if(repeats == 5) {
		numerals[0] = 'V';
		numerals[1] = '\0';
		return;
	}

	if(repeats == 4) {
		numerals[1] = 'V';
		numerals[2] = '\0';
		return;
	}
}