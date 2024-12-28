#include <math.h>
#include "root_finding.h"

float root_bisection(RootFunction f, float a, float b, float tolerance) {
    // apply IVT to ensure a root exist
    if ((a >= b) || (f(a) * f(b) > 0) || (tolerance < 0))
      return NAN;

    int max = (int) ceil(log2(b-a) - log2(2*tolerance));
    float midpoint;
    for (int i = 0; i < max; i++) {
        midpoint = (a + b) / 2;
        if (f(a) * f(midpoint) < 0)
          b = midpoint;
        else
          a = midpoint;
    }

    return midpoint;
}
