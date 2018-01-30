
#include "../src/locator2longlat.h"

#include "CUnit/Basic.h"

int init_locator2longlat(void) {
    return 0;
}

int clean_locator2longlat(void) {
    return 0;
}

void test_qra_short(void) {
    CU_ASSERT(1 == check_qra("JN"));
}

void test_qra_ok4(void) {
    CU_ASSERT(0 == check_qra("JN97"));
}

void test_qra_ok6(void) {
    CU_ASSERT(0 == check_qra("JN97ab"));
}

