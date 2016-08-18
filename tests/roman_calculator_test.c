#include <check.h>
#include <roman_calculator.h>

const int EXIT_FAILURE = 1;
const int EXIT_SUCCESS = 0;

START_TEST(addingIAndIResultsInII) {
	char* augend = "I";
	char* addend = "I";
	char* result;

	add(augend, addend, result);
	
	ck_assert_str_eq(result, "II");
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
	
    suite_add_tcase(s, tc_core);

    return s;
}

 int main(void)
 {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = roman_calculator_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
 }