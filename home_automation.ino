// Pin Assignments
const int lightPin = 8;        // LED for Light
const int fanPin = 9;          // LED for Fan
const int lightButtonPin = 2;  // Button for Light
const int fanButtonPin = 3;    // Button for Fan

// Current states
int lightState = LOW;
int fanState = LOW;

void setup() {
  // Set LED pins as OUTPUT
  pinMode(lightPin, OUTPUT);
  pinMode(fanPin, OUTPUT);

  // Set button pins as INPUT with internal pull-up resistors
  pinMode(lightButtonPin, INPUT_PULLUP);
  pinMode(fanButtonPin, INPUT_PULLUP);

  // Initialize both devices OFF
  digitalWrite(lightPin, lightState);
  digitalWrite(fanPin, fanState);
}

void loop() {
  // Light Button Pressed (Active LOW)
  if (digitalRead(lightButtonPin) == LOW) {
    delay(200); // Debounce delay
    lightState = !lightState; // Toggle state
    digitalWrite(lightPin, lightState);
    while (digitalRead(lightButtonPin) == LOW); // Wait until released
  }

  // Fan Button Pressed (Active LOW)
  if (digitalRead(fanButtonPin) == LOW) {
    delay(200);
    fanState = !fanState;
    digitalWrite(fanPin, fanState);
    while (digitalRead(fanButtonPin) == LOW);
  }
}
