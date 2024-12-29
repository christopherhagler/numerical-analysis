#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "test_functions.h"
#include "root_finding.h"

static void test_newton_cubic(void **state) {
    (void)state; // Unused
    float root = root_newton(RootFinder_Cubic, Derivative_Cubic, 1.0, 2.0, 1e-6);
    assert_false(isnan(root));
    assert_float_equal(root, 1.521380, 1e-5);
}

static void test_newton_quadratic(void **state) {
    (void)state; // Unused
    float root = root_newton(RootFinder_Quadratic, Derivative_Quadratic,  0.0, 2.0, 1e-6);
    assert_false(isnan(root));
    assert_float_equal(root, 1.414214, 1e-5);
}

static void test_newton_sin(void **state) {
    (void)state; // Unused
    float root = root_newton(RootFinder_Sine, Derivative_Sine,  0.0, 2.0, 1e-6);
    assert_false(isnan(root));
    assert_float_equal(root, 0.523599, 1e-5);
}

static void test_newton_logarithm(void **state) {
    (void)state; // Unused
    float root = root_newton(RootFinder_Logarithmic, Derivative_Logarithmic,  1.0, 3.0, 1e-6);
    assert_false(isnan(root));
    assert_float_equal(root, 2.718282, 1e-5);
}

static void test_newton_positive_quadratic(void **state) {
    (void)state; // Unused
    float root = root_newton(PositiveQuadratic, Derivative_PositiveQuadratic,  -2.0, 2.0, 1e-6);
    assert_true(isnan(root));
}

static void test_newton_invalid_interval(void **state) {
    (void)state; // Unused
    float root = root_newton(RootFinder_Quadratic, Derivative_Quadratic,  1.0, 1.0, 1e-6);
    assert_true(isnan(root));
}

static void test_newton_no_root(void **state) {
    (void)state; // Unused
    float root = root_newton(RootFinder_Quadratic, Derivative_Quadratic,  5.0, 6.0, 1e-6);
    assert_true(root);
}