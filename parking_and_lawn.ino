

#include <Servo.h>
int ledPin = 0;   //D3
const int ldrPin = A0;
int IRpin = 16;  //D0
int hasObstacle = HIGH;
Servo myservo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position
  // attaches the servo on pin D6 to the servo object


void setup() 
{
  
Serial.begin(9600);
pinMode(IRpin, INPUT);
pinMode(ledPin, OUTPUT);
pinMode(ldrPin, INPUT);
myservo.attach(14);

}

void loop() 
{

int ldrStatus = analogRead(ldrPin);
if (ldrStatus >=600) 
{
 
digitalWrite(ledPin, HIGH);
Serial.print("Its DARK, Turn on the LED : ");
Serial.println(ldrStatus);
} 

else 

{
digitalWrite(ledPin, LOW);
Serial.print("Its BRIGHT, Turn off the LED : ");
Serial.println(ldrStatus);
}

hasObstacle = digitalRead(IRpin); //Reads the output of the obstacle sensor from the D0 PIN of the Digital section of the Wemos Board
  if (hasObstacle == LOW) //LOW means something is ahead
  {
    Serial.println("Stop something is ahead!!");
    {
    for (pos =0; pos <= 100; pos += 3) 
     {
      myservo.write(pos); 
      delay(150);                       
     } 
    for (pos = 100; pos >= 0; pos -= 3) 
    {
    myservo.write(pos);
    delay(150);
    }
  }
  }
  else
  {
    Serial.println("Path is clear");

  }

}
