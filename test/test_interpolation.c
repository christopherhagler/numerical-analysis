#include <math.h>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "interpolation.h"

static void test_lagrange_quadratic(void **state) {
    (void)state; // Unused

    float x[] = {0.0, 1.0, 2.0, 3.0};
    float y[] = {0.0, 1.0, 4.0, 9.0};

    InterpolationPoly *poly = create_interpolation_poly(x, y, 3, INTERP_LAGRANGE);
    // the coefficient array should be [0.0, 0.0, 1.0] which represents x^2
    assert_float_equal(poly->coeffs[0], 0.0, 1e-5);
    assert_float_equal(poly->coeffs[1], 0.0, 1e-5);
    assert_float_equal(poly->coeffs[2], 1.0, 1e-5);
}