/*
By Michael Nuro Spetås
Michael.Nuro.Spetas@gmail.com

feel free to use and modify
 */

int trigPin = 6;           // HC-SR04 trigger pin
int echoPin = 7;           // HC-SR04 echo pin
int speakerPin = 2;        // Buzzer speaker anode
int rPin = 3;              // red RGB LED
int gPin = 4;              // green RGB LED
int bPin = 5;              // blue RGB LED
int wPin = 8;              // white LED

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(speakerPin, OUTPUT);
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(wPin, OUTPUT);
  digitalWrite(wPin, HIGH);     // showing the device is receiving power
}

void loop() {
  int duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  duration = pulseIn(echoPin, HIGH);
  distance = ( duration / 2) / 29.1;        // Distance formula for HC-SR04
  if (distance > 100)                       // distance is over 1 meter
  {
    Serial.print(distance);
    Serial.println(" cm");
    digitalWrite(gPin, HIGH);
    digitalWrite(rPin, LOW);
    digitalWrite(bPin, LOW);
    delay(50);
  }
  else if (distance <= 100 && distance > 50) // distance is between 1 meter and 50cm
  {
    Serial.print(distance);
    Serial.println(" cm");
    digitalWrite(bPin, HIGH);
    digitalWrite(gPin, LOW);
    digitalWrite(rPin, LOW);
    if (distance <= 70 && distance > 60)
    {
      tone(speakerPin, 4000, 2);
      delay(650);
      digitalWrite(speakerPin, LOW);
    }
    if (distance <= 60 && distance > 50)
    {
      tone(speakerPin, 4000, 6);
      delay(500);
      digitalWrite(speakerPin, LOW);
    }
    delay(25);
  }
  else if (distance <= 50)               // distance is equal to or less than 50cm
  {
    Serial.print(distance);
    Serial.println(" cm");
    digitalWrite(rPin, HIGH);
    digitalWrite(bPin, LOW);
    digitalWrite(gPin, LOW);
    if (distance <= 50 && distance > 40)
    {
      tone(speakerPin, 4000, 10);
      delay(400);
      digitalWrite(speakerPin, LOW);
    }
    if (distance <= 40 && distance > 30)
    {
      tone(speakerPin, 4000, 14);
      delay(200);
      digitalWrite(speakerPin, LOW);
    }
    if (distance <= 30 && distance > 20)
    {
      tone(speakerPin, 4000, 18);
      delay(100);
      digitalWrite(speakerPin, LOW);
    }
    if (distance <= 20 && distance > 15)
    {
      tone(speakerPin, 4000, 22);
      delay(50);
      digitalWrite(speakerPin, LOW);
    }
    if (distance <= 15 && distance > 10)
    {
      tone(speakerPin, 4000, 26);
      delay(25);
      digitalWrite(speakerPin, LOW);
    }
    if (distance <= 10 && distance > -1)
    {
      tone(speakerPin, 4000, 30);
      delay(5);
      digitalWrite(speakerPin, LOW);
    }
  }
  else
  {
    Serial.print("error");
    digitalWrite(rPin, HIGH);
    delay(50);
    digitalWrite(gPin, HIGH);
    digitalWrite(rPin, LOW);
    delay(50);
    digitalWrite(bPin, HIGH);
    digitalWrite(gPin, LOW);
  }
}
