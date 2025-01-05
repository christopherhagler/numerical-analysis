#include <stdlib.h>
#include <string.h>
#include "interpolation.h"

static void lagrangeCoeffs(int n, const float *x, const float *y, float *C) {
  memset(C, 0, (n+1)*sizeof(float));

  float *Lj = (float *)calloc(n+1, sizeof(float));
  if (!Lj) {
    // TODO: return an error code or something
    return;
  }

  for (int j = 0; j <= n; j++) {
    memset(Lj, 0, (n+1)*sizeof(float));
    Lj[0] = 1.0;

    for (int m = 0; m <= n; m++) {
      if (m == j) continue;

      float denom  = (x[j] - x[m]);
      float factor = -x[m];

      for (int k = n; k >= 1; k--) {
        float oldVal = Lj[k];
        Lj[k] = (Lj[k-1] + factor*oldVal) / denom;
      }

      Lj[0] = (factor * Lj[0]) / denom;
    }

    for (int k = 0; k <= n; k++) {
      C[k] += Lj[k] * y[j];
    }
  }

  free(Lj);
}


/**
* TODO: Finish Implementing
*/
InterpolationPoly *create_interpolation_poly(const float *x, const float *y, size_t n, InterpolationMethod method) {
  InterpolationPoly *poly = (InterpolationPoly *) malloc(sizeof(InterpolationPoly));
  poly->coeffs = (float *) calloc(n+1, sizeof(float));

  switch (method) {
    case INTERP_LAGRANGE:
      lagrangeCoeffs(n, x, y, poly->coeffs);
      break;
    case INTERP_NEWTON:
    case INTERP_HERMITE:
    default:
      break;
  }

  return poly;
}