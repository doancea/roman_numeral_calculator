#include<check.h>
#include<numeral_compressor.h>
#include<numeral_compressor_tests.h>

START_TEST(fourConsecutiveINumeralsAreConvertedToTheCorrectIVNumerals) {
	char* numerals = "IIII";

	compressNumerals(numerals);
	
	ck_assert_str_eq(numerals, "IV");
}
END_TEST

Suite * numeral_compressor_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("NumeralCompressor");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, fourConsecutiveINumeralsAreConvertedToTheCorrectIVNumerals);
	
    suite_add_tcase(s, tc_core);

    return s;
}