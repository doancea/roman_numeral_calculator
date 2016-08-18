
#include<roman_calculator.h>
#include <string.h>
#include <stdlib.h>

void add(char augend[], char addend[], char result[]) {
	int augend_length = strlen(augend);
	int addend_length = strlen(addend);

	char* sum = malloc(augend_length + addend_length + 1);

	memcpy(sum, augend, augend_length);
    memcpy(sum + augend_length, addend, addend_length + 1);
    
	strcpy(result, sum); 
}