/*
* File: random.h
* -------------------
* Library package to produce pseudo-random numbers.
*/

#ifndef _ramdom_h
#define _ramdom_h

#include "genlib.h"

/*
* Function: Randomize
* Usage: Randomize();
* ----------------------------
* This function sets the random seed so that the random sequence
* is unpredictable. During the debugging phase, it is best not 
* to call this function, so that program behavior is repeatable.
*/

void Randomize(void);

/*
* Function: RandomInteger
* Usage: n = RandomInteger(low, high);
* ---------------------------------------------------
* This function returns a random integer in the range low to high,
* inclusive.
*/

int RandomInteger(int low, int high);

/*
* Function: RandomReal
* Usage: d = RandomReal(low, high);
* -----------------------------------------------
* This function returns a random real number in the half-open
* interval [low..high], meaning that the result is always
* greater than or equal to low but strictly less than high.
*/

double RandomReal(double low, double high);

/*
* Function: RandomChance
* Usage: if (RandomChance(p))…
* -------------------------------------------
* The RandomChance function returns TRUE with the probability
* indicated by p, which should be a floating-point number between
* 0 (meaning never) and 1 (meaning always). For example, calling 
* RandomChance(.30) returns TRUE 30 percent of the time.
*/
bool RandomChance(double p);

/**
 * @brief Set the Inhanced Random object
 * Usage; SetInhancedRandom(TRUE);
 * --------------------------------------
 * it's to return more randomized values for frequent cases
 */
void SetInhancedRandom(bool flag);



#endif