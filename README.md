# AVR Matrix Keypad, 7-Segment Display & LCD Interfacing

An **Embedded C project using an AVR microcontroller** to scan a 3×3 matrix keypad, display the corresponding digit on a 7-segment display, and show key and button status on a 16×2 LCD.

This project was completed as a practical classroom challenge assigned by my teacher. I was the **first student in my class to complete the task**.

## 📸 Project Demonstration

<!-- Replace the path below with your uploaded project image -->
![AVR Matrix Keypad and Display Interfacing](https://github.com/sarthakboy/AVR-Matrix-Keypad-7-Segment-Display-LCD-Interfacing/blob/main/Screenshot%202026-10-22%20094618.png)

🔗 **LinkedIn Project Post:** [View my project demonstration](https://www.linkedin.com/feed/update/urn:li:activity:7518886632364793856/)

## 🚀 Features

- **3×3 Matrix Keypad Scanning:** Detects key presses by scanning three rows and reading three columns.
- **7-Segment Display:** Displays the corresponding digit using a lookup table.
- **16×2 LCD Interfacing:** Displays the selected keypad digit on the first row.
- **Button State Detection:** Monitors a separate push button and displays START/STOP status on the second row.
- **AVR Register-Level Programming:** Configures GPIO direction, pull-up resistors, and output states using AVR registers.
- **4-Bit LCD Communication:** Sends LCD commands and characters using the upper and lower nibbles of each byte.

## 🛠️ Hardware and Tools

- AVR microcontroller
- 3×3 matrix keypad
- 7-segment display
- 16×2 character LCD
- Push button
- Current-limiting resistors and supporting circuit connections
- AVR-GCC-compatible C environment

*Add your exact microcontroller model and simulator or hardware platform here.*

## ⚙️ Pin Configuration

The following pin assignments are defined in the source code.

| Component | AVR pins | Purpose |
|---|---|---|
| Keypad rows | PA0–PA2 | Row scanning outputs |
| Keypad columns | PA3–PA5 | Column inputs with pull-ups |
| 7-segment display | PORTC | Segment control |
| LCD data lines | PD0–PD3 | 4-bit data interface |
| LCD RS | PD6 | Command/data selection |
| LCD Enable | PD7 | Latches LCD data |
| Push button | PB7 | Button state input with pull-up |

**Note:** Verify the physical wiring against your actual circuit before running the program.

## 🧠 How It Works

1. **Initialization:** Configures GPIO pins, enables the keypad column pull-ups, and initializes the LCD.
2. **Keypad scanning:** Drives one row LOW at a time and checks the column inputs to identify the pressed key.
3. **7-segment output:** Converts the detected digit into its segment pattern using a lookup table.
4. **LCD update:** Displays the selected key on the first row.
5. **Button monitoring:** Checks PB7 for a HIGH-to-LOW transition and changes the displayed status between START and STOP.

## 💻 Key Programming Concepts

- AVR GPIO registers: `DDRA`, `PORTA`, `PINA`, `DDRC`, and `PORTC`
- Bitwise operations and bit masking
- Matrix keypad scanning
- Lookup tables for 7-segment encoding
- LCD initialization and 4-bit data transfer
- Button edge detection
- String comparison and status management in C

## 📚 What I Learned

This project helped me practise integrating multiple peripherals in a single embedded application. Instead of working with each component independently, I combined keypad input, display output, and button-state handling in one program.

It also strengthened my understanding of register-level programming and debugging embedded C code.

## 🔧 Future Improvements

- Add proper keypad debouncing.
- Initialize all state variables and handle startup conditions safely.
- Add support for all 16 keys using a 4×4 matrix keypad.
- Replace blocking delays with timer-based, non-blocking logic.
- Improve LCD updates to avoid unnecessary repeated writes.

## 👨‍💻 Author

**Sarthak Pandey**

Aspiring Embedded Software / Firmware Engineer

Skills: Embedded C · AVR Microcontrollers · GPIO · LCD Interfacing · Peripheral Integration

- LinkedIn: [View my profile](https://www.linkedin.com/in/sarthak-pandey-981551428/)
- Project Post: [View the project on LinkedIn](https://www.linkedin.com/feed/update/urn:li:activity:7518886632364793856/)
