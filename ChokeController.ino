// Control the choke position of a carburated vehicle
// with a potentiometer and temp sensing with a TMP36
//
// TMP36 Digital Value 140 ~ 65F

#include <Servo.h> 

int chokeTempSensePin = 1; // choke temperature sensor pin
int chokeTemp = 0;
 
Servo chokeServo;  // create servo object to control the choke servo 
int chokeKnobPin = 0;  // analog pin used to connect the potentiometer
int chokeKnobValue;    // variable to read the value from the analog pin 
 
void setup() 
{ 
  // Setup Choke Servo on pin 9. 
  chokeServo.attach(9);
  // Setup serial so we can monitor knob position and temp reading.
  Serial.begin(9600); 
} 
 
void loop() 
{ 
  // Report the temp reading. We'll eventualy use this to help auto 
  // control the choke position.
  chokeTemp = analogRead(chokeTempSensePin);
  Serial.print("Temp: ");
  Serial.print(chokeTemp, DEC);
  
  // Set the choke position based on the knob.
  chokeKnobValue = analogRead(chokeKnobPin);            // reads the value of the potentiometer (value between 0 and 1023) 
  chokeKnobValue = map(chokeKnobValue, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
  chokeServo.write(chokeKnobValue);                  // sets the servo position according to the scaled value 
  Serial.print(" Knob: ");
  Serial.print(chokeKnobValue, DEC);
  Serial.print("\n");
  
  delay(50);  // Wait a little bit, we don't need to run too fast.
} 
