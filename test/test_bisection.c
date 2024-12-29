#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "test_functions.h"
#include "root_finding.h"

static void test_bisection_cubic(void **state) {
    (void)state; // Unused
    float root = root_bisection(RootFinder_Cubic, 1.0, 2.0, 1e-6);
    assert_false(isnan(root));
    assert_float_equal(root, 1.521380, 1e-5);
}

static void test_bisection_quadratic(void **state) {
    (void)state; // Unused
    float root = root_bisection(RootFinder_Quadratic, 0.0, 2.0, 1e-6);
    assert_false(isnan(root));
    assert_float_equal(root, 1.414214, 1e-5);
}

static void test_bisection_sin(void **state) {
    (void)state; // Unused
    float root = root_bisection(RootFinder_Sine, 0.0, 2.0, 1e-6);
    assert_false(isnan(root));
    assert_float_equal(root, 0.523599, 1e-5);
}

static void test_bisection_logarithm(void **state) {
    (void)state; // Unused
    float root = root_bisection(RootFinder_Logarithmic, 1.0, 3.0, 1e-6);
    assert_false(isnan(root));
    assert_float_equal(root, 2.718282, 1e-5);
}

static void test_bisection_positive_quadratic(void **state) {
    (void)state; // Unused
    float root = root_bisection(PositiveQuadratic, -2.0, 2.0, 1e-6);
    assert_true(isnan(root));
}

static void test_bisection_invalid_interval(void **state) {
    (void)state; // Unused
    float root = root_bisection(RootFinder_Quadratic, 1.0, 1.0, 1e-6);
    assert_true(isnan(root));
}

static void test_bisection_no_root(void **state) {
    (void)state; // Unused
    float root = root_bisection(RootFinder_Quadratic, 2.0, 3.0, 1e-6);
    assert_true(isnan(root));
}