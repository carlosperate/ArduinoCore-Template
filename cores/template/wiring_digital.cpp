/**
 * @file wiring_digital.cpp
 * @brief Function definitions for setting pin mode, digital read and write.
 */
#include "api/Common.h"

/**
 * Set a pin to a specific mode (input or output).
 *
 * Input pull mode can also be enabled using this function.
 *
 * @param pinNumber The Arduino pin to configure.
 * @param pinMode The mode to set the pin.
 */
void pinMode(pin_size_t pinNumber, PinMode pinMode) {
    if (!isPinDigital(pinNumber)) return;

    // Implement: Fill in the pin configuration inside this switch statement
    switch (pinMode) {
        case INPUT: break;
        case OUTPUT: break;
        case INPUT_PULLUP: break;
        case INPUT_PULLDOWN: break;
        case OUTPUT_OPENDRAIN: break;
        default: break;
    }
}

/**
 * Set a pin to a digital HIGH or LOW state.
 *
 * If the pin is configured as an input, this function will instead set the
 * pull up (HIGH) or down (LOW).
 *
 * @param pinNumber The Arduino pin number to write.
 * @param status The state to set the pin, either `HIGH` or `LOW`.
 */
void digitalWrite(pin_size_t pinNumber, PinStatus status) {
    if (!isPinDigital(pinNumber)) return;

    // Implement: Set pin output here
}

/**
 * Read the digital state of a pin.
 *
 * @param pinNumber The Arduino pin number to read.
 * @return The digital state of the pin, either `HIGH` or `LOW`.
 */
PinStatus digitalRead(pin_size_t pinNumber) {
    if (!isPinDigital(pinNumber)) return;

    // Implement: Read pin input here
}
