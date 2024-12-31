#include <math.h>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "test_functions.h"
#include "root_finding.h"

static void test_illinois_cubic(void **state) {
    (void)state; // Unused
    float root = root_illinois(RootFinder_Cubic, 1.0, 2.0, 1e-6);
    assert_false(isnan(root));
    assert_float_equal(root, 1.521380, 1e-5);
}

static void test_illinois_quadratic(void **state) {
    (void)state; // Unused
    float root = root_illinois(RootFinder_Quadratic, 0.0, 2.0, 1e-6);
    assert_false(isnan(root));
    assert_float_equal(root, 1.414214, 1e-5);
}

static void test_illinois_sin(void **state) {
    (void)state; // Unused
    float root = root_illinois(RootFinder_Sine, 0.0, 2.0, 1e-6);
    assert_false(isnan(root));
    assert_float_equal(root, 0.523599, 1e-5);
}

static void test_illinois_logarithm(void **state) {
    (void)state; // Unused
    float root = root_illinois(RootFinder_Logarithmic, 1.0, 3.0, 1e-6);
    assert_false(isnan(root));
    assert_float_equal(root, 2.718282, 1e-5);
}

static void test_illinois_positive_quadratic(void **state) {
    (void)state; // Unused
    float root = root_illinois(PositiveQuadratic, -2.0, 2.0, 1e-6);
    assert_true(isnan(root));
}

static void test_illinois_invalid_interval(void **state) {
    (void)state; // Unused
    float root = root_illinois(RootFinder_Quadratic, 1.0, 1.0, 1e-6);
    assert_true(isnan(root));
}

static void test_illinois_no_root(void **state) {
    (void)state; // Unused
    float root = root_illinois(ConstantFunc, 5.0, 6.0, 1e-6);
    assert_true(isnan(root));
}