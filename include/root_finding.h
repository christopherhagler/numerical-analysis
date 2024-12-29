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

/**
 * False Position method (Regula Falsi) to find the root of a function.
 * The False Position method is an improvement on the bisection method by using the x-intercept of the secant line
 * between f(a) and f(b). The Worst case convergence rate is the same as the bisection method, but it is usually faster.
 * The choice of 'c' is dependent on the function being evaluated. In contrast with the bisection method, the choice
 * of c is static, and it does not depend on the function. Therefore, using information about the function to construct
 * a new interval can yield a better convergence rate.
 *
 * @param f         The function whose root is to be found.
 * @param a         The start of the interval.
 * @param b         The end of the interval.
 * @param tolerance The tolerance for the root approximation.
 * @return          The approximate root, or NAN if no root is found.
 */
float root_false_position(RootFunction f, float a, float b, float tolerance);

/**
 * Secant method to find the root of a function using two initial guesses.
 *
 * @param f         The function whose root is to be found.
 * @param a         The first initial guess.
 * @param b         The second initial guess.
 * @param tolerance The tolerance for the root approximation.
 * @return          The approximate root, or NAN if no root is found.
 */
float root_secant(RootFunction f, float a, float b, float tolerance);

/**
 * Steffensen's method to find the root of a function.
 *
 * @param f         The function whose root is to be found.
 * @param a         The initial guess for the root.
 * @param b         Unused parameter (for compatibility with other methods).
 * @param tolerance The tolerance for the root approximation.
 * @return          The approximate root, or NAN if no root is found.
 */
float root_steffensen(RootFunction f, float a, float b, float tolerance);

/**
 * Illinois method to find the root of a function.
 *
 * @param f         The function whose root is to be found.
 * @param a         The start of the interval.
 * @param b         The end of the interval.
 * @param tolerance The tolerance for the root approximation.
 * @return          The approximate root, or NAN if no root is found.
 */
float root_illinois(RootFunction f, float a, float b, float tolerance);

/**
 * Pegasus method to find the root of a function.
 *
 * @param f         The function whose root is to be found.
 * @param a         The start of the interval.
 * @param b         The end of the interval.
 * @param tolerance The tolerance for the root approximation.
 * @return          The approximate root, or NAN if no root is found.
 */
float root_pegasus(RootFunction f, float a, float b, float tolerance);

/**
 * Newton's method to find the root of a function.
 *
 * @param f         The function whose root is to be found.
 * @param f_prime   The first derivative of f
 * @param a         The start of the interval.
 * @param b         The end of the interval.
 * @param tolerance The tolerance for the root approximation.
 * @return          The approximate root, or NAN if no root is found.
 */
float root_newton(RootFunction f, RootFunction f_prime, float a, float b, const float tolerance);

#endif // ROOT_FINDING_H
