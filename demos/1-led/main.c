#include <msp430.h>

#include "led.h"  // Include the LED definitions



int main() {

  WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer

  P1DIR |= LEDS; // Set LED pins as output



  while (1) {

    P1OUT |= LED_RED; // Turn on green LED

    __delay_cycles(500000); // Delay for approximately 1 second

    P1OUT &= ~LED_RED; // Turn off green LED

    __delay_cycles(500000); // Delay for approximately 1 second

  }

}
