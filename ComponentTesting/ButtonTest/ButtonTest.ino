#define button 46

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);

}

void loop() {
  Serial.println(digitalRead(button));
  delay(500);

}
