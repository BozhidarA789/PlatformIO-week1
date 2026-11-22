# Lab 1 – ESP32 GPIO Input / Output

PlatformIO project for the ESP32 (ESP32-DevKit-V1, 30 pins) using the Arduino framework.
The program toggles an LED every time a push button is pressed.

## Behaviour

- The LED turns **on** when the ESP32 starts up.
- Each press of the button **toggles** the LED (on → off → on ...).
- The button is **debounced** in software, so one press gives exactly one toggle.

## Wiring

| Component    | Connection                              |
|--------------|-----------------------------------------|
| LED          | GPIO23 → 220 Ω resistor → LED → GND     |
| Push button  | GPIO22 → button → 3.3V                  |

The button input uses `INPUT_PULLDOWN`. When the button is not pressed, the internal
pull-down resistor holds GPIO22 at LOW. Without it, the pin would be "floating" and read
random values. Pressing the button connects the pin to 3.3V, so it reads HIGH.

## Project structure

```
Lab1/
├── platformio.ini        # board + build settings
└── src/
    └── main.cpp          # Lab 1a program (LED toggle)
```

## Build and upload

Open the `Lab1` folder in VS Code with the PlatformIO extension installed, then use
**PlatformIO: Upload** (→) in the bottom status bar.
