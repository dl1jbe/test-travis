
#include "CUnit/Basic.h"

#include "defs.h"   // created by generate_defs.pl

int main() {

    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* register suites and their tests */
    if (CUE_SUCCESS != CU_register_suites(suites)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    int n_fails = CU_get_number_of_failure_records();

    CU_cleanup_registry();

    return n_fails;
}


