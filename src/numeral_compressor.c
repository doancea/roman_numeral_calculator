#include<numeral_compressor.h>
#include<string.h>
#include<stdio.h>

void handleIChars(char numerals[]) {
	int repeats = 0;
	int position = strlen(numerals) - 1;

	while(numerals[position] == 'I') {
		repeats++;
		position--;
	}
	// for(position; position >= 0; position-- ) {
	// 	if(numerals[position] == 'I') {
	// 		repeats++;
	// 	}
	// }

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

void handleVChars(char numerals[], int vposition) {
	int repeats = 0;
	int position = strlen(numerals) - 1;

	for(position; position >= 0; position-- ) {
		if(numerals[position] == 'V') {
			repeats++;
		}
	}

	if(repeats == 2) {
		numerals[0] = 'X';
		numerals[1] = '\0';
	}
}

void compressNumerals(char numerals[]) {
	handleIChars(numerals);
	handleVChars(numerals);
}