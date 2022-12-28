#pragma once

// Common API from Arduino
#include "api/ArduinoAPI.h"
// This core drivers
#include "Uart.h"

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

// Sketch functions
void setup(void);
void loop(void);

#ifdef __cplusplus
}  // extern "C"
#endif
