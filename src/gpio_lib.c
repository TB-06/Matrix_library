//gpio_lib.c
#include <msp430.h>
#include "C:\Users\thijn\workspace_ccstheia\Matrix_library\include\gpio_lib.h"

void pinSet(uint16_t port, uint16_t bit, bool val)
{
    volatile uint8_t *out = (volatile uint8_t *)port;

    if (val)
        *out |= bit;    //set bit hoog
    else
        *out &= ~bit;   //set bit laag
}

void pinToggle(uint16_t port, uint16_t bit)
{
    volatile uint8_t *out = (volatile uint8_t *)port;
    *out ^= bit;    //XOR toggled spec bit
}

bool pinGet(uint16_t port, uint16_t bit)
{
    volatile uint8_t *in = (volatile uint8_t *)port;
    return ((*in & bit) != 0);
}

void pinConfigInput(uint16_t port, uint16_t bit, bool pullResistor, bool pullUP, bool IES, bool IE)
{
    //set direction to input
    volatile uint8_t *dir = (volatile uint8_t *)(port + 0x04);
    *dir &= ~bit; //input

    //pul up / down
    volatile uint8_t *ren = (volatile uint8_t *)(port + 0x06); //PxREN offset = +6
    volatile uint8_t *out = (volatile uint8_t *)(port + 0x02); //PxREN offset = +2

    if (pullResistor)
    {
        *ren |= bit;
        if (pullUP)
            *out |= bit;
        else
            *out &= ~bit;
    }
    else
    {
        *ren &= ~bit;
    }

    //interrupt edge select
    volatile uint8_t *ies = (volatile uint8_t *)(port + 0x14); //PxIES offset = +14
    if (IES)
        *ies |= bit;
    else
        *ies &= ~bit;

    //interrupt enable
    volatile uint8_t *ie = (volatile uint8_t *)(port + 0x16); //PxIE offset = +16
    if (IE)
        *ie |= bit;
    else
        *ie &= ~bit;
}