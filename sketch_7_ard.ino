//***************************************************************************************
//  EE40LX
//  Sketch 7.1
//
//  Description; Final code that runs the robot
//
//  Tom Zajdel
//  University of California, Berkeley
//  February 23, 2014
//***************************************************************************************
// modified for arduino
//***************************************************************************************

int PBLOCK = 1;  // set PBLOCK as P1.1 alias

int RPHOTO = 2;  // set RPHOTO as P1.2 alias
int LPHOTO = 3;  // set LPHOTO as P1.3 alias

int BUZZER = 7;  // set BUZZER as P1.7 alias
int MICINP = 8;    // set MICINP as A8   alias

int RMOTOR = 9;  // set RMOTOR as P1.9 alias
int LMOTOR = 10;  // set LMOTOR as P1.10 alias

int MPOW   = 205;   // set motors to use 50% PWM (possible values 0-255)
int MICTHRESH = 700; // set microphone trigger threshold (possible values 0-1023)

int FIVE = 12;
int i;
int val;
int maxval;

void setup()
{  
  
  // set outputs
  pinMode(LMOTOR, OUTPUT);
  pinMode(RMOTOR, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(PBLOCK, OUTPUT);
  pinMode(FIVE, OUTPUT);
  // set inputs
  pinMode(LPHOTO, INPUT);
  pinMode(RPHOTO, INPUT);
  
}

void loop()
{
  analogWrite(LMOTOR,0);        // turn off both motors 
  analogWrite(RMOTOR,0);
  digitalWrite(FIVE, HIGH);
  // Step 1: beep a bunch of times!
  for (i=1; i<5; i++)
  {
    beep(BUZZER, 1000, 100*i);
    delay(100*i);
  }

  // Step 2: listen to the microphone for ~100 ms
  maxval = 0;
  for (i=1; i<100; i++)
  {
    val = analogRead(MICINP);
    if (val > maxval)
      maxval = val;
    delay(1);
  }

  // If the largest voltage detected is above 1.94 V (3.3*600/1023),
  // commence the "beep dance" response
  if (maxval > MICTHRESH)
  {
    // Make the "siren" noise by alternating 1200 Hz and 800 Hz tones
    for (i=0; i<5; i++)
    {
        beep(BUZZER, 1200, 100);
        beep(BUZZER, 800,  100);
    }
    // Shake motors back and forth rapidly
    for (i=0; i<3; i++)
    {
        analogWrite(RMOTOR, MPOW);
        delay(500); //500 instead of 200
        analogWrite(RMOTOR, 0);
        analogWrite(LMOTOR, MPOW);
        delay(500); //500 instead of 200
        analogWrite(LMOTOR, 0);
    }
    // Make a series of tones with increasing frequency from 300-100 Hz
    // then come back down
    for (i=30; i<100; i+=1)
      beep(BUZZER, 10*i, 10);
    for (i=100; i>30; i-=1)
      beep(BUZZER, 10*i, 10);
  } 
  // Step 3: read the status of photocells and adjust motor output
  digitalWrite(PBLOCK, HIGH);      // supply 5V to the power rail
  delayMicroseconds(2000);           // delay briefly to allow comparator outputs to settle 
  // 20 us became 2000
  
  if (digitalRead(LPHOTO))         // check each photocell/circuit output and determine
    analogWrite(LMOTOR, MPOW);     // whether to run on the left motor...
  if (digitalRead(RPHOTO))         // ...or right motor
    analogWrite(RMOTOR, MPOW);     
  digitalWrite(PBLOCK, LOW);       // turn the power-blocked rail off
    
  delay(1000);                      // wait 500 ms became 1000 ms
  
 }
 
void beep(int pin, int freq, long ms)  	//generate a square wave at a given frequency for ms miliseconds
{
	int k;
        long semiper = (long) (1000000/(freq*2));
        long loops = (long)((ms*1000)/(semiper*2));
	for (k=0;k<loops;k++)
	{
            digitalWrite(pin, HIGH);  //set buzzer pin high
	    delayMicroseconds(semiper);  //for half of the period
	    digitalWrite(pin, LOW);   //set buzzer pin low
            delayMicroseconds(semiper);  //for the other half of the period
	}
}
