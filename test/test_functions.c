#include <math.h>
#include "test_functions.h"

float RootFinder_Cubic(float x) {
    return x * x * x - x - 2;
}

float Derivative_Cubic(float x) {
    return (3 * (x * x)) - 1;
}

float RootFinder_Quadratic(float x) {
    return x * x - 2;
}

float Derivative_Quadratic(float x) {
    return 2 * x;
}

float RootFinder_Sine(float x) {
    return sin(x) - 0.5;
}

float Derivative_Sine(float x) {
    return cos(x);
}

float RootFinder_Logarithmic(float x) {
    return log(x) - 1;
}

float Derivative_Logarithmic(float x) {
    return 1 / x;
}

float PositiveQuadratic(float x) {
    return x * x + 2;
}

float Derivative_PositiveQuadratic(float x) {
    return Derivative_Quadratic(x);
}

float ConstantFunc(float x) {
    return 5;
}

float Derivative_ConstantFunc(float x) {
  return 0;
}