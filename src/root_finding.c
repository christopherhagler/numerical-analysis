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

    float c = a - (((b - a) * f(a)) / (f(b) - f(a)));
    while (fabs(f(c)) > tolerance) {
      if (f(c) * f(a) > 0)
        a = c;
      else
        b = c;

      c = a - ((b - a) * f(a)) / (f(b) - f(a));
    }

    return c;
}

float root_secant(RootFunction f, float a, float b, float tolerance){
    return NAN;
}

float root_steffensen(RootFunction f, float a, float b, float tolerance){
    return NAN;
}

float root_illinois(RootFunction f, float a, float b, float tolerance){
    return NAN;
}

float root_pegasus(RootFunction f, float a, float b, float tolerance){
    return NAN;
}