#include <msp430.h>
#include "C:\Users\thijn\workspace_ccstheia\Matrix_library\include\gpio_lib.h"

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer


    P1DIR |= BIT0; //set P1.0 as output

    P4DIR |= BIT6; //set P4.6 as output

    P4DIR |= BIT5;    //set direction for switch as input
    P4REN |= BIT5;    //enable resistor
    P4OUT |= BIT5;    //set resistor as pull up

    PM5CTL0 &= ~LOCKLPM5; //unlock pins

    while (1)
    {
    if (!(P4IN & BIT5)) 
    {
        pinSet(PORT1, BIT0, 1);
        pinSet(PORT4, BIT6, 0);
    }
    else{
        pinSet(PORT1, BIT0, 0);
        pinSet(PORT4, BIT6, 1);
        }
    __delay_cycles(1000);
    }
}

