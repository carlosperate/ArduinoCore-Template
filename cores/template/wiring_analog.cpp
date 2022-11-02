#include "api/Common.h"

/**
 * Read the analog value from a pin.
 *
 * The majority of Arduino Cores only have ADC available to some pins,
 * usually referred to Ax pins (e.g. A1, A2, etc). This function should take
 * that into consideration.
 *
 * By default this function returns a 10-bit value. In Arduino Cores where the
 * ADC can be configured to a higher resolution, the return value range of
 * this function can be changed with the analogReadResolution() function.
 *
 * If the resolution configured with analogReadResolution() is higher than
 * what is available by the hardware this function should return a value padded
 * by zeros. If the resolution is lower, the extra bits should be discarded.
 *
 * @param pinNumber The Arduino analog pin to read.
 *
 * @return A 10-bit value, where the max value 1023 represents the operating
 *         voltage (normally 5V or 3.3V).
 */
int analogRead(pin_size_t pinNumber) {}

/**
 * Configure the ADC resolution.
 *
 * This function is usually only available in microcontrollers with an ADC
 * peripheral that can be configured with resolutions different than 10-bits.
 *
 * This function affects the return value range of the analogRead() function.
 *
 * @param resolution The number of bits for the ADC resolution, from 1 to 32.
 */
void analogReadResolution(int resolution) {}

/**
 * Configure the ADC voltage reference.
 *
 * This function depends on the hardware capabilities of the ADC peripheral.
 *
 * It is recommended to typedef a enum to define the different Analog
 * Reference Modes and to change the parameter type to that.
 *
 * @param mode The ADC reference voltage mode to set.
 */
void analogReference(int mode) {}

/**
 * Output a PWM signal to a pin.
 *
 * The duty cycle is Arduino board dependent (different boards have different
 * default frequencies), and there isn't a way to change it.
 *
 * Some Arduino Cores only have PWM available in some pins, so this function
 * should take that in consideration.
 *
 * If a microcontroller has true analogue output via a DAC, this function will
 * use that instead in the pins with the available DAC functionality.
 *
 * Where available, the input resolution for the value parameter can be
 * configured with the analogWriteResolution() function.
 *
 * If the resolution configured by the analogWriteResolution() is higher than
 * what is available by the hardware, this function will discard the extra bits
 * from the return value. If it is lower, it will pad the value with zeros.
 *
 * @param pinNumber The Arduino pin number to output.
 * @param value The duty cycle for the PWM signal, from 0 to 255.
 */
void analogWrite(pin_size_t pinNumber, int value) {}

/**
 * Configure the PWM or DAC resolution.
 *
 * This function is not available in all Arduino boards.
 *
 * This function affects the value parameter range of the analogWrite()
 * function.
 *
 * @param resolution The number of bits for the PWM/DAC resolution,
 *                   from 1 to 32.
 */
void analogWriteResolution(int resolution) {}
