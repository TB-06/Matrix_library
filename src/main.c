#include <msp430.h>
#include "C:\Users\thijn\workspace_ccstheia\Matrix_library\include\gpio_lib.h"

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer

    pinSetDir(&P1IN, BIT0, 1); // P1.0 output
    pinSet(&P1IN, BIT0, 1);    // LED aan

    while (1)
    {
        pinToggle(&P1IN, BIT0);
        __delay_cycles(80000);
    }
}
