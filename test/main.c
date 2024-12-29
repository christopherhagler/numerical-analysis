#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "root_finding.h"
#include "test_bisection.c"
#include "test_newton.c"
#include "test_false_position.c"

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
    cmocka_unit_test(test_newton_invalid_interval),
    cmocka_unit_test(test_newton_no_root)
};

int main(void) {
    return cmocka_run_group_tests(tests, NULL, NULL);
}
