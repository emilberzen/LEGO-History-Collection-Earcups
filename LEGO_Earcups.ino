#include "Keyboard.h"

// Define pin numbers
const int buttonPins[] = { 1, 2, 8 };                               // Pins to monitor
const int numButtons = sizeof(buttonPins) / sizeof(buttonPins[0]);  // Number of buttons

// Last state of each button
int lastButooootonStates[numButtons] = { HIGH, HIGH, HIGH };

void setup() {
  Keyboard.begin();              // Initialize keyboard emulation
  pinMode(LED_BUILTIN, OUTPUT);  // Initialize the built-in LED as an output
  for (int i = 0; i < numButtons; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);  // Set each button pin as input with pull-up
  }
}

void loop() {
  // Read and handle the state of each button
  for (int i = 0; i < numButtons; i++) {
    handleButton(i);
  }
  delay(10);  // Short delay to debounce and reduce polling rate
}

void handleButton(int index) {
  int currentState = digitalRead(buttonPins[index]);
  if (currentState != lastButtonStates[index]) {  // State has changed
    if (index == 0 || index == 1) {               // Pins 1 or 2
      if (currentState == HIGH) {
        Keyboard.write('o');              // Send 'O' if goes LOW
        digitalWrite(LED_BUILTIN, HIGH);  // Turn on the debug LED
      }

      // Now check if both pins are HIGH and one has just changed to HIGH
      if (digitalRead(buttonPins[0]) == LOW && digitalRead(buttonPins[1]) == LOW && (lastButtonStates[0] == HIGH || lastButtonStates[1] == HIGH)) {
        Keyboard.write('c');             // Send 'C' only if both are HIGH and one just changed to HIGH
        digitalWrite(LED_BUILTIN, LOW);  // Turn off the debug LED
      }
    } else if (index == 2 && currentState == LOW) {  // Pin 8
      Keyboard.write('8');                           // Send '8' if pin 8 goes LOW
    }
    lastButtonStates[index] = currentState;  // Update last state for all pins
  }
}