#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <string.h>
//#include <cmocka.h>
#include "CUnit/Basic.h"

#include "../src/score.h"
#include "../src/tlf.h"
#include "../src/dxcc.h"

#include "../src/globalvars.h"

// ===========
// these are missing from globalvars
extern int dupe;
extern int my_country_points;
extern int my_cont_points;
extern int dx_cont_points;
extern int countrylist_only;
extern int countrylist_points;
extern char countrylist[][6];
extern int continentlist_only;
extern int continentlist_points;
extern char mycontinent[];
extern char continent_multiplier_list[7][3];
extern int lowband_point_mult;
extern int portable_x2;
// ===========

int exist_in_country_list();
int readctydata(void);

#define check_points(point) \
    do{ CU_ASSERT_EQUAL(score(), point); }while(0)
//    do{ assert_int_equal(score(), point); }while(0)

#define check_call_points(call,point) \
    do{ strcpy(hiscall, call); \
        CU_ASSERT_INT_EQUAL(score(), point); }while(0)
//	assert_int_equal(score(), point); }while(0)

#if 0
char hiscall[20];
char call[20];
char comment[80];
char pxstr[11];
char continent[3];
char cqzone[3], ituzone[3], zone_export[3];
int itumult= 0;
char lan_logline[256];
int points, total;
int countrynr, dupe;
int bandinx = 1;
int band_score[9];

char mycontinent[3] = "EU";
int mycountrynr = 95; 	/* DL */
int w_cty = 184; 	/* W */
int ve_cty = 283; 	/* VE */

int trxmode = CWMODE;

int arrldx_usa, wpx, pfxmult, cqww, arrl_fd, one_point, two_point, three_point;
int focm, stewperry_flg;
int cwpoints, ssbpoints;
int lowband_point_mult, portable_x2;
int my_country_points, my_cont_points, dx_cont_points;
int countrylist_only, countrylist_points;
char countrylist[255][6];
int continentlist_only, continentlist_points;
char continent_multiplier_list[7][3];

int bandweight_points[NBANDS] = {1, 1, 1, 1, 1, 1, 1, 1, 1};

#define malloc test_malloc
#define free   test_free
#endif

void __wrap_qrb(char *x, char *y, char *u, char *v, double *a, double *b)
{
}

int __wrap_foc_score()
{
    return 0;
}

#if 0
void refreshp() {

}
#endif

//! char myqra[7]="jo60lx";

//static int setup(void **state) {
int init_score(void) {
    cqww = 0;
    wpx = 0;
    pfxmult = 0;
    arrl_fd = 0;
    dupe = 0;
    arrldx_usa = 0;
    one_point = 0;
    two_point = 0;
    three_point = 0;

    my_country_points = -1;
    my_cont_points = -1;
    dx_cont_points = -1;

    countrylist_only = 0;
    countrylist_points = -1;
    strcpy(countrylist[0], "");

    continentlist_only = 0;
    continentlist_points = -1;
    strcpy(continent_multiplier_list[0], "");

    strcpy(mycontinent, "EU");

    lowband_point_mult = 0;
    portable_x2 = 0;

    return 0;
}

int setup_cty(void **state) {
//!    setup(state);
    /* TODO */
    /* load_ctydata needs means to destroy the database */
//!    assert_int_equal(load_ctydata("../share/cty.dat"), 0);

    return 0;
}


//static void dupe_test(void **state) {
void test_dupe(void) {
    dupe = 1;
    check_points(0);
}

#if 0
static int teardown(void **state) {
    return 0;
}


static void wpx_test(void **state) {
    wpx = 1;
    pfxmult = 0;

    /* same country */
    countrynr = mycountrynr;
    check_points(1);

    /* different continents */
    countrynr = 2;
    strcpy(continent, "AF");
    bandinx = BANDINDEX_20;
    check_points(3);

    bandinx = BANDINDEX_40;
    check_points(6);

    /* same continent, not NA */
    strcpy(continent, mycontinent);
    bandinx = BANDINDEX_20;
    check_points(1);

    bandinx = BANDINDEX_40;
    check_points(2);

    /* same continent, NA */
    strcpy(mycontinent, "NA");
    strcpy(continent, mycontinent);
    bandinx = BANDINDEX_20;
    check_points(2);

    bandinx = BANDINDEX_40;
    check_points(4);

}


static void cqww_test(void **state) {
    cqww = 1;

    countrynr = mycountrynr;
    check_points(0);

    countrynr = 2;
    strcpy(continent, "EU");
    strcpy(mycontinent, "EU");
    check_points(1);

    strcpy(continent, "NA");
    strcpy(mycontinent, "NA");
    check_points(2);

    strcpy(continent, "EU");
    strcpy(mycontinent, "NA");
    check_points(3);
}

static void arrl_fd_test(void **state) {
    arrl_fd = 1;

    trxmode = CWMODE;
    check_points(2);

    trxmode = SSBMODE;
    check_points(1);

}


static void simple_points_test(void **state) {
    one_point = 1;
    check_points(1);
    one_point = 0;

    two_point = 1;
    check_points(2);
    two_point = 0;

    three_point = 1;
    check_points(3);
}

static void arrldx_usa_test(void **state) {
    arrldx_usa = 1;

    countrynr = w_cty;
    check_points(0);

    countrynr = ve_cty;
    check_points(0);

    countrynr = mycountrynr;
    check_points(3);
}

static void ssbcw_test(void **state) {
    check_points(0);

    ssbpoints = 3;
    check_points(0);

    cwpoints = 4;
    trxmode = CWMODE;
    check_points(4);
    trxmode = SSBMODE;
    check_points(3);

    lowband_point_mult = 1;
    bandinx = BANDINDEX_30;
    check_points(3);
    bandinx = BANDINDEX_40;
    check_points(6);

    portable_x2 = 1;
    check_call_points("DL3XYZ", 6);
    check_call_points("DL3XYZ/P", 12);

    trxmode = DIGIMODE;
    check_points(0);
    ssbpoints = 0;
    check_points(0);
}

void init_countrylist() {
    strcpy(countrylist[0], "OE");
    strcpy(countrylist[1], "DL");
    strcpy(countrylist[2], "W");
    strcpy(countrylist[3], "");
}

static void country_found_test(void **state) {
    /* nothing to find in empty list */
    strcpy(hiscall, "LZ1AB");
    assert_int_equal(country_found(""), 0);
    strcpy(hiscall, "DL3XYZ");
    assert_int_equal(country_found(""), 0);

    init_countrylist();
    strcpy(hiscall, "LZ1AB");
    assert_int_equal(country_found(""), 0);
    strcpy(hiscall, "DL3XYZ");
    assert_int_equal(country_found(""), 1);
    strcpy(hiscall, "K3LA");
    assert_int_equal(country_found(""), 1);
}

static void scoreByCorC_listOnly_test(void ** state) {
    countrylist_only = 1;
    check_call_points("LZ1AB", 0);
    check_call_points("DL3XYZ", 0);

    init_countrylist();
    check_call_points("LZ1AB", 0);
    check_call_points("DL3XYZ", 0);

    countrylist_points = 4;
    check_call_points("LZ1AB", 0);
    check_call_points("DL3XYZ", 4);
}

static void scoreByCorC_notInList_test(void ** state) {

    /* my_country/cont_points and dx_cont_points not set */
    check_call_points("DL3XYZ", 0);
    check_call_points("LZ1AB", 0);
    check_call_points("K3XX", 0);

    dx_cont_points = 4;
    check_call_points("DL3XYZ", 0);
    check_call_points("LZ1AB", 0);
    check_call_points("K3XX", 4);

    my_cont_points = 3;
    check_call_points("DL3XYZ", 3);
    check_call_points("LZ1AB", 3);
    check_call_points("K3XX", 4);

    my_country_points = 1;
    check_call_points("DL3XYZ", 1);
    check_call_points("LZ1AB", 3);
    check_call_points("K3XX", 4);
}


static void scoreByCorC_InList_test(void ** state) {
    init_countrylist();

    /* countrylist_points, my_country_points and my_cont_points
     * not set -> 0 points for all */
    check_call_points("OE2BL", 0);
    check_call_points("DL3XYZ", 0);
    check_call_points("K3XX", 0);

    /* only countrylist_points set -> use my_country/cont_points for
     * my own country , otherwise 0 ??? */
    countrylist_points = 3;
    check_call_points("OE2BL", 3);
    check_call_points("DL3XYZ", 0);
    check_call_points("K3XX", 3);

    my_cont_points = 2;
    check_call_points("OE2BL", 3);
    check_call_points("DL3XYZ", 2);
    check_call_points("K3XX", 3);

    my_country_points = 1;
    check_call_points("OE2BL", 3);
    check_call_points("DL3XYZ", 1);
    check_call_points("K3XX", 3);
}
#endif

#if 0
int main(void) {
    const struct CMUnitTest tests[] = {
	cmocka_unit_test_setup_teardown(dupe_test, setup, teardown),
	cmocka_unit_test_setup_teardown(wpx_test, setup, teardown),
	cmocka_unit_test_setup_teardown(cqww_test, setup, teardown),
	cmocka_unit_test_setup_teardown(arrl_fd_test, setup, teardown),
	cmocka_unit_test_setup_teardown(simple_points_test, setup, teardown),
	cmocka_unit_test_setup_teardown(arrldx_usa_test, setup, teardown),
	cmocka_unit_test_setup_teardown(ssbcw_test, setup_cty, teardown),
	cmocka_unit_test_setup_teardown(country_found_test, setup, teardown),
	cmocka_unit_test_setup_teardown(scoreByCorC_listOnly_test,
	    setup, teardown),
	cmocka_unit_test_setup_teardown(scoreByCorC_notInList_test,
	    setup, teardown),
	cmocka_unit_test_setup_teardown(scoreByCorC_InList_test,
	    setup, teardown),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
#endif
