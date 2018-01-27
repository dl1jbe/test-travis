
#include "zone_nr.h"

#include "CUnit/Basic.h"

void test_ok_08(void) {
    CU_ASSERT(8 == zone_nr("08"));
}

void test_ok__8(void) {
    CU_ASSERT(8 == zone_nr(" 8"));
}

void test_ok_14(void) {
    CU_ASSERT(14 == zone_nr("14"));
}

void test_bad_empty(void) {
    CU_ASSERT(0 == zone_nr(""));
}

void test_bad_nan(void) {
    CU_ASSERT(0 == zone_nr("foo"));
}

//void test_bad_short(void) {
//    CU_ASSERT(0 == zone_nr("7"));
//}
