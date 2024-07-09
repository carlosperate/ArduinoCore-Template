#include "api/Common.h"

/**
 * Generate a pseudo random number from zero to (max - 1).
 *
 * @param max Upper bound for the generated number, exclusive of this number.
 *
 * @return A random integer between 0 and (max - 1).
 */
long random(long max) {
    return 0;
}

/**
 * Generate a pseudo random number from min to (max - 1).
 *
 * @param min Lower bound for the generated number, inclusive of this number.
 * @param max Upper bound for the generated number, exclusive of this number.
 *
 * @return A random integer between 0 and (max - 1).
 */
long random(long min, long max) {
    if (min >= max) {
        return min;
    }
    return random(max - min) + min;
}

/**
 * Seeds the pseudo random number generator with a specific value.
 *
 * This function should be called before random(), otherwise the sequence of
 * values returned by random() will always be the same.
 *
 * Calling this function with a seed of 0 has no effect.
 */
void randomSeed(unsigned long seed) {
    if (seed) {
        // Implement: Seed your random number generator here
    }
}
