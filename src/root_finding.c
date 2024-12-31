#include <float.h>
#include <math.h>
#include "root_finding.h"

#include <stddef.h>

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

float root_newton(const RootFunction f, const RootFunction f_prime, float guess, const float tolerance) {
    if (!guess || (tolerance < 0) || !f || !f_prime)
        return NAN;

    int max_iterations = 10000;
    for (int i = 0; i < max_iterations; i++) {
        if (fabs(f(guess)) < tolerance)
            return guess;

        float denominator = f_prime(guess);
        if (fabs(denominator) < FLT_EPSILON)
            return NAN;

        guess = guess - (f(guess) / f_prime(guess));
    }

    return NAN;
}

/**
 * The secant method is a variation of Newton's method. Sometimes, we simply may not have the derivative
 * of the function f, or it may be very costly to evaluate. Therefore, the secant method uses a finite
 * difference approximation of the derivative.
 */
float root_secant(const RootFunction f, float guess, const float tolerance){
    if (!guess || (tolerance < 0) || !f)
        return NAN;

    float another_guess = guess + (0.5f * guess);

    int max_iterations = 10000;
    for (int i = 0; i < max_iterations; i++) {
        if (fabs(f(guess)) < tolerance)
            return guess;

        float numerator = (f(guess) * (guess - another_guess));
        float denominator = (f(guess) - f(another_guess));

        if (fabs(denominator) < FLT_EPSILON)
            return NAN;

        another_guess = guess;
        guess = guess - (numerator / denominator);
    }

    return NAN;
}

float root_steffensen(const RootFunction f, const float a, const float b, const float tolerance) {
    if ((a >= b) || (tolerance <= 0.0f) || (f == NULL))
        return NAN;

    float x_current = 0.5f * (a + b);

    const int max_iterations = 10000;
    for (int i = 0; i < max_iterations; i++) {
        float fx = f(x_current);
        if (fabsf(fx) < tolerance)
            return x_current;

        float f_xplusfx = f(x_current + fx);
        float denominator = f_xplusfx - fx;
        if (fabsf(denominator) < FLT_EPSILON)
            return NAN;

        float x_next = x_current - (fx * fx) / denominator;
        if (fabsf(x_next - x_current) < tolerance) {
            return x_next;
        }

        x_current = x_next;
    }

    return NAN;
}

float root_illinois(const RootFunction f, float a, float b, const float tolerance) {
    float fa = f(a);
    float fb = f(b);
    if (fa * fb > 0.0f)
        return NAN;

    const int max_iterations = 1000;
    for (int i = 0; i < max_iterations; i++) {
        float c = (a * fb - b * fa) / (fb - fa);
        float fc = f(c);

        if (fabs(fc) < tolerance)
            return c;

        if (fa * fc < 0.0f) {
            b = c;
            fb = fc;
            fa *= 0.5f;
        } else {
            a = c;
            fa = fc;
            fb *= 0.5f;
        }
    }

    return 0.5f * (a + b);
}

float root_pegasus(const RootFunction f, float a, float b, const float tolerance) {
    float fa = f(a);
    float fb = f(b);
    if (fa * fb > 0.0f)
        return NAN;

    const int max_iterations = 1000;
    for (int i = 0; i < max_iterations; i++) {
        float c  = (a * fb - b * fa) / (fb - fa);
        float fc = f(c);

        if (fabs(fc) < tolerance)
            return c;

        float old_fa = fa;
        float old_fb = fb;

        if (old_fb * fc > 0.0f) {
            b  = c;
            fb = fc;
            fa = old_fa * (fc / (fc + old_fb));
        } else {
            a  = c;
            fa = fc;
            fb = old_fb * (fc / (fc + old_fa));
        }
    }

    return 0.5f * (a + b);
}