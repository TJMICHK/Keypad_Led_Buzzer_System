# Keypad_Led_Buzzer_System
Arduino project that reads a 4×4 matrix keypad and gives feedback with an LED and a piezo buzzer. It’s designed as a simple “enter code → success/fail beep with LED” system.

## Demo
- Find in .media file

## Hardware
- Arduino UNO R3
- 4x4 Matrix Membrane Keypad
- Red LED + 220 Ω Resistor
- Green LED + 220 Ω Resistor
- Active Piezo Buzzer
- Breadboard + Jumper Wires

## How to Run
1. Open `src/project2_range_based_alarm/project3_keypad_led_buzzer.ino` in the Arduino IDE.
2. Select your board and COM port.
3. Click **Upload**.

## Features
- Adjustable distance threshold to trigger LED and buzzer
- Optional pulsed buzzer/LED pattern (beep, flash, or static)
- Simple pin mapping for easy rewiring
- Serial output for live distance readings

## What I Learned
- How to setup and utilize a Matrix Keypad, inluding its adjacent functions.
- C++ Logic to ask for a input, remember a input, and determine equality of the input relative to an accepted value.

## Next Steps
- [ ] Add I2C Liquid Crystal Display
- [ ] Build a physical function which runs if the code is true
