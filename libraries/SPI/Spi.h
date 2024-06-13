/**
 * SPI library.
 *
 * Only Controller mode is supported with this SPI class.
 *
 * The SPISettings class is defined in the api/HardwareSPI.h file, and contains
 * the configuration for the SPI bus as used by SpiClass::beginTransaction():
 *  - SPI bus clock speed in Hz
 *  - Data order, with Most Significant Bit First (MSBFIRST) or
 *    Least Signficiant Bit First (LSBFIRST)
 *  - The SPI mode 0 to 3, as defined in the SPI standard, a combination of
 *    clock polarity, clock phase, and clock edge configurations.
 */
#pragma once

#include "api/HardwareSPI.h"

// Indicates SPI.notUsingInterrupt() is available
#define SPI_HAS_NOTUSINGINTERRUPT 1

namespace arduino {

class SpiClass : public HardwareSPI {
  public:
    /**
     * Constructor for this SPI class.
     *
     * Don't initialise the SPI hardware or pins here, that should be done in
     * begin(). The constructor can be used to prepare the instance before
     * it is used, like storing the pins, peripheral selections, etc.
     *
     * The Chip select pins are not controlled by this class and the user is
     * expected to manage those.
     *
     * The main "SPI" instance accessed by the users is declared in this
     * header file and instantiated in Spi.cpp. So, the user is not expected
     * to use the class constructor directly and its signature is not
     * standarised. So you can adapt it to requirements of your Arduino core.
     */
    SpiClass();

    /**
     * Initialise the SPI peripheral and pins.
     */
    void begin();

    /**
     * Disable the SPI peripheral and disconnect the pins, undoing all the
     * effects of begin().
     */
    void end();

    /**
     * Register an Interrupt Number where SPI transaction are used, so that
     * beginTransaction() can disable those interrupts and/or other resources
     * to prevent clashes using the SPI bus.
     */
    void usingInterrupt(int interruptNumber);

    /**
     * Remove from the register interrupts if they are no longer using SPI.
     */
    void notUsingInterrupt(int interruptNumber);

    /**
     * Prepare the SPI peripheral and bus for a transaction with the provided
     * settings.
     *
     * To be followed by calls to the transfer methods and finished by a call
     * to endTransaction().
     *
     * If interrupts using SPI have been register with the usingInterrupt()
     * this methods will have to deal with configuring those interrupts to
     * avoid usage conflicts, as required by your Arduino Core.
     *
     * As this class does not control the Chip Select pin the user needs to
     * assert the pin after calling this function.
     *
     * @param settings An SPISettings instance configuring the bus clock, bit
     *                 order, and SPI mode.
     */
    void beginTransaction(SPISettings settings);

    /**
     * Ends usage of the SPI bus.
     *
     * Any resource or interrupt configuration done by beginTransaction()
     * should be freed up here.
     *
     * As this class does not control the Chip Select pin the user needs to
     * release the pin before calling this function.
     */
    void endTransaction(void);

    /**
     * Send data to the SPI peripheral and read data back.
     *
     * @param data A single byte to send.
     *
     * @return A byte read back.
     */
    uint8_t transfer(uint8_t data);

    /**
     * Send data to the SPI peripheral and read data back.
     *
     * The byte order will depend on the default SPISettings or the
     * configuration set with beginTransaction(SPISettings).
     *
     * @param data Two bytes to send.
     *
     * @return Two bytes read back.
     */
    uint16_t transfer16(uint16_t data);

    /**
     * Send data to the SPI peripheral and read data back.
     *
     * The byte order will depend on the default SPISettings or the
     * configuration set with beginTransaction(SPISettings).
     *
     * @param buf A byte array to send via SPI.
     * @param count The size of the array in bytes.
     */
    void transfer(void *buf, size_t count);

    /**
     * These methods are undocumented and should not be used any more by users,
     * but need to be declared and defined as HardwareSPI has configure them
     * as pure virtual.
     */
    void attachInterrupt();
    void detachInterrupt();

    /**
     * These methods are deprecated and should not be used in new Arduino
     * Skectches, instead an instance of SPISettings should be used with the
     * beginTransaction() method.
     * However, they have been included here commented out, in case you might
     * choose to implement them for compatibility reasons.
     */
    // void setClockDivider(uint8_t divider);
    // void setBitOrder(BitOrder order);
    // void setDataMode(SPIMode mode);
};

}  // namespace arduino

extern arduino::SpiClass SPI;
