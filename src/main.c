#include <msp430.h>
#include "C:\Users\thijn\workspace_ccstheia\Matrix_library\include\gpio_lib.h"

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer

    unlock_GPIO();

    pinSetDir(PORT1, BIT3, 1); //set P1.3 as output

    pinSetDir(PORT2, BIT6, 1); //set P2.6 as output

    pinSet(PORT1, BIT3, 1); //make P1.3 HIGH

    pinSet(PORT2, BIT6, 0); //make P2.6 LOW
    while(1){
        pinToggle(PORT1, BIT3); //toggle P1.3

        _delay_cycles(1000000);
    }
}

