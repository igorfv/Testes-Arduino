/*
 * HCSR04Ultrasonic/examples/UltrasonicDemo/UltrasonicDemo.pde
 *
 * SVN Keywords
 * ----------------------------------
 * $Author: cnobile $
 * $Date: 2011-09-17 02:43:12 -0400 (Sat, 17 Sep 2011) $
 * $Revision: 29 $
 * ----------------------------------
 */

#include <Ultrasonic.h>

#define TRIGGER_PIN 12
#define ECHO_PIN    13
#define BUZZ        11
#define DIST        100

int interval = 1000;

Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

void setup()
  {
    pinMode(BUZZ, OUTPUT);
    Serial.begin(9600);
  }

void loop()
  {
    long microsec = ultrasonic.timing();
    float cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
    
    if(cmMsec < DIST)
    {
      int dely = interval/(DIST/cmMsec);
      
      digitalWrite(BUZZ, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(100);                 // wait for a second
      digitalWrite(BUZZ, LOW);    // turn the LED off by making the voltage LOW
      delay(dely);
    }
  }

