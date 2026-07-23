#include "SPI.h"

using namespace arduino;

SpiClass::SpiClass() {}

void SpiClass::begin() {}
void SpiClass::end() {}

void SpiClass::usingInterrupt(int interruptNumber) {}
void SpiClass::notUsingInterrupt(int interruptNumber) {}

void SpiClass::beginTransaction(SPISettings settings) {}
void SpiClass::endTransaction(void) {}

uint8_t SpiClass::transfer(uint8_t data) {
    return 0;
}
uint16_t SpiClass::transfer16(uint16_t data) {
    return 0;
}
void SpiClass::transfer(void *buf, size_t count) {}

void SpiClass::attachInterrupt() {}
void SpiClass::detachInterrupt() {}

SpiClass SPI;
