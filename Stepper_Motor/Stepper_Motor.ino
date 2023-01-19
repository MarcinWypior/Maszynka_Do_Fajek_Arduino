#include <Servo.h>

const int dirPin = 2;
const int stepPin = 3;
const int buttonPin = 12;
const int diodePin = 13;
const int stepsPerRevolution = 45;
bool cycleStarted=false;
bool buttonPressed=false;
Servo servo;
 
void setup()
{
  // Declare pins as Outputs
  #include <Servo.h>
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(diodePin, OUTPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(dirPin, HIGH);
  Serial.begin(9600);

  servo.attach(8);
  servo.write(30);
}
void loop()
{
  // Set motor direction counterclockwise
  digitalWrite(dirPin, LOW);

  if(!digitalRead(buttonPin) and buttonPressed==false)
  {
    digitalWrite(diodePin, LOW);
    
    for(int x = 0; x < stepsPerRevolution; x++)
    {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(100);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(100);
      Serial.println("nowy krok");
    }

    servo.write(180);
    delay(2000); 
    servo.write(30);
    
  }//end of production sequence

  //Serial.println("nowa iteracja pętli głównej \n");
  

  if (!digitalRead(buttonPin))
  {
    buttonPressed=true;
    Serial.println("przycisk wciśnięty \n");
  }else
    {
    buttonPressed=false;
    digitalWrite(diodePin, HIGH);
    Serial.println("przycisk gotowy \n");
    }
    
}
