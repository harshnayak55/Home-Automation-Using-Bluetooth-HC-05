Below is a professional **README.md** that you can directly upload to your GitHub repository. It is based on your Proteus circuit and AVR C code, which uses an **ATmega32**, **HC-05 Bluetooth module**, **16×2 LCD**, and **4 relay-controlled appliances**. The firmware initializes UART at **9600 baud**, receives Bluetooth commands, controls relays, and displays appliance status on the LCD. 

---

````markdown
# 🏠 Smart Home Automation using ATmega32 and Bluetooth

A Bluetooth-based Smart Home Automation System designed using the **ATmega32 microcontroller**, simulated in **Proteus**, and programmed in **Embedded C** using **AVR-GCC**.

The system allows users to wirelessly control multiple home appliances from an Android smartphone through the HC-05 Bluetooth module. A 16×2 LCD displays the current status of each appliance.

---

## 📌 Project Overview

This project demonstrates a low-cost smart home automation system capable of controlling electrical appliances using Bluetooth communication.

The ATmega32 receives commands from an HC-05 Bluetooth module via UART and controls relay modules connected to different appliances.

The LCD continuously displays the current status of the selected appliance.

---

## ✨ Features

- Bluetooth-based wireless control
- ATmega32 Microcontroller
- HC-05 Bluetooth Module
- 16×2 LCD Display
- Controls multiple appliances
- Relay-based switching
- Real-time appliance status display
- Proteus simulation
- Embedded C firmware

---

## 🛠 Components Used

| Component | Quantity |
|-----------|----------|
| ATmega32 Microcontroller | 1 |
| HC-05 Bluetooth Module | 1 |
| 16×2 LCD | 1 |
| 5V Relay Module | 4 |
| Bulb | 1 |
| DC Motor/Fan | 1 |
| LED | 1 |
| Buzzer | 1 |
| Capacitor (0.1µF) | 1 |
| 5V Supply | 1 |

---

## 📷 Proteus Simulation

The Proteus design includes:

- ATmega32
- HC-05 Bluetooth
- LCD
- Four Relay Modules
- Bulb
- Motor
- LED
- Buzzer

---

## 🔌 Hardware Connections

### HC-05 → ATmega32

| HC-05 | ATmega32 |
|--------|----------|
| TX | RXD (PD0) |
| RX | TXD (PD1) |
| VCC | +5V |
| GND | GND |

---

### LCD Connections

LCD operates in **4-bit mode**.

| LCD Pin | ATmega32 |
|----------|-----------|
| RS | PD2 |
| EN | PD3 |
| D4-D7 | PORTD |
| VSS | GND |
| VDD | +5V |
| VEE | Potentiometer |

---

### Relay Outputs

| Relay | Device |
|--------|--------|
| Relay 1 | Bulb |
| Relay 2 | Motor |
| Relay 3 | LED |
| Relay 4 | Buzzer |

---

## 📱 Bluetooth Commands

| Command | Action |
|----------|--------|
| 1 | Bulb ON |
| A | Bulb OFF |
| 2 | Motor ON |
| B | Motor OFF |
| 3 | LED ON |
| C | LED OFF |
| 4 | Buzzer ON |
| D | Buzzer OFF |

---

## 💻 Software Used

- Proteus 8 Professional
- AVR-GCC
- Atmel Studio
- Android Bluetooth Terminal App

---

## ⚙ Working Principle

1. Power ON the circuit.
2. Pair the Android phone with HC-05.
3. Open any Bluetooth Terminal application.
4. Connect to HC-05.
5. Send command characters.
6. ATmega32 receives UART data.
7. Corresponding relay is activated/deactivated.
8. LCD updates appliance status.

---

## 📂 Project Structure

```
Smart-Home-Automation/
│
├── Proteus/
│   ├── homeautoproteus.pdsprj
│
├── Code/
│   ├── main.c
│   ├── hometrial.hex
│
├── Images/
│   ├── Screenshot 2026-07-01 113755.png
│
├── README.md
```

---

## ⚡ UART Configuration

- Baud Rate : 9600
- Data Bits : 8
- Stop Bits : 1
- Parity : None

---

## 📺 LCD Display

Example messages:

```
SMART HOME
AUTOMATION
```

When controlling appliances:

```
Bulb ON
```

```
Motor OFF
```

```
LED ON
```

```
Buzzer OFF
```

---

## 🚀 Future Improvements

- ESP32 Wi-Fi Control
- IoT Dashboard
- Firebase Integration
- Voice Assistant Support
- Mobile Application
- Scheduling System
- Energy Monitoring
- Password Protected Access

---

## 🎯 Applications

- Smart Homes
- Offices
- Laboratories
- Industrial Automation
- Educational Projects
- Embedded Systems Learning

---

## 👨‍💻 Author

**Harsh Nayak**

Electronics and Communication Engineering

GitHub: https://github.com/yourusername

---

## 📄 License

This project is released under the MIT License.

Feel free to use and modify it for educational purposes.
````

---

### GitHub Folder Structure (Recommended)

```
Smart-Home-Automation/
│
├── README.md
├── LICENSE
├── main.c
├── SmartHome.hex
├── homeautoproteus.pdsprj
├── Circuit.png
├── Images/
│   ├── Simulation.png
│   ├── Hardware.png
│
└── Documentation/
    ├── Report.pdf
```


