//led matrix library
#include <msp430.h>
#include "C:\Users\thijn\workspace_ccstheia\Matrix_library\include\led_matrix_lib.h"

static MatrixConfig LEDMatrixConfig;
static uint8_t matrixState[MATRIX_ROWS][MATRIX_COLS];

void configLEDMatrix(IOPin *iolist){

    for (int r = 0; r < MATRIX_ROWS; r++){ // Set Matrix Rows
        LEDMatrixConfig.rowPins[r] = iolist[r];
        pinConfigFunction(iolist[r].port, iolist[r].bit, digital);
        pinSetDir(iolist[r].port, iolist[r].bit, true);
    }

    for (int c = 0; c < MATRIX_COLS; c++){ // Set Matrix Collums
        LEDMatrixConfig.colPins[c] = iolist[MATRIX_ROWS + c];
        pinConfigFunction(iolist[MATRIX_ROWS + c].port, iolist[MATRIX_ROWS + c].bit, digital);
        pinSetDir(iolist[MATRIX_ROWS + c].port, iolist[MATRIX_ROWS + c].bit, true);
    }
    
    for (int r = 0; r < MATRIX_ROWS; r++){
        for (int c = 0; c < MATRIX_COLS; c++){
            matrixState[r][c] = 0;
        }
    }

    setMatrix(0);   // Empty Matrix
}

void setLed(int row, int col, bool val){
    if (row < 0 || row >= MATRIX_ROWS) return;  // Check if row is compatible value
    if (col < 0 || col >= MATRIX_COLS) return;  // Check if col is compatible value
    matrixState[row][col] = val;
}

void setMatrix(bool val){
    for (int r = 0; r < MATRIX_ROWS; r++){
        for (int c = 0; c < MATRIX_COLS; c++){
            matrixState[r][c] = val;
        }
    }
}

void setLedRow(int row, bool *val){
    if (row < 0 || row >= MATRIX_ROWS) return;  // Check if row is compatible value
    for (int c = 0; c < MATRIX_COLS; c++){
        matrixState[row][c] = val[c];
    }
}

void setLedCol(int col, bool *val){
    if (col < 0 || col >= MATRIX_COLS) return;  // Check if col is compatible value
    for (int r = 0; r < MATRIX_ROWS; r++){
        matrixState[r][col] = val[r];
    }
}

void refreshMatrix(void){
    for (int r = 0; r < MATRIX_ROWS; r++){

        pinSet(LEDMatrixConfig.rowPins[r].port, LEDMatrixConfig.rowPins[r].bit, true);

        for (int c = 0; c < MATRIX_COLS; c++){
            pinSet(LEDMatrixConfig.colPins[c].port, LEDMatrixConfig.colPins[c].bit, (matrixState[r][c] ? false : true));
        }

        __delay_cycles(100);

        for (int c = 0; c < MATRIX_COLS; c++){
            pinSet(LEDMatrixConfig.colPins[c].port, LEDMatrixConfig.colPins[c].bit, true);
        }

        pinSet(LEDMatrixConfig.rowPins[r].port, LEDMatrixConfig.rowPins[r].bit, false);
    }
}