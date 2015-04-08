/**
 * Library for computing factorials -- Unit Test.
 */

#include "fact.h"
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

/* Test Suite setup and cleanup functions: */

int
init_suite_fact_rec(void)
{
	return 0;
}
int
clean_suite_fact_rec(void)
{
	return 0;
}

/************* Test case functions ****************/

void
test_fact_rec_nom(void)
{
	CU_ASSERT_EQUAL(fact_rec(0), 1);
	CU_ASSERT_EQUAL(fact_rec(1), 1);
	CU_ASSERT_EQUAL(fact_rec(10), 3628800);
}

void
test_fact_rec_lim(void)
{
	CU_ASSERT_EQUAL(fact_rec(-1), 0);
	CU_ASSERT(fact_rec(100) > 0);
	/* forces evaluation and, if not 0, pass the test */
}

int
test_fact_rec_suite(void)
{
	/* add a suite to the registry */
	CU_pSuite       pSuite = CU_add_suite("test suite for fact_rec", init_suite_fact_rec, clean_suite_fact_rec);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}
	/* add the tests to the suite */
	if ((NULL == CU_add_test(pSuite, "fact_rec nominal", test_fact_rec_nom)) ||
	    (NULL == CU_add_test(pSuite, "fact_rec limite", test_fact_rec_lim))) {
		CU_cleanup_registry();
		return CU_get_error();
	}
	return 0;
}

/************* Test Runner Code goes here **************/

int 
main(void)
{
	/* initialize the CUnit test registry */
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

	/* add a suite to the registry */
	if (1 == test_fact_rec_suite())
		return CU_get_error();

	//Run all tests using the basic interface
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	printf("\n");
	CU_basic_show_failures(CU_get_failure_list());
	printf("\n\n");

	/*
	   // Run all tests using the automated interface
	   CU_automated_run_tests();
	   CU_list_tests_to_file();
	
	   // Run all tests using the console interface
	   CU_console_run_tests();
	*/

	/* Clean up registry and return */
	CU_cleanup_registry();
	return CU_get_error();
}
