#include "api/Common.h"

// Only a single tone can be played at a time, so this can be used to keep
// track of the current pin playing the tone.
static int current_tone_pin = -1;

/**
 * Generate a square wave on the specified pin & frequency at a 50% duty cycle.
 *
 * In the official API, only a single tone can be played at a time.
 * When this functions is called when a tone is already playing on a different
 * pin, then this function will have no effect. If the same pin is used, the
 * tone will be updated to the new frequency.
 *
 * To create multiple tones on different pins, the user must call noTone()
 * before calling tone() on a different pin.
 *
 * This function is non-blocking, so when called with a duration value, the
 * function will return immediately while the tone plays in the background.
 *
 * @param _pin The pin to output the tone.
 * @param frequency The frequency of the tone in Hz.
 * @param duration The duration of the tone in milliseconds.
 *                 If set to 0, the tone will play indefinitely or until
 *                 noTone() is called.
 *                 Optional argument with a default value of zero.
 */
void tone(uint8_t _pin, unsigned int frequency, unsigned long duration) {
    if (!isPinPwm(_pin)) return;

    if (current_tone_pin != -1 && current_tone_pin != _pin) return;

    // Implement: Set the PWM frequency for the given pin at 50% duty cycle

    current_tone_pin = _pin;

    if (duration) {
        // Implement: If a duration value is provided the tone should stop
        // playing after that time without blocking this function.
        // Remember to set current_tone_pin to -1 when the tone stops.
    }
}

/**
 * Stop the generation of a tone on a pin.
 *
 * If the given pin is not playing a tone, or no tone is being played,
 * this function will have no effect.
 *
 * @param _pin The pin to stop playing the tone.
 */
void noTone(uint8_t _pin) {
    if (_pin != current_tone_pin) return;

    // Implement: Stop the PWM output on the given pin

    current_tone_pin = -1;
}
