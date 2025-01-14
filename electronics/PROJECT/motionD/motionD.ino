// MOTION CONE type D
// Wemo board
// Interactions and feedbacks:
// ball switch on, vibrating, off, stop
// lightvalue > 500, vibrating, <500, stop


// Pin
const int tiltPin = D2; 
// const int photoResistorPin = A0;
const int motorPin = D6;

void setup() {
  pinMode(tiltPin, INPUT_PULLUP); 
  pinMode(motorPin, OUTPUT);
  // pinMode(photoResistorPin, INPUT); 

  digitalWrite(motorPin, LOW);
  Serial.begin(9600);
}

void loop() {
  int ballState = digitalRead(tiltPin); // 0 = on，1 = off
  // int lightValue = analogRead(photoResistorPin);

  // if (ballState == LOW || lightValue > 500) {
  //   digitalWrite(motorPin, HIGH);
  // } else {
  //   digitalWrite(motorPin, LOW); 
  // }

  if (ballState == LOW) {
    analogWrite(motorPin, 255);
  } else {
    analogWrite(motorPin, 30); 
  }

  // debug
  Serial.print("Ball Switch: ");
  Serial.print(ballState == LOW ? "ON" : "OFF");
  // Serial.print(" | Light Value: ");
  // Serial.print(lightValue);
  Serial.print(" | Motor Intensity: ");
  Serial.println(ballState == LOW ? "255 (HIGH)" : "30 (LOW)");

  delay(100);
}

