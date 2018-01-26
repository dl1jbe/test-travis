
#include "locator2longlat.h"

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

