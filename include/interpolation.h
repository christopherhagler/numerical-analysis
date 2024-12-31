#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include <stddef.h>

/*
 * InterpolationMethod: The supported interpolation techniques
 */
typedef enum {
    INTERP_LAGRANGE,
    INTERP_NEWTON,
    INTERP_HERMITE
} InterpolationMethod;

/*
 * InterpolationPoly: Holds information about the constructed polynomial.
 *   - degree: The polynomial degree (e.g., n-1 for n data points).
 *   - coeffs: An array of coefficients or other representation of the polynomial.
 *   - method: Which method was used to create it.
 *
 * For Lagrange polynomials, 'coeffs' might be the direct polynomial coefficients.
 * For Newton polynomials, 'coeffs' might be the Newton form coefficients (divided differences).
 */
typedef struct {
    InterpolationMethod method;
    size_t degree;
    float *coeffs;
} InterpolationPoly;

/*
 * create_interpolation_poly:
 *   Creates an interpolation polynomial for given data points (x[i], y[i]).
 *   - x, y: arrays of length n containing the data points.
 *   - n: number of data points (n >= 2).
 *   - method: whether to use Lagrange, Newton, etc.
 *
 *   Returns a pointer to a newly allocated InterpolationPoly, or NULL on failure.
 *   The caller is responsible for freeing it with 'free_interpolation_poly()'.
 */
InterpolationPoly *create_interpolation_poly(const float *x, const float *y, size_t n, InterpolationMethod method);

/*
 * evaluate_interpolation:
 *   Evaluates the interpolation polynomial at a given point 'X'.
 *   - poly: pointer to a valid InterpolationPoly created by create_interpolation_poly().
 *   - X:    the point at which to evaluate the polynomial.
 *
 *   Returns the interpolated value at X.
 */
float evaluate_interpolation(const InterpolationPoly *poly, float X);

/*
 * free_interpolation_poly:
 *   Frees the memory allocated by create_interpolation_poly().
 *   Safe to call with a NULL pointer.
 */
void free_interpolation_poly(InterpolationPoly *poly);

#endif // INTERPOLATION_H
