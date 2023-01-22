#include <Servo.h>

const int dirPin = 2;
const int stepPin = 3;
const int smallStepPin = 5;
const int stepFwrPin = 6;
const int stepBwrPin = 7;
const int buttonPin = 12;
const int diodePin = 13;
const int stepsPerRevolution = 25;
bool cycleStarted=false;
bool buttonPressed=false;
Servo servo;
 
void setup()
{
  #include <Servo.h>
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(smallStepPin, OUTPUT);
  pinMode(diodePin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(stepFwrPin, INPUT);
  pinMode(stepBwrPin, INPUT);
  digitalWrite(dirPin, HIGH);
  Serial.begin(9600);

  servo.attach(8);
  servo.write(30);
}
void loop()
{
  // Set motor direction counterclockwise
  digitalWrite(dirPin, LOW);

  if(!digitalRead(buttonPin))
  {
    buttonPressed=true;
    Serial.println("przycisk wciśnięty \n");
  }else
    {
    buttonPressed=false;
    digitalWrite(diodePin, HIGH);  
    cycleStarted = false; 
    }

  if(buttonPressed and (cycleStarted==false))
  {
    cycleStarted = true;
    digitalWrite(diodePin, LOW);
    
    for(int x = 0; x < stepsPerRevolution; x++)
    {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(4700);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(4700);
      Serial.println("nowy krok");
    }

        servo.write(180);
        delay(500); 
        servo.write(30);
        delay(500); 
  }
    
  
  if(digitalRead(stepFwrPin))
    {
     Serial.println("krok do przoddu");
     digitalWrite(smallStepPin,HIGH);
     delay(10);
     digitalWrite(stepPin,HIGH);
     delay(10);
     digitalWrite(stepPin,LOW);
     delay(10);
     digitalWrite(smallStepPin,LOW);
     delay(10);
    }

    if(digitalRead(stepBwrPin))
    {
     Serial.println("krok do tyłu");
     digitalWrite(dirPin, HIGH);
     digitalWrite(smallStepPin,HIGH);
     delay(10);
     digitalWrite(stepPin,HIGH);
     delay(10);
     digitalWrite(stepPin,LOW);
     delay(10);
     digitalWrite(smallStepPin,LOW);
     delay(10);
     digitalWrite(dirPin, LOW);
     delay(10);
    }
    
}
