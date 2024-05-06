#include <msp430.h>
#include "libTimer.h"
#define BUTTON BIT2 


#define LED_RED BIT0               // P1.0

#define LED_GREEN BIT6             // P1.6

#define LEDS (BIT0 | BIT6)





P2DIR &= ~BUTTON; // Set P2.2 as input

P2REN |= BUTTON;  // Enable pull-up resistor on P2.2

P2OUT |= BUTTON; 
void main(void)

{

  configureClocks();



  P1DIR |= LEDS;                // sets p1dir.0 and p1dir.6 to true(output)

  P1OUT &= ~LEDS;/* leds initially off */



  P1REN |= SWITCHES;/* enables resistors for switches */

  P1IE |= SWITCHES;/* enable interrupts from switches */

  P1OUT |= SWITCHES;/* pull-ups for switches */

  P1DIR &= ~SWITCHES;/* set switches' bits for input */



  or_sr(0x18);  // CPU off, GIE on

}
void

switch_interrupt_handler()

{

  char p1val = P1IN;//0000 1000/* switch is in P1 */



  /* update switch interrupt sense to detect changes from current buttons */

  P1IES |= (p1val & SWITCHES);/* if switch up,check for transition to down */

  P1IES &= (p1val | ~SWITCHES);/* if switch down, sense up */



  /* up=red, down=green */

  if (p1val & SW1) { // p1val and 0000 1000

    P1OUT |= LED_RED;

    P1OUT &= ~LED_GREEN;

  } else {

    P1OUT |= LED_GREEN;

    P1OUT &= ~LED_RED;

  }

}
/* Switch on P1 (S2) */

void

__interrupt_vec(PORT1_VECTOR) Port_1(){

  if (P1IFG & SWITCHES) { /* did a button cause this interrupt? p1ifg is port 1 interrupt */

    P1IFG &= ~SWITCHES;      /* clear pending sw interrupts */

    switch_interrupt_handler();/* single handler for all switches */

  }

}
