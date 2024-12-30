#include <float.h>
#include <math.h>
#include "root_finding.h"

float root_bisection(const RootFunction f, float a, float b, const float tolerance) {
    if ((a >= b) || (f(a) * f(b) > 0) || (tolerance < 0))
      return NAN;

    int max = (int) ceil(log2(b-a) - log2(2*tolerance));
    float midpoint = NAN;
    for (int i = 0; i < max; i++) {
        midpoint = (a + b) / 2;
        if (f(a) * f(midpoint) < 0)
          b = midpoint;
        else
          a = midpoint;
    }

    return midpoint;
}

float root_false_position(const RootFunction f, float a, float b, const float tolerance) {
    if ((a >= b) || (f(a) * f(b) > 0) || (tolerance < 0))
      return NAN;

    int max_interations = 10000;
    int current_iteration = 0;
    float c = a - (((b - a) * f(a)) / (f(b) - f(a)));
    while ((fabs(f(c)) > tolerance) && (current_iteration++ < max_interations)) {
      if (f(c) * f(a) > 0)
        a = c;
      else
        b = c;

      c = a - ((b - a) * f(a)) / (f(b) - f(a));
    }

    return c;
}

float root_newton(const RootFunction f, const RootFunction f_prime, float a, float b, const float tolerance) {
    if ((a >= b) || (tolerance < 0) || !f || !f_prime)
        return NAN;

    float point = (a + b)/2.0f;

    int max_iterations = 10000;
    for (int i = 0; i < max_iterations; i++) {
        if (fabs(f(point)) < tolerance)
            return point;

        float denominator = f_prime(point);
        if (fabs(denominator) < FLT_EPSILON)
            return NAN;

        point = point - (f(point) / f_prime(point));
    }

    return NAN;
}

/**
 * The secant method is a variation of Newton's method. Sometimes, we simply may not have the derivative
 * of the function f, or it may be very costly to evaluate. Therefore, the secant method uses a finite
 * difference approximation of the derivative.
 */
float root_secant(const RootFunction f, const float a, const float b, const float tolerance){
    if ((a >= b) || (tolerance < 0) || !f)
        return NAN;

    float new_point = (a + b)/2.0f;
    float previous_point = a;

    int max_iterations = 10000;
    for (int i = 0; i < max_iterations; i++) {
        if (fabs(f(new_point)) < tolerance)
            return new_point;

        float numerator = (f(new_point) * (new_point - previous_point));
        float denominator = (f(new_point) - f(previous_point));

        if (fabs(denominator) < FLT_EPSILON)
            return NAN;

        previous_point = new_point;
        new_point = new_point - (numerator / denominator);
    }

    return NAN;
}

float root_steffensen(RootFunction f, float a, float b, float tolerance){
    if ((a >= b) || (tolerance < 0) || !f)
        return NAN;

    float new_point = (a + b)/2.0f;
    float previous_point = a;

    int max_iterations = 10000;
    for (int i = 0; i < max_iterations; i++) {
        if (fabs(f(new_point)) < tolerance)
            return new_point;

        // TODO: check for division by zero with f(previous_point)
        float denominator = (f(previous_point + f(previous_point)) - f(previous_point)) / f(previous_point);
        if (denominator == 0)
            return NAN;

        new_point = (previous_point - f(previous_point)) / denominator;
        previous_point = new_point;
    }

    return NAN;
}

float root_illinois(RootFunction f, float a, float b, float tolerance){
    return NAN;
}

float root_pegasus(RootFunction f, float a, float b, float tolerance){
    return NAN;
}