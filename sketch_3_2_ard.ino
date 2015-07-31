//***************************************************************************************
//  EE40LX
//  Sketch 3.2
//
//  Description; Power-block a 5V rail at P1 and subsequently read inputs from
//     Wheatstone bridges, connected to P2 and P3
//
//  Tom Zajdel
//  University of California, Berkeley
//  December 16, 2014
//
//  Modified for Arduino Leonardo
//***************************************************************************************

int PBRAIL = 1;   // set PBRAIL as Pin 1 alias
int LPHOTO = 2;   // set LPHOTO as Pin 2 alias
int RPHOTO = 3;   // set RPHOTO as Pin 3 alias

int REDLED = 5;   // set REDLED as Pin 5 alias
int GRNLED = 6;   // set GRNLED as Pin 6 alias

void setup()
{ 
  Serial.begin(9600);
  
  // set power block pin and led pins as outputs
  pinMode(PBRAIL, OUTPUT);
  pinMode(REDLED, OUTPUT);
  pinMode(GRNLED, OUTPUT);
  
  // set photocell input pins
  pinMode(LPHOTO, INPUT);
  pinMode(RPHOTO, INPUT);

  Serial.println("Setup complete!");
}

void loop()
{
  digitalWrite(PBRAIL, HIGH);        // supply 3.3V to the power rail
  delay(20);                         // delay briefly to allow comparator outputs to settle

  if (digitalRead(LPHOTO) == HIGH)  // if LPHOTO is on, turn REDLED on
     digitalWrite(REDLED, HIGH);     // otherwise, turn REDLED off
  else
     digitalWrite(REDLED, LOW);  
     
  if (digitalRead(RPHOTO) == HIGH)  // if RPHOTO is on, turn GRNLED on
     digitalWrite(GRNLED, HIGH);     // otherwise, turn GRNLED off
  else
     digitalWrite(GRNLED, LOW);  
  
  digitalWrite(PBRAIL, LOW);          // turn the power rail off again
  delay(500);                          // wait 19 ms (can do other tasks in this time,
                                      // but we are simply demonstrating that you can cut power
                                      // to the circuits for 95% of the time and not notice!

}
