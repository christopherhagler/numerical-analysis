#ifndef ROOT_FINDING_H
#define ROOT_FINDING_H

/**
 * Function pointer type for a function that takes a single float
 * as input and returns a float.
 */
typedef float (*RootFunction)(float);

/**
 * Bisection method to find the root of a function in a given interval.
 *
 * @param f         The function whose root is to be found.
 * @param a         The start of the interval.
 * @param b         The end of the interval.
 * @param tolerance The tolerance for the root approximation.
 * @return          The approximate root, or NAN if no root is found.
 */
float root_bisection(RootFunction f, float a, float b, float tolerance);

#endif // ROOT_FINDING_H
