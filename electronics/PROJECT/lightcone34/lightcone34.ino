// LIGHT CONE normal only LED
// Wemo board
// Interactions and feedbacks:
// - When stay there without interactions, LED on, white light
// every random(5,10) seconds, it randomly output feedback 1-5
// feedback1: LED off; feedback2: slow blink; feedback 3: rainbow color change; feedback4: LED off for 5 seconds; feedback5: quick blink

const int redPin = D8;   
const int greenPin = D7;  
const int bluePin = D6;  

unsigned long lastInteractionTime = 0;
unsigned long nextInteractionInterval = random(5000, 10000); 

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  setLED(255, 255, 255);

  Serial.begin(9600);
}

void loop() {
  unsigned long currentTime = millis();

  setLED(255, 255, 255);

  // Trigger random feedback every 5-10 seconds
  if (currentTime - lastInteractionTime > nextInteractionInterval) {
    int feedback = random(1, 6);  // Randomly feedback 1-5
    triggerFeedback(feedback);

    lastInteractionTime = currentTime;
    nextInteractionInterval = random(5000, 10000);
  }
}

// Helper Functions

void setLED(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

// Trigger specific feedback
void triggerFeedback(int feedback) {
  switch (feedback) {
    case 1:  // Feedback1: LED off
      setLED(0, 0, 0);
      Serial.println("Feedback 1: LED Off");
      break;

    case 2:  // Feedback2: Slow blink
      Serial.println("Feedback 2: Slow Blink");
      blinkLED(255, 255, 255, 5, 500);  
      break;

    case 3:  // Feedback3: Rainbow color change
      Serial.println("Feedback 3: Rainbow Effect");
      rainbowEffect(10);  
      break;

    case 4:  // Feedback4: LED off for 5 seconds
      Serial.println("Feedback 4: LED Off for 5 seconds");
      setLED(0, 0, 0);
      delay(5000);
      setLED(255, 255, 255); 
      break;

    case 5:  // Feedback5: Quick blink
      Serial.println("Feedback 5: Quick Blink");
      blinkLED(255, 255, 255, 10, 100); 
      break;
  }
}

void blinkLED(int red, int green, int blue, int times, int delayTime) {
  for (int i = 0; i < times; i++) {
    setLED(red, green, blue);
    delay(delayTime);
    setLED(0, 0, 0);
    delay(delayTime);
  }
}

// Rainbow
void rainbowEffect(int delayTime) {
  for (int i = 0; i < 256; i++) {
    setLED(255, i, 0);  
    delay(delayTime);
  }
  for (int i = 255; i >= 0; i--) {
    setLED(i, 255, 0);  
    delay(delayTime);
  }
  for (int i = 0; i < 256; i++) {
    setLED(0, 255, i); 
    delay(delayTime);
  }
  for (int i = 255; i >= 0; i--) {
    setLED(0, i, 255); 
    delay(delayTime);
  }
  for (int i = 0; i < 256; i++) {
    setLED(i, 0, 255); 
    delay(delayTime);
  }
  for (int i = 255; i >= 0; i--) {
    setLED(255, 0, i); 
    delay(delayTime);
  }
}
