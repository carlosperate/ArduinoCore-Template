#include "Uart.h"

namespace arduino {

Uart::Uart() {}

void Uart::begin(const unsigned long baudrate) {
    begin(baudrate, SERIAL_8N1);
}

void Uart::begin(const unsigned long baudrate, const uint16_t config) {
    uint8_t word_size = 8;
    switch (config & SERIAL_DATA_MASK) {
        case SERIAL_DATA_5:
            word_size = 5;
            break;
        case SERIAL_DATA_6:
            word_size = 6;
            break;
        case SERIAL_DATA_7:
            word_size = 7;
            break;
        case SERIAL_DATA_8:
            word_size = 8;
            break;
    }

    uint8_t stop_bits = 1;
    switch (config & SERIAL_STOP_BIT_MASK) {
        case SERIAL_STOP_BIT_1:
            stop_bits = 1;
            break;
        case SERIAL_STOP_BIT_2:
            stop_bits = 2;
            break;
    }

    typedef enum {
        NONE = 0,
        ODD = 1,
        EVEN = 2,
    } parity_mode_t;
    parity_mode_t parity_mode = ODD;
    switch (config & SERIAL_PARITY_MASK) {
        case SERIAL_PARITY_EVEN:
            parity_mode = EVEN;
            break;
        case SERIAL_PARITY_ODD:
            parity_mode = ODD;
            break;
        case SERIAL_PARITY_NONE:
            parity_mode = NONE;
            break;
    }
}

void Uart::end(void) {}

int Uart::available() {
    return 0;
}

int Uart::peek() {
    return 0;
}

int Uart::read() {
    return 0;
}

void Uart::flush() {}

size_t Uart::write(const uint8_t c) {
    return 0;
}

size_t Uart::write(const uint8_t* buf, const size_t size) {
    return 0;
}

Uart::operator bool() {
    // If there is no initialisation delay this can just return true
    return true;
}

}  // namespace arduino

// Instantiate user accessible Serial instance
arduino::UART Serial;
