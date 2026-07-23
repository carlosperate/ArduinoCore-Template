#include "Uart.h"

namespace arduino {

Uart::Uart() {}

void Uart::begin(const unsigned long baudrate) {
    begin(baudrate, SERIAL_8N1);
}

void Uart::begin(const unsigned long baudrate, const uint16_t config) {
    uint8_t word_size = 8;
    switch (config & SERIAL_DATA_MASK) {
        case SERIAL_DATA_5: word_size = 5; break;
        case SERIAL_DATA_6: word_size = 6; break;
        case SERIAL_DATA_7: word_size = 7; break;
        case SERIAL_DATA_8: word_size = 8; break;
    }
    // Implement: Set word size here

    uint8_t stop_bits = 1;
    switch (config & SERIAL_STOP_BIT_MASK) {
        case SERIAL_STOP_BIT_1: stop_bits = 1; break;
        case SERIAL_STOP_BIT_2: stop_bits = 2; break;
    }
    // Implement: Set stop bits here

    typedef enum {
        NONE = 0,
        ODD = 1,
        EVEN = 2,
    } parity_mode_t;
    parity_mode_t parity_mode = ODD;
    switch (config & SERIAL_PARITY_MASK) {
        case SERIAL_PARITY_EVEN: parity_mode = EVEN; break;
        case SERIAL_PARITY_ODD: parity_mode = ODD; break;
        case SERIAL_PARITY_NONE: parity_mode = NONE; break;
    }
    // Implement: Set parity mode here
}

void Uart::end(void) {}

int Uart::available() {
    // Implement: query the number of bytes in the hardware RX buffer.
    int hw_bytes_available = 0;
    // Add the byte held back by a pending peek() (see peek() below).
    return hw_bytes_available + (peeked >= 0 ? 1 : 0);
}

int Uart::peek() {
    // Arduino's peek() returns the next byte without consuming it.
    // In the case this implementation can't do that, pull and stash one byte
    if (peeked < 0) {
        // Implement: read one byte from hardware, or < 0 if none.
        int c = -1;
        peeked = (c < 0) ? -1 : c;
    }
    return peeked;
}

int Uart::read() {
    // Return the byte stashed by a previous peek() before touching hardware,
    // so the peeked byte is not lost or returned out of order.
    if (peeked >= 0) {
        int c = peeked;
        peeked = -1;
        return c;
    }
    // Implement: read one byte from hardware, or < 0 if none.
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
