#include<numeral_compressor.h>
#include<string.h>
#include<stdio.h>

void compressNumerals(char numerals[]) {
	int repeats = 0;
	int position = 0;
	
	for(position; position < strlen(numerals) - 1; position++ ) {
		if(numerals[position] == 'I') {
			repeats++;
		}

		if(repeats == 3) {
			numerals[position - 1] = 'V';
			numerals[position] = '\0';
			repeats = 0;
		}
	}
}