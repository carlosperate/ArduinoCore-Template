#include "api/Common.h"

/**
 * Wait for a given amount of time.
 *
 * This function generally busy waits, but it must not disable interrupts.
 *
 * @param ms Time to wait in milliseconds.
 */
void delay(unsigned long ms) {}

/**
 * Like delay(), with with microseconds instead of milliseconds.
 *
 * @param us Time to wait in microseconds.
 */
void delayMicroseconds(unsigned int us) {}

/**
 * Get the number of milliseconds since the programme started running.
 *
 * The time at which any counters overflow should be documented here, together
 * with the resolution (minimum time step).
 *
 * @return Time elapsed since startup, in milliseconds.
 */
unsigned long millis() {
    return 0;
}

/**
 * Get the number of microseconds since the programme started running.
 *
 * The time at which any counters overflow should be documented here, together
 * with the resolution (minimum time step).
 *
 * @return Time elapsed since startup, in microseconds.
 */
unsigned long micros() {
    return 0;
}
