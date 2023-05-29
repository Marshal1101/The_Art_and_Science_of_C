/**
 * @file rational.h
 * @brief exercise 16-5
 * @date 2023-05-29
 */

#include "genlib.h"

/**
 * @brief The type rationalT, which can be used to represent a rational value.
 * Usage: rationalT r
 */
typedef struct {
    int num, den;
} rationalT;

/**
 * @brief Create a Rational object
 * A function CreateRational (num, den), which returns the rational
 * @param num 
 * @param den 
 * @return rationalT 
 */
rationalT CreateRational(int num, int den);

/**
 * @brief A function AddRational (r1, r2), 
 * which returns the sum of two rational numbers. 
 * @param r1 
 * @param r2 
 * @return rationalT 
 */
rationalT AddRational(rationalT r1, rationalT r2);

/**
 * @brief A function MultiplyRational (r1, r2),
 * which returns the product of two rational numbers.
 * @param r1 
 * @param r2 
 * @return rationalT 
 */
rationalT MultiplyRational(rationalT r1, rationalT r2);

/**
 * @brief Get the Rational object
 * A function GetRational (r), which reads
 * a retinal number from the user
 * in the from num/den.
 * @return rationalT 
 */
rationalT GetRational(void);

/**
 * @brief Get the String To Rational object
 * @param r 
 * @return rationalT 
 */
rationalT GetStringToRational(string r);

/**
 * @brief A function PrintRational (r), 
 * which displays the number as 
 * a fraction on the screen.
 * @param r 
 */
void PrintRational(rationalT r);