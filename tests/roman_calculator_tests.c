#include <check.h>
#include <roman_calculator_tests.h>
#include <numeral_compressor_tests.h>
#include <roman_calculator.h>

START_TEST(addingIAndIResultsInII) {
	char* augend = "I";
	char* addend = "I";
	char* result;

	add(augend, addend, result);
	
	ck_assert_str_eq(result, "II");
}
END_TEST

START_TEST(addingIIAndIIResultsInIV) {
	char* augend = "II";
	char* addend = "II";
	char result[4];

	add(augend, addend, result);
	
	ck_assert_str_eq(result, "IV");
}
END_TEST

START_TEST(addingIIIAndIIResultsInV) {
	char* augend = "III";
	char* addend = "II";
	char result[4];

	add(augend, addend, result);
	
	ck_assert_str_eq(result, "V");
}
END_TEST


Suite * roman_calculator_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("RomanCalc");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, addingIAndIResultsInII);
    tcase_add_test(tc_core, addingIIAndIIResultsInIV);
    tcase_add_test(tc_core, addingIIIAndIIResultsInV);
	
    suite_add_tcase(s, tc_core);

    return s;
}