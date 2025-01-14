//MOTION CONE 1
//wemo D1 mini board
//ball switch activated, vibrates, off, stop vibration

const int ballSwitchPin = D2;
const int motorPin = D7;

void setup() {
  pinMode(ballSwitchPin, INPUT_PULLUP);
  pinMode(motorPin, OUTPUT);
  digitalWrite(motorPin, LOW);
  Serial.begin(115200);
}

void loop() {
  int switchState = digitalRead(ballSwitchPin);

  // Serial.println(switchState);  // debug
  // digitalWrite(motorPin, HIGH);

  if (switchState == LOW) {
    digitalWrite(motorPin, HIGH);
    Serial.println("Motor ON");
  } else {
    digitalWrite(motorPin, LOW);
    Serial.println("Motor OFF");
  }

  delay(10);
}
