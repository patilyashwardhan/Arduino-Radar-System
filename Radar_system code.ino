
#include<Servo.h>
int trig = 3 ;
int echo = 4 ;
int buzz = 5 ;
float Dist , Duration ;
Servo myservo ;

void setup() 
{
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
  pinMode(buzz , OUTPUT);
  myservo.attach(6);
  Serial.begin(9600);
  
}

void loop()
{
  for(int i=0 ; i<=180 ; i++)
  {
    myservo.write(i);
    delay(15);

    digitalWrite(trig , LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);

    Duration = pulseIn(echo , HIGH);
    Dist = 0.0343*Duration/2 ;

    Serial.print("Angle: ");
    Serial.println(i);
    Serial.print("Distance: ");
    Serial.println(Dist);
    
    if(Dist > 0 && Dist < 50)
    {
      digitalWrite(buzz,HIGH);
    }
    else
    {
       digitalWrite(buzz,LOW);
    }
  }
    

  for(int i=180 ; i>=0 ; i--)
  {
    myservo.write(i);
    delay(15);

    digitalWrite(trig , LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);

    Duration = pulseIn(echo , HIGH);
    Dist = 0.0343*Duration/2 ;

     Serial.print("Angle: ");
    Serial.println(i);
    Serial.print("Distance: ");
    Serial.println(Dist);
    
    if(Dist > 0 && Dist <50)
    {
      digitalWrite(buzz,HIGH);
    }
    else
    {
       digitalWrite(buzz,LOW);
    }
  }

}
