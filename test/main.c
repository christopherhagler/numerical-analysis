#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "root_finding.h"
#include "test_bisection.c"
#include "test_newton.c"
#include "test_false_position.c"
#include "test_illinois.c"
#include "test_pegasus.c"
#include "test_secant.c"

extern void test_bisection_cubic(void **state);
extern void test_bisection_quadratic(void **state);
extern void test_bisection_sin(void **state);
extern void test_bisection_logarithm(void **state);
extern void test_bisection_positive_quadratic(void **state);
extern void test_bisection_invalid_interval(void **state);
extern void test_bisection_no_root(void **state);

extern void test_false_pos_cubic(void **state);
extern void test_false_pos_quadratic(void **state);
extern void test_false_pos_sin(void **state);
extern void test_false_pos_logarithm(void **state);
extern void test_false_pos_positive_quadratic(void **state);
extern void test_false_pos_invalid_interval(void **state);
extern void test_false_pos_no_root(void **state);

extern void test_newton_cubic(void **state);
extern void test_newton_quadratic(void **state);
extern void test_newton_sin(void **state);
extern void test_newton_logarithm(void **state);
extern void test_newton_positive_quadratic(void **state);
extern void test_newton_invalid_interval(void **state);
extern void test_newton_no_root(void **state);

extern void test_secant_cubic(void **state);
extern void test_secant_quadratic(void **state);
extern void test_secant_sin(void **state);
extern void test_secant_logarithm(void **state);
extern void test_secant_positive_quadratic(void **state);
extern void test_secant_invalid_interval(void **state);
extern void test_secant_no_root(void **state);

extern void test_illinois_cubic(void **state);
extern void test_illinois_quadratic(void **state);
extern void test_illinois_sin(void **state);
extern void test_illinois_logarithm(void **state);
extern void test_illinois_positive_quadratic(void **state);
extern void test_illinois_invalid_interval(void **state);
extern void test_illinois_no_root(void **state);

extern void test_pagasus_cubic(void **state);
extern void test_pagasus_quadratic(void **state);
extern void test_pagasus_sin(void **state);
extern void test_pagasus_logarithm(void **state);
extern void test_pagasus_positive_quadratic(void **state);
extern void test_pagasus_invalid_interval(void **state);
extern void test_pagasus_no_root(void **state);

const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_bisection_cubic),
    cmocka_unit_test(test_bisection_quadratic),
    cmocka_unit_test(test_bisection_sin),
    cmocka_unit_test(test_bisection_logarithm),
    cmocka_unit_test(test_bisection_positive_quadratic),
    cmocka_unit_test(test_bisection_invalid_interval),
    cmocka_unit_test(test_bisection_no_root),
    cmocka_unit_test(test_false_pos_cubic),
    cmocka_unit_test(test_false_pos_quadratic),
    cmocka_unit_test(test_false_pos_sin),
    cmocka_unit_test(test_false_pos_logarithm),
    cmocka_unit_test(test_false_pos_positive_quadratic),
    cmocka_unit_test(test_false_pos_invalid_interval),
    cmocka_unit_test(test_false_pos_no_root),
    cmocka_unit_test(test_newton_cubic),
    cmocka_unit_test(test_newton_quadratic),
    cmocka_unit_test(test_newton_sin),
    cmocka_unit_test(test_newton_logarithm),
    cmocka_unit_test(test_newton_positive_quadratic),
    cmocka_unit_test(test_newton_no_root),
    cmocka_unit_test(test_secant_cubic),
    cmocka_unit_test(test_secant_quadratic),
    cmocka_unit_test(test_secant_sin),
    cmocka_unit_test(test_secant_logarithm),
    cmocka_unit_test(test_secant_positive_quadratic),
    cmocka_unit_test(test_secant_no_root),
    cmocka_unit_test(test_illinois_cubic),
    cmocka_unit_test(test_illinois_quadratic),
    cmocka_unit_test(test_illinois_sin),
    cmocka_unit_test(test_illinois_logarithm),
    cmocka_unit_test(test_illinois_positive_quadratic),
    cmocka_unit_test(test_illinois_invalid_interval),
    cmocka_unit_test(test_illinois_no_root),
    cmocka_unit_test(test_pegasus_cubic),
    cmocka_unit_test(test_pegasus_quadratic),
    cmocka_unit_test(test_pegasus_sin),
    cmocka_unit_test(test_pegasus_logarithm),
    cmocka_unit_test(test_pegasus_positive_quadratic),
    cmocka_unit_test(test_pegasus_invalid_interval),
    cmocka_unit_test(test_pegasus_no_root)
};

int main(void) {
    return cmocka_run_group_tests(tests, NULL, NULL);
}
