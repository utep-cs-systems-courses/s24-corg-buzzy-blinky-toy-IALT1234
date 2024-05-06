#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"


#define A3  2272
#define E4  1516
#define D4  1702
#define G3  2551
#define B3  2028
#define E3  3034
#define F3S 2863
#define C3  3816
#define PAUSE 0

int main() {
  
    configureClocks();
    buzzer_init();
    // Play "Yellow Submarine"

    buzzer_set_period(B3); __delay_cycles(2000000); // IN
    buzzer_set_period(PAUSE); __delay_cycles(4000000);
    buzzer_set_period(C3); __delay_cycles(2000000); // THE
    buzzer_set_period(PAUSE); __delay_cycles(1000000);
    buzzer_set_period(D4); __delay_cycles(10000000); // TOWN
    buzzer_set_period(PAUSE); __delay_cycles(4000000);
    buzzer_set_period(B3); __delay_cycles(2000000); // WHERE
    buzzer_set_period(PAUSE); __delay_cycles(1000000);
    buzzer_set_period(A3); __delay_cycles(2000000); // I
    buzzer_set_period(PAUSE); __delay_cycles(4000000);
    buzzer_set_period(B3); __delay_cycles(2000000); // WAS
    buzzer_set_period(PAUSE); __delay_cycles(1000000);
    buzzer_set_period(G3); __delay_cycles(10000000); // BORN
    buzzer_set_period(PAUSE); __delay_cycles(8000000);
    buzzer_set_period(B3); __delay_cycles(2000000); // NO
    buzzer_set_period(PAUSE); __delay_cycles(4000000);
    buzzer_set_period(B3); __delay_cycles(2000000); // ONE
    buzzer_set_period(PAUSE); __delay_cycles(1000000);
    buzzer_set_period(A3); __delay_cycles(2000000); // CARED
    buzzer_set_period(PAUSE); __delay_cycles(4000000);
    buzzer_set_period(G3); __delay_cycles(2000000); //  
    buzzer_set_period(PAUSE); __delay_cycles(1000000);
    buzzer_set_period(E3); __delay_cycles(10000000); // 
    buzzer_set_period(PAUSE); __delay_cycles(2000000);
    buzzer_set_period(E3); __delay_cycles(2000000); // NO
    buzzer_set_period(PAUSE); __delay_cycles(1000000);
    buzzer_set_period(B3); __delay_cycles(2000000); // ONE
    buzzer_set_period(PAUSE); __delay_cycles(4000000);
    buzzer_set_period(B3); __delay_cycles(2000000); // CARED
    buzzer_set_period(PAUSE); __delay_cycles(1000000);
    buzzer_set_period(A3); __delay_cycles(8000000); // 
    buzzer_set_period(PAUSE); __delay_cycles(1000000); // 
    or_sr(0x18);                // CPU off, GIE on
}
