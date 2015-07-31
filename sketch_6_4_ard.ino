//***************************************************************************************
//  EE40LX
//  Sketch 6.4
//
//  Description;  Switch P1.0 and P1.6 of MSP430 between 3.3V and 0V to create
//                a PWM signal for motor control
//
//  Tom Zajdel
//  University of California, Berkeley
//  February 16, 2014
//***************************************************************************************
//  Code modified for Arduino Leonardo by gkapsid L205, R127
//***************************************************************************************

int LMOTOR = 10;     // set LMOTOR as P10 alias
int RMOTOR = 9;     // set RMOTOR as P9 alias

void setup()
{ 
  pinMode(LMOTOR, OUTPUT);   // set P10 as output (LMOTOR)
  pinMode(RMOTOR, OUTPUT);   // set P11 as output (RMOTOR)
}

void loop()
{            
   analogWrite(RMOTOR,205);  // PWM both motors at 50% 255 is 100% duty cycle
   analogWrite(LMOTOR,128);
   delay(1000);              // let motors run one second
   analogWrite(RMOTOR,0);    // turn both motors off
   analogWrite(LMOTOR,0);
   delay(1000);              // let motors rest one second
}

