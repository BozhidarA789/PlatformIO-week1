/*
 * Lab 1a - GPIO - Input / Output
 * Name:           Bozhidar
 * Student number: 26087235
 *
 * Toggles an LED every time the button is pressed.
 *
 * How it works:
 *   1. setup() configures the pins and turns the LED on.
 *   2. loop() keeps checking the button.
 *   3. When a press is detected, it waits DEBOUNCE_MS and checks again
 *      to ignore contact bounce.
 *   4. If the button is still pressed, the LED is toggled.
 *   5. It then waits until the button is released, so one press = one toggle.
 *
 * Wiring:
 *   GPIO23 -> 220 Ohm resistor -> LED -> GND
 *   GPIO22 -> push button -> 3.3V
 */

#include <Arduino.h>

<<<<<<< HEAD
#define LED_PIN     GPIO_NUM_23
#define BUTTON_PIN  GPIO_NUM_22
#define DEBOUNCE_MS 60
=======
#define LED_PIN     GPIO_NUM_23  // output: LED via 220 Ohm resistor
#define BUTTON_PIN  GPIO_NUM_22  // input: push button to 3.3V
#define DEBOUNCE_MS 50           // time (ms) to wait for the button to settle
>>>>>>> c400f40c99eb16c7e373545a7d45ffdc3c3e1d81

// Remembers whether the LED is on (HIGH) or off (LOW).
// It starts as HIGH so the LED is on at startup.
int ledState = HIGH;

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
      // Toggle the LED: "!" flips HIGH to LOW and LOW to HIGH
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
