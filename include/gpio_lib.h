//gpio_lib.h
#include <msp430.h>
#include <stdint.h>
#include <stdbool.h>

#ifndef INCLUDE_GPIO_LIB_H_
#define INCLUDE_GPIO_LIB_H_

typedef enum {
    GPIO_FUNCTION,
    ALT_FUNCTION_1,
    ALT_FUNCTION_2,
    ALT_FUNCTION_3
} purposeFunction;


void pinSet(uint16_t port, uint16_t bit, bool val);

void pinToggle(uint16_t port, uint16_t bit);

bool pinGet(uint16_t port, uint16_t bit);

void pinConfigInput(uint16_t port, uint16_t bit, bool pullResistor, bool pullUP, bool IES, bool IE);

pinSetDir(uint16_t port, uint16_t bit, uint16_t val);

pinConfigFunction(uint16_t port, uint16_t bit, purposeFunction pf);

#endif 