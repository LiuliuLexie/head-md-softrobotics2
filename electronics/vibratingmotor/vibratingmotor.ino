int mvm = 5;  // micro vibration motor is connected with pin number 5 which is the pwm pin.
int vresistor = A1;
int data = 0;

void setup() {
  // put your setup code here, to run once:

  pinMode(mvm, OUTPUT);
  pinMode(vresistor, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  data = analogRead(vresistor);

  data = map(data, 0, 1023, 0, 255);
  analogWrite(mvm, data);
}
