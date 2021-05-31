#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3f, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.backlight();
}
  void loop(){

  lcd.setCursor(3,0);
  lcd.print("H");
  delay(200);
  lcd.setCursor(5,1);
  lcd.print("H");
  delay(200);

  lcd.setCursor(5,0);
  lcd.print("E");
  delay(200);
  lcd.setCursor(7,1);
  lcd.print("E");
  delay(200);

  lcd.setCursor(7,0);
  lcd.print("L");
  delay(100);
  lcd.setCursor(9,1);
  lcd.print("L");
  delay(200);

  lcd.setCursor(9,0);
  lcd.print("L");
  delay(200);
  lcd.setCursor(11,1);
  lcd.print("L");
  delay(200);

  lcd.setCursor(11,0);
  lcd.print("O");
  delay(200);
  lcd.setCursor(13,1);
  lcd.print("O");
  delay(400);
  lcd.clear();

  delay(400);
  lcd.setCursor(3,0);
  lcd.print("H E L L O");
  lcd.setCursor(5,1);
  lcd.print("H E L L O");
  delay(400);
  lcd.clear();
  delay(400);

  lcd.setCursor(3,0);
  lcd.print("H E L L O");
  lcd.setCursor(5,1);
  lcd.print("H E L L O");
  delay(400);
  lcd.clear();
  delay(400);

  lcd.setCursor(3,0);
  lcd.print("H E L L O");
  lcd.setCursor(5,1);
  lcd.print("H E L L O");
  delay(400);
  lcd.clear();
  delay(400);

  lcd.setCursor(3,0);
  lcd.print("H E L L O");
  lcd.setCursor(5,1);
  lcd.print("H E L L O");
  delay(400);
  lcd.clear();
  delay(400);
}
