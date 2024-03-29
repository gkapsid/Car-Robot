//***************************************************************************************
//  EE40LX
//  Sketch 3.6
//
//  Description; the MSP430 reads the output of the microphone circuit at P1.5 and
//	decides whether or not to flash on an LED based on the sound level
//
//  Tom Zajdel
//  University of California, Berkeley
//  December 17, 2014
//  Code for ARDUINO
//***************************************************************************************

int MICINP = 8;   // set MICINP as P8 alias
int GRNLED = 11; // set GRNLED as P11 alias
int value = 0;     // variable that stores the value read in

void setup()
{
  // start the serial monitor
  Serial.begin(9600);
  
  // set GRNLED as output pin
  pinMode(GRNLED, OUTPUT);
  
  Serial.println("Setup complete!");
}

void loop()
{
  value = analogRead(MICINP);  // get the voltage from the microphone
  Serial.println(value);       // write digitized value to serial monitor

  if (value >= 700)            // if digitized value is above 560,
    digitalWrite(GRNLED, HIGH);// turn on the LED...
  else
    digitalWrite(GRNLED, LOW); // ...else turn off the LED
    
  delay(1);                    // delay in between reads for stability
    
}
