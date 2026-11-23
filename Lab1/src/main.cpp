/*
 * Lab 1a - GPIO - Input / Output
 * Name:           Bozhidar
 * Student number: 26087235
 *
 * Toggles an LED every time the button is pressed.
 *
 * Wiring:
 *   GPIO23 -> 220 Ohm resistor -> LED -> GND
 *   GPIO22 -> push button -> 3.3V
 */

#include <Arduino.h>

#define LED_PIN     GPIO_NUM_23
#define BUTTON_PIN  GPIO_NUM_22
#define DEBOUNCE_MS 60

int ledState = HIGH;  // the LED starts ON

void setup() {
  pinMode(LED_PIN, OUTPUT);

  // The button connects GPIO22 to 3.3V when pressed. When it is not pressed
  // the pin is connected to nothing ("floating") and could read HIGH or LOW
  // at random. INPUT_PULLDOWN turns on the internal pull-down resistor, which
  // pulls the pin to GND so it reads a stable LOW when the button is released.
  pinMode(BUTTON_PIN, INPUT_PULLDOWN);

  // Requirement: the LED is on when the ESP32 starts up
  digitalWrite(LED_PIN, ledState);
}

void loop() {
  // Is the button pressed?
  if (digitalRead(BUTTON_PIN) == HIGH) {
    // Debouncing: the contacts of a button "bounce" for a few milliseconds,
    // so the pin quickly switches between HIGH and LOW. Wait a moment and
    // check again to make sure it is a real press.
    delay(DEBOUNCE_MS);

    if (digitalRead(BUTTON_PIN) == HIGH) {
      // Toggle the LED
      ledState = !ledState;
      digitalWrite(LED_PIN, ledState);

      // Wait until the button is released, so holding it down
      // only toggles the LED once
      while (digitalRead(BUTTON_PIN) == HIGH) {
        delay(10);
      }

      // The button also bounces when it is released
      delay(DEBOUNCE_MS);
    }
  }
}
