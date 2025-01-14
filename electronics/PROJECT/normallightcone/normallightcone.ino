// LIGHT CONE
// Wemo board, no interaction, only light, and network tbc
// RGB LED Blinking Red, Green, Blue

// Pin definitions for RGB LED
const int redPin = D6; 
const int greenPin = D7; 
const int bluePin = D8;

void setup() {
  // Set RGB pins as output
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Initialize all colors as OFF (HIGH for common anode)
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, HIGH);
  digitalWrite(bluePin, HIGH);
}

void loop() {
  // Blink Red
  digitalWrite(redPin, LOW);  // LOW = ON for common anode
  delay(500);                // 0.5 second
  digitalWrite(redPin, HIGH); // HIGH = OFF

  // Blink Green
  digitalWrite(greenPin, LOW); 
  delay(500);
  digitalWrite(greenPin, HIGH);

  // Blink Blue
  digitalWrite(bluePin, LOW); 
  delay(500);
  digitalWrite(bluePin, HIGH);
}
