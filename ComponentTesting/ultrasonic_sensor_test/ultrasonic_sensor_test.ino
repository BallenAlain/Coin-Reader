#define trigPin 9
#define echoPin 10

#define redLED 6
#define greenLED 7
#define yellowLED 5
 
#define buttonPin 47

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3f, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

long duration;
int distance;
int button;
int sum = 0;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.begin(16,2);
  lcd.backlight();
  pinMode(greenLED,OUTPUT);
  pinMode(redLED,OUTPUT);
  pinMode(yellowLED,OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  duration = pulseIn(echoPin, HIGH);
  distance =( (duration*0.034)/2 );  

  button = digitalRead(buttonPin);
  delay(100);
  Serial.print("Distance: ");
  Serial.println(distance);

//  if(distance < 10){
//  lcd.setCursor(3,1);
//  lcd.print(distance);
//  delay(500);
//  lcd.clear();
//  digitalWrite(greenLED, HIGH);
//  digitalWrite(redLED,LOW);
//  } else {
//    digitalWrite(redLED,HIGH);
//    digitalWrite(greenLED, LOW);
//  }
  if(button == LOW){
    sum = 0;
  }
  lcd.setCursor(1,0);
  lcd.print(sum);
  if(distance >= 3 && distance < 8){
    digitalWrite(yellowLED, HIGH);
    delay(2000);
    if(distance > 5 && distance < 7){
        digitalWrite(greenLED, HIGH);
        digitalWrite(yellowLED, LOW);
        digitalWrite(redLED, LOW);
        Serial.print("Distance: ");
        Serial.println(distance);
        lcd.clear();
        lcd.setCursor(1,0);
        lcd.print(sum);
        sum = sum + 5;
    } else {
      digitalWrite(redLED,HIGH);
      digitalWrite(greenLED,LOW);
      digitalWrite(yellowLED, LOW);
      Serial.print("Distance: ");
      Serial.println(distance);
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print(sum);
    }
    delay(1000);
  } else {
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED,LOW);
  }
  delay(100);


}
