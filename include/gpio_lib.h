//gpio_lib.h
#include <msp430.h>
#include <stdint.h>
#include <stdbool.h>

#ifndef INCLUDE_GPIO_LIB_H_
#define INCLUDE_GPIO_LIB_H_

#define PORT1 0x0000
#define PORT2 0x0001
#define PORT3 0x0020
#define PORT4 0x0021

typedef enum {
    digital, 
    primary, 
    secondary, 
    tertiary
} purposeFunction;

void pinSet(uint16_t port, uint16_t bit, bool val);

void pinToggle(uint16_t port, uint16_t bit);

bool pinGet(uint16_t port, uint16_t bit);

void pinConfigInput(uint16_t port, uint16_t bit, bool pullResistor, bool pullUp, bool IES, bool IE);

void pinSetDir(uint16_t port, uint16_t bit, bool val);

void pinConfigFunction(uint16_t port, uint16_t bit, purposeFunction pf);

void GPIO_init();

#endif /* INCLUDE_GPIO_LIB_H_ */