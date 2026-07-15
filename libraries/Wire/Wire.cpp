#include "Wire.h"

using namespace arduino;

TwoWire::TwoWire() {}

void TwoWire::begin() {
    begin(0);
}

void TwoWire::begin(uint8_t address) {
    peripheral_address = address;
    if (peripheral_address == 0) {
        // Implement: Configure I2C as a controller here.
    } else {
        // Implement: Configure I2C as a peripheral here.
    }
}

void TwoWire::end() {}

size_t TwoWire::requestFrom(uint8_t address, size_t len) {
    return requestFrom(address, len, true);
}

size_t TwoWire::requestFrom(uint8_t address, size_t len, bool stopBit = true) {
    uint8_t read_buffer[I2C_BUFFER_LENGTH] = {0};

    // Reads larger than the RX buffer would drop the extra bytes, so cap early
    if (len > I2C_BUFFER_LENGTH) len = I2C_BUFFER_LENGTH;

    // Implement: Fill read_buffer[] with I2C read data here, and capture into
    // number_of_bytes_received how many bytes were read in total
    size_t number_of_bytes_received = len;

    // Move the data from read_buffer into the RX ring buffer
    rx_buffer.clear();
    for (size_t i = 0; i < number_of_bytes_received; i++) {
        rx_buffer.store_char(read_buffer[i]);
    }

    return number_of_bytes_received;
}

void TwoWire::beginTransmission(uint8_t address) {
    memset(tx_buffer, 0, I2C_BUFFER_LENGTH);
    tx_buffer_i = 0;
    clearWriteError();
}

uint8_t TwoWire::endTransmission() {
    return endTransmission(true);
}

uint8_t TwoWire::endTransmission(bool stopBit) {
    if (getWriteError()) {
        return getWriteError();
    }
    // Implement: Send the tx_buffer via I2C with or without the stop bit
    return 0;
}

size_t TwoWire::write(uint8_t value) {
    if (tx_buffer_i >= I2C_BUFFER_LENGTH) {
        setWriteError(1 /* data too long */);
        return 0;
    }
    tx_buffer[tx_buffer_i++] = value;
    return 1;
}

size_t TwoWire::write(const uint8_t *buffer, size_t size) {
    // Per the Arduino docs, bytes that do not fit in the buffer are dropped
    if (tx_buffer_i + size > I2C_BUFFER_LENGTH) {
        setWriteError(1 /* data too long */);
        size = I2C_BUFFER_LENGTH - tx_buffer_i;
    }
    memcpy(tx_buffer + tx_buffer_i, buffer, size);
    tx_buffer_i += size;
    return size;
}

int TwoWire::available() {
    return rx_buffer.available();
}

int TwoWire::peek() {
    return rx_buffer.peek();
}

int TwoWire::read() {
    return rx_buffer.read_char();
}

void TwoWire::setClock(uint32_t freq) {}

void TwoWire::onReceive(void (*handler)(int)) {
    // Implement: Configure the interrupts to run the onReceive handler
    onReceiveHandler = handler;
}

void TwoWire::onRequest(void (*handler)(void)) {
    // Implement: Configure the interrupts to run the onRequest handler
    onRequestHandler = handler;
}

void TwoWire::setWireTimeout(uint32_t timeout, bool reset_on_timeout) {
    timeout_us = timeout;
    timeout_reset = reset_on_timeout;
    // Implement: Configure the timer or I2C peripheral to timeout
}

void TwoWire::clearWireTimeoutFlag(void) {
    timeout_flag = false;
}

bool TwoWire::getWireTimeoutFlag(void) {
    return timeout_flag;
}

TwoWire Wire;
