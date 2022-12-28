#include <Arduino.h>

// This function can be overwritten by the variant-specific code
void initVariant() __attribute__((weak));
void initVariant() {}

/**
 * Code to initialise the board goes here.
 */
void init() {}

int main(void) {
    init();
    initVariant();

    setup();

    for (;;) {
        loop();

        // User can defined this function in a sketch to run after every loop iteration
        if (arduino::serialEventRun) arduino::serialEventRun();
    }

    return 0;
}
