#include<check.h>
#include<string.h>
#include<numeral_compressor.h>
#include<numeral_compressor_tests.h>

START_TEST(fourConsecutiveINumeralsAreConvertedToTheCorrectIVNumerals) {
	char numerals[] = "IIII";

	compressNumerals(numerals);
	
	ck_assert_str_eq(numerals, "IV");
}
END_TEST

START_TEST(fourConsecutiveINumeralsThenTheConvertedStringIsTheCorrectLength) {
	char numerals[] = "IIII";

	compressNumerals(numerals);
	
	ck_assert_int_eq(strlen(numerals), 2);
}
END_TEST

START_TEST(fiveConsecutiveICharactersAreReplacedWithAV) {
	char numerals[] = "IIIII";

	compressNumerals(numerals);
	
	ck_assert_str_eq(numerals, "V");
    ck_assert_int_eq(strlen(numerals), 1);
}
END_TEST

START_TEST(VVGetsCompressedToX) {
	char numerals[] = "VV";

	compressNumerals(numerals);
	
	ck_assert_str_eq(numerals, "X");
    ck_assert_int_eq(strlen(numerals), 1);
}
END_TEST

START_TEST(VVIGetsCompressedToXI) {
	char numerals[] = "VVI";

	compressNumerals(numerals);
	
	ck_assert_str_eq(numerals, "XI");
    ck_assert_int_eq(strlen(numerals), 2);
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
    tcase_add_test(tc_core, fourConsecutiveINumeralsThenTheConvertedStringIsTheCorrectLength);
    tcase_add_test(tc_core, fiveConsecutiveICharactersAreReplacedWithAV);
    tcase_add_test(tc_core, VVGetsCompressedToX);
    tcase_add_test(tc_core, VVIGetsCompressedToXI);
	
    suite_add_tcase(s, tc_core);

    return s;
}