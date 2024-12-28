#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <math.h>
#include "root_finding.h"

// Function 1: f(x) = x^3 - x - 2 (has a root)
float function1(float x) {
    return x * x * x - x - 2;
}

// Function 2: f(x) = x^2 - 2 (has a root)
float function2(float x) {
    return x * x - 2;
}

// Function 3: f(x) = sin(x) - 0.5 (has a root)
float function3(float x) {
    return sin(x) - 0.5;
}

// Function 4: f(x) = log(x) - 1 (has a root, x > 0)
float function4(float x) {
    return log(x) - 1;
}

// Function 5: f(x) = x^2 + 2 (no root, always positive)
float function5(float x) {
    return x * x + 2;
}

// Test case: Valid root for f(x) = x^3 - x - 2
static void test_function1_root(void **state) {
    (void)state; // Unused
    float root = root_false_position(function1, 1.0, 2.0, 1e-6);
    assert_false(isnan(root));
    assert_float_equal(root, 1.521380, 1e-5);
}

// Test case: Valid root for f(x) = x^2 - 2
static void test_function2_root(void **state) {
    (void)state; // Unused
    float root = root_false_position(function2, 0.0, 2.0, 1e-6);
    assert_false(isnan(root));
    assert_float_equal(root, 1.414214, 1e-5);
}

// Test case: Valid root for f(x) = sin(x) - 0.5
static void test_function3_root(void **state) {
    (void)state; // Unused
    float root = root_false_position(function3, 0.0, 2.0, 1e-6);
    assert_false(isnan(root));
    assert_float_equal(root, 0.523599, 1e-5);
}

// Test case: Valid root for f(x) = log(x) - 1
static void test_function4_root(void **state) {
    (void)state; // Unused
    float root = root_false_position(function4, 1.0, 3.0, 1e-6);
    assert_false(isnan(root));
    assert_float_equal(root, 2.718282, 1e-5);
}

// Test case: No root for f(x) = x^2 + 2
static void test_function5_no_root(void **state) {
    (void)state; // Unused
    float root = root_false_position(function5, -2.0, 2.0, 1e-6);
    assert_true(isnan(root));
}

// Test case: Invalid interval (a = b)
static void test_invalid_interval(void **state) {
    (void)state; // Unused
    float root = root_false_position(function2, 1.0, 1.0, 1e-6);
    assert_true(isnan(root));
}

// Test case: Invalid interval (f(a) * f(b) > 0)
static void test_no_sign_change(void **state) {
    (void)state; // Unused
    float root = root_false_position(function2, 2.0, 3.0, 1e-6);
    assert_true(isnan(root));
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_function1_root),
        cmocka_unit_test(test_function2_root),
        cmocka_unit_test(test_function3_root),
        cmocka_unit_test(test_function4_root),
        cmocka_unit_test(test_function5_no_root),
        cmocka_unit_test(test_invalid_interval),
        cmocka_unit_test(test_no_sign_change),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
