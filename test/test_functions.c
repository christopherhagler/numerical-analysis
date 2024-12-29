#include <math.h>
#include "test_functions.h"

// Function 1: f(x) = x^3 - x - 2 (has a root)
float RootFinder_Cubic(float x) {
    return x * x * x - x - 2;
}

// Function 1 prime: f'(x) = 3x^2 - 1
float Derivative_Cubic(float x) {
    return (3 * (x * x)) - 1;
}

// Function 2: f(x) = x^2 - 2 (has a root)
float RootFinder_Quadratic(float x) {
    return x * x - 2;
}

// Function 2 prime: f'(x) = 2x
float Derivative_Quadratic(float x) {
    return 2 * x;
}

// Function 3: f(x) = sin(x) - 0.5 (has a root)
float RootFinder_Sine(float x) {
    return sin(x) - 0.5;
}

// Function 3 prime: f'(x) = cos(x)
float Derivative_Sine(float x) {
    return cos(x);
}

// Function 4: f(x) = log(x) - 1 (has a root, x > 0)
float RootFinder_Logarithmic(float x) {
    return log(x) - 1;
}

// Function 4 prime: f'(x) = 1 / x
float Derivative_Logarithmic(float x) {
    return 1 / x;
}

// Function 5: f(x) = x^2 + 2 (no root, always positive)
float PositiveQuadratic(float x) {
    return x * x + 2;
}

// Function 5 prime: f'(x) = 2x
float Derivative_PositiveQuadratic(float x) {
    return Derivative_Quadratic(x);
}