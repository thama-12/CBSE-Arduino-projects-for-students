const int potPin = A0; 
const int buttonPin = 7; 
const int led1Pin = 6; 
const int led2Pin = 8; 
void setup() { 
pinMode(led1Pin, OUTPUT); 
pinMode(led2Pin, OUTPUT); 
pinMode(buttonPin, INPUT_PULLUP); 
Serial.begin(9600); 
} 
void loop() { 
int potValue = analogRead(potPin); 
int brightness = map(potValue, 0, 1023, 255, 0); 
analogWrite(led1Pin, brightness); 
int buttonState = digitalRead(buttonPin); 
if (buttonState == LOW) { 
digitalWrite(led2Pin, HIGH); 
} else { 
digitalWrite(led2Pin, LOW); 
} 
Serial.print("Potentiometer: "); 
Serial.print(potValue); 
Serial.print("  Brightness: "); 
Serial.println(brightness); 
delay(100); 
} 
