//led matrix library
#include <msp430.h>
#include <stdint.h>
#include <stdbool.h>

#ifndef INCLUDE_LED_MATRIX_LIB_H_
#define INCLUDE_LED_MATRIX_LIB_H_

#include "C:\Users\thijn\workspace_ccstheia\Matrix_library\include\gpio_lib.h"

#define MATRIX_ROWS 8
#define MATRIX_COLL 8 

typedef struct{
    uint16_t port;
    uint16_t bit;
} IOPin;

typedef struct{
    IOPin rowPins[MATRIX_ROWS];
    IOPin collPins[MATRIX_COLL];
} MatrixConfig;

setLED(int row, int col, int val);

setLedRow(int row, int *val);

setLedCol(int col, int *val);

setMatrix(int val);


#endif /*INCLUDE_LED_MATRIX_LIB_H_*/