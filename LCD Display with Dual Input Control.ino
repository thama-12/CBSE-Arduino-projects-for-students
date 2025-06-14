#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Use 0x3F if 0x27 doesn't work

// Pin definitions
const int trigPin = 9;
const int echoPin = 8;
const int potPin = A0;
const int button1 = 2;
const int button2 = 3;
const int redLED = 5;
const int greenLED = 6;

void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  lcd.setCursor(0, 0);
  lcd.print("Ready");
}

void loop() {
  // Measure distance with ultrasonic sensor
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);  
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;

  // LED control based on distance
  if (distance <= 20) {
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
  } else if (distance >=20) {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
  } else {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);
  }

  // Show distance or pot value on LCD
  if (digitalRead(button1) == HIGH) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Distance:");
    lcd.setCursor(0, 1);
    lcd.print(distance, 1);
    lcd.print(" cm");
  } else if (digitalRead(button2) == HIGH) {
    int potVal = analogRead(potPin);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Pot Value:");
    lcd.setCursor(0, 1);
    lcd.print(potVal);
  }

  delay(300);
}
