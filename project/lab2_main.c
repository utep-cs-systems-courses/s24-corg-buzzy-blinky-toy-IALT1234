#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"

#define A 2272
#define E 3024
#define E4 1516
#define D 1702
#define G 2551
#define B 2028
#define F 2863
#define C3 3816
#define PAUSE 0

#define BUTTON1 BIT0
#define BUTTON2 BIT2
#define BUTTON3 BIT3

void greenControl();

void button_init() {

  P2DIR &= ~(BUTTON1 | BUTTON2 | BUTTON3);

  P2REN |= (BUTTON1 | BUTTON2 | BUTTON3); 

  P2OUT |= (BUTTON1 | BUTTON2 | BUTTON3); 
}
int button_down() {

  return !(P2IN & BUTTON1); // Return true if button is pressed (P1.0 is low)

}
int button2_down() {

  return !(P2IN & BUTTON2); // Return true if button 2 (P1.2) is pressed

}
int button3_down() {

  return !(P2IN & BUTTON3); // Return true if button 2 (P1.3) is pressed

}

int main(){

  configureClocks();
  buzzer_init();
  button_init();

  
  while(1) {

    if (button_down()) {
      
      
      buzzer_set_period(B); __delay_cycles(2000000);//IN
      buzzer_set_period(PAUSE); __delay_cycles(4000000);
  
      buzzer_set_period(C3); __delay_cycles(2000000);//THE
      buzzer_set_period(PAUSE); __delay_cycles(1000000);
  
      buzzer_set_period(D); __delay_cycles(10000000);//TOWN
      buzzer_set_period(PAUSE); __delay_cycles(4000000);
  
      buzzer_set_period(B); __delay_cycles(2000000);//WHERE
      buzzer_set_period(PAUSE); __delay_cycles(1000000);
  
      buzzer_set_period(A); __delay_cycles(2000000);//CARED
      buzzer_set_period(PAUSE); __delay_cycles(4000000);

      buzzer_set_period(B); __delay_cycles(2000000);//WAS
      buzzer_set_period(PAUSE); __delay_cycles(1000000);
  
      buzzer_set_period(G); __delay_cycles(10000000);//BORN
      buzzer_set_period(PAUSE); __delay_cycles(8000000);
  
      buzzer_set_period(B); __delay_cycles(2000000);//NO
      buzzer_set_period(PAUSE); __delay_cycles(4000000);
  
      buzzer_set_period(B); __delay_cycles(2000000);//ONE
      buzzer_set_period(PAUSE); __delay_cycles(1000000);
  
      buzzer_set_period(A); __delay_cycles(2000000);//CARED
      buzzer_set_period(PAUSE); __delay_cycles(4000000);
  
      buzzer_set_period(G); __delay_cycles(2000000);//
      buzzer_set_period(PAUSE); __delay_cycles(1000000);
  
      buzzer_set_period(E); __delay_cycles(10000000);//
      buzzer_set_period(PAUSE); __delay_cycles(2000000);
  
      buzzer_set_period(E); __delay_cycles(2000000);//NO
      buzzer_set_period(PAUSE); __delay_cycles(1000000);
  
      buzzer_set_period(B); __delay_cycles(2000000);//ONE
      buzzer_set_period(PAUSE); __delay_cycles(4000000);
  
      buzzer_set_period(B); __delay_cycles(2000000);//CARED
      buzzer_set_period(PAUSE); __delay_cycles(1000000);
  
      buzzer_set_period(A); __delay_cycles(8000000);//
      buzzer_set_period(PAUSE); __delay_cycles(1000000);
    }
    else if(button2_down()) {
      buzzer_set_period(D); __delay_cycles(2000000);//WE
      buzzer_set_period(PAUSE); __delay_cycles(8000000);
     
      buzzer_set_period(D); __delay_cycles(2000000);//ALL
      buzzer_set_period(PAUSE); __delay_cycles(8000000);
      
      buzzer_set_period(D); __delay_cycles(2000000);//LIVE
      buzzer_set_period(PAUSE); __delay_cycles(8000000);

      buzzer_set_period(D); __delay_cycles(2000000);//IN
      buzzer_set_period(PAUSE); __delay_cycles(4000000);

      buzzer_set_period(E4); __delay_cycles(2000000);//A
      buzzer_set_period(PAUSE); __delay_cycles(2000000);

      buzzer_set_period(A); __delay_cycles(2000000);//YE
      buzzer_set_period(PAUSE); __delay_cycles(4000000);

      buzzer_set_period(A); __delay_cycles(2000000);//LLOW
      buzzer_set_period(PAUSE); __delay_cycles(2000000);

      buzzer_set_period(A); __delay_cycles(2000000);//SUB
      buzzer_set_period(PAUSE); __delay_cycles(4000000);

      buzzer_set_period(A); __delay_cycles(2000000);//MA
      buzzer_set_period(PAUSE); __delay_cycles(2000000);

      buzzer_set_period(A); __delay_cycles(2000000);//RIN
      buzzer_set_period(PAUSE); __delay_cycles(15000000);

      buzzer_set_period(A); __delay_cycles(2000000);//YE
      buzzer_set_period(PAUSE); __delay_cycles(4000000);

      buzzer_set_period(A); __delay_cycles(2000000);//LLOW
      buzzer_set_period(PAUSE); __delay_cycles(2000000);

      buzzer_set_period(A); __delay_cycles(2000000);//SUB
      buzzer_set_period(PAUSE); __delay_cycles(4000000);

      buzzer_set_period(A); __delay_cycles(2000000);//MA
      buzzer_set_period(PAUSE); __delay_cycles(2000000);

      buzzer_set_period(A); __delay_cycles(2000000);//RIN
      buzzer_set_period(PAUSE); __delay_cycles(15000000);

      buzzer_set_period(G); __delay_cycles(2000000);//YE
      buzzer_set_period(PAUSE); __delay_cycles(4000000);

      buzzer_set_period(G); __delay_cycles(2000000);//LLOW
      buzzer_set_period(PAUSE); __delay_cycles(2000000);

      buzzer_set_period(G); __delay_cycles(2000000);//SUB
      buzzer_set_period(PAUSE); __delay_cycles(4000000);

      buzzer_set_period(G); __delay_cycles(2000000);//MA
      buzzer_set_period(PAUSE); __delay_cycles(2000000);

      buzzer_set_period(G); __delay_cycles(2000000);//RIN
      buzzer_set_period(PAUSE); __delay_cycles(10000000);

      }else if(button3_down()){
         greenControl(1);

    }



    else {

    // Stop playing the song if no button is pressed

    buzzer_set_period(0);
    }
  }
}
