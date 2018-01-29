
#include "../src/getpx.h"

#include "CUnit/Basic.h"

char pxstr[100];    // output buffer

void test_A1BB(void) {
    getpx("A1BB");
    CU_ASSERT_STRING_EQUAL(pxstr, "A1");
}

void test_AB1BB(void) {
    getpx("AB1BB");
    CU_ASSERT_STRING_EQUAL(pxstr, "AB1");
}

void test_AB2BB_P(void) {
    getpx("AB2BB/P");
    CU_ASSERT_STRING_EQUAL(pxstr, "AB2");
}

void test_OE_AB2BB(void) {
    getpx("OE/AB2BB");
    CU_ASSERT_STRING_EQUAL(pxstr, "OE0");
}

void test_OE6_AB2BB(void) {
    getpx("OE6/AB2BB");
    CU_ASSERT_STRING_EQUAL(pxstr, "OE6");
}

void test_R7AB_8(void) {
    getpx("R7AB/8");
    CU_ASSERT_STRING_EQUAL(pxstr, "R8");
}
