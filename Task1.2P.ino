#define MOTION_SENSOR_PIN 2  // Motion Sensor is connected to Pin 2
#define LED_PIN 13  // Built-in LED is connected to Pin 13
#define BUTTON_PIN 3  // Button is connected to Pin 3

volatile bool isLedOn = false; 

void setup() {
  pinMode(MOTION_SENSOR_PIN, INPUT); // Set the motion sensor pin as input
  pinMode(LED_PIN, OUTPUT); // Set the LED pin as output
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // Set the button pin as input with pullup resistor
  Serial.begin(9600); // Start the serial communication
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), toggleLED, CHANGE);  // The interrupt will be triggered whenever the button state changes
}

void loop() {
  // Control the LED based on the button state
  if (isLedOn) {
    digitalWrite(LED_PIN, HIGH); 
    Serial.println("LED is ON.");
  } else {
    digitalWrite(LED_PIN, LOW); 
    Serial.println("LED is OFF.");
  }
  delay(1000);
}
void toggleLED() {
  if (digitalRead(BUTTON_PIN) == LOW) { // If the button is pressed
    isLedOn = !isLedOn; 
    delay(20);
    while (digitalRead(BUTTON_PIN) == LOW);
    delay(20);
  }
}
