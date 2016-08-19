#include<check.h>
#include<numeral_compressor_tests.h>
#include<roman_calculator_tests.h>

const int EXIT_FAILURE = 1;
const int EXIT_SUCCESS = 0;

int main(void)
 {
    int number_failed;
    Suite *calc_tests;
    Suite *numeral_compressor_tests;
    SRunner *sr;

    calc_tests = roman_calculator_suite();
    numeral_compressor_tests = numeral_compressor_suite();
    sr = srunner_create(calc_tests);
    srunner_add_suite(sr, numeral_compressor_tests);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
 }