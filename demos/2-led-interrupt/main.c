//Alternate LEDs from Off, Green, and Red
#include <msp430.h>

#include "libTimer.h"

#include "led.h"



int main(void) {

  // Set up Port 1 to control the LEDs

  P1DIR |= LEDS;



  // Initialize clocks and enable periodic interrupts

  configureClocks();

  enableWDTInterrupts();



  // Turn off the red LED initially

  P1OUT &= ~LED_RED;



  // Enter low-power mode with interrupts enabled

  or_sr(0x18); // CPU off, GIE on

}



// Interrupt Service Routine for Watchdog Timer

void __interrupt_vec(WDT_VECTOR) WDT() {

  // Toggle the state of the red LED

  P1OUT ^= LED_RED;

}
