const int trig = 12;     // Trig pin connected to digital pin 12
const int echo = 13;     // Echo pin connected to digital pin 13

const int l1 = 7;        // LED 1
const int l2 = 6;        // LED 2
const int l3 = 8;        // LED 3

long duration;
float distance;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // Trigger the ultrasonic pulse
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // Read the duration
  duration = pulseIn(echo, HIGH);

  // Convert to distance (cm)
  distance = (duration * 0.0343) / 2;

  // Clear all LEDs first
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);

  // LED logic based on distance
  if (distance >= 40) {
    digitalWrite(l1, HIGH);  // Far
  } 
  else if (distance >= 20 && distance < 40) {
    digitalWrite(l2, HIGH);  // Medium
  } 
  else {
    digitalWrite(l3, HIGH);  // Close
  }

  // Print distance
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500); // Small delay
}
