#define MOTION_SENSOR_PIN 2  // Motion Sensor is connected to Pin 2
#define LED_PIN 13  // Built-in LED is connected to Pin 13
#define BUTTON_PIN 3  // Button is connected to Pin 3

bool isLedOn = false;
void setup() {
  pinMode(MOTION_SENSOR_PIN, INPUT); // Set the motion sensor pin as input
  pinMode(LED_PIN, OUTPUT); // Set the LED pin as output
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // Set the button pin as input with pullup resistor
  Serial.begin(9600); // Start the serial communication
}
void loop() {
  int buttonState = digitalRead(BUTTON_PIN); // Read the state of the button
  if (buttonState == LOW) {
    delay(20);  
    if (digitalRead(BUTTON_PIN) == LOW) { 
      isLedOn = !isLedOn; 
      while (digitalRead(BUTTON_PIN) == LOW);
      delay(20);
    }
  }
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