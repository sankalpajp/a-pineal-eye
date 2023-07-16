int GNDPin=5;
#define echoPin 15
#define trigPin 14
#define buzzer 3
#define led2 6
#define led3 7
#define led4 8
#define led5 9
float time:
float distance_cm;
float distance_in;
void setup()
{ Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(buzzer, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(led4, OUTPUT);
pinMode(led5, OUTPUT);
pinMode(GNDPin, OUTPUT);
digitalWrite(GNDPin, LOW);
}
void loop()
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
time = pulseln(echoPin, HIGH);
distance_cm = (time/2)/29.1;
distance_in = (time/2)/ 73.914;
Serial.print("cm= ");
Serial.print(distance_cm);
Serial.print(" inch= ");
Serial.println(distance_in);
delay(200);
if(distance_in<20)
 {
digitalWrite(led2, HIGH);
tone(buzzer, 1000,500);
}
else
{ digitalWrite(led2, LOW);
digitalWrite(buzzer, LOW);
}
if(distance_in<15)
{ digitalWrite(led3, HIGH);
tone(buzzer, 800,400);
}
else
{ digitalWrite(led3, LOW);
digitalWrite(buzzer, LOW);}
if(distance_in<10)
{ digitalWrite(led4, HIGH);
tone(buzzer, 700,300);
}
else
 {
digitalWrite(led4, LOW);
digitalWrite(buzzer, LOW);
}
if(distance_in<5)
{tone(buzzer, 200, 100);
digitalWrite(led5, HIGH);
}
else
{ digitalWrite(led5, LOW);
digitalWrite(buzzer, LOW);
}