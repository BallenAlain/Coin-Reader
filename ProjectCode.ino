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
double sum = 0.00;

void displays(){
  // displays the sum
  lcd.setCursor(0,0);
  lcd.print("Balance:");
  lcd.setCursor(9,0);
  lcd.print(sum);
}

void clearLine(int line){
  // clears a line by replacing all characters with a blank space
  String string = "";
  for(int i = 0; i < 16; i++){
    // addes a white space to the string variable
    string += " "; //concatenate a blank space to the string variable
  }
  lcd.setCursor(0, line); //set the position on the LCD
  lcd.print(string); //print the blank spaces on the LCD
}

void resetValue(){
    lcd.setCursor(0,1); //sets the position on the LCD
    lcd.print("Balance reset!");
    sum = 0.00;
    delay(500);
    clearLine(1); //clears the "Balance reset!" statement
}

void getDistance(){
  // trig pin controls when an ultrasonic pulse is sent out
  //will send 8 waves
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  
  // reads how long the wave travels to and from the object
  duration = pulseIn(echoPin, HIGH);
  /* measures the distance by multiplying 
   * the duration by the speed of soundthen divide by 2
   *  manual calibration by subtracting 1 cm.
   */
  distance = ((duration*0.034)/2 - 1);  
}

void setup() {
  Serial.begin(9600); //start communication to the serial monitor.
  //serial monitor is used for testing purposes
  pinMode(trigPin, OUTPUT); //controls the echol pin
  pinMode(echoPin, INPUT); //recieved duration values from the echo pin
  lcd.begin(16,2); //defines the dimensions of the LCD
  lcd.backlight(); 
  pinMode(greenLED,OUTPUT);
  pinMode(redLED,OUTPUT);
  pinMode(yellowLED,OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {

  getDistance();

  button = digitalRead(buttonPin);
  Serial.print("Distance: ");
  Serial.println(distance);
  Serial.println(sum);

  if(button == LOW){
    // when the button is pressed
    // resets the balance to 0
    resetValue();
  }
  
  displays();
  
  if(distance >= 2 && distance < 8){ 
    // when there is a coin inserted turn on the yellow LED
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);
    delay(3000); //allows time for the user to adjust the positioning of the coin
    getDistance();

    if(distance == 2){ //can change distance values
        // reading a coin with a value of $0.05 (nickel)
        digitalWrite(greenLED, HIGH);
        digitalWrite(yellowLED, LOW);
        digitalWrite(redLED, LOW);
        Serial.print("Distance: ");
        Serial.println(distance); //testing purposes
        lcd.clear();
        displays();
        lcd.setCursor(1,1);
        lcd.print("adding 5 cents");
        sum = sum + 0.05;
        delay(5000); //allows time for the user to remove the coin
        clearLine(1); //clear the indication statement
        
    } else if(distance == 3){ //can change distance values
        // reading a coin with a value of $2.00 (toonie)
        digitalWrite(greenLED, HIGH);
        digitalWrite(yellowLED, LOW);
        digitalWrite(redLED, LOW);
        Serial.print("Distance: ");
        Serial.println(distance); //testing purposes
        lcd.clear(); 
        displays();
        lcd.setCursor(1,1); 
        lcd.print("adding 2 dollars");
        sum = sum + 2.00;
        delay(5000); //allows time for the user to remove the coin
        clearLine(1); //clear the indication statement
        
    } else {
      // Coin is unable to be read
      digitalWrite(redLED,HIGH);
      digitalWrite(greenLED,LOW);
      digitalWrite(yellowLED, LOW);
      Serial.print("Distance: ");
      Serial.println(distance);
      lcd.clear();
      displays();
      lcd.setCursor(1,1);
      lcd.print("unable to read");
      delay(5000); //allows time for the user to remove the coin
      clearLine(1); //clears the indication statement
    }
    /*distance values can be changed to match other Canadian coins
     * device does not use a DHT11 sensor
     */
  } else { 
    // turn off all LEDs when there is no coin being inserted
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED,LOW);
    digitalWrite(greenLED, LOW);
  }
  
  delay(100);
}
