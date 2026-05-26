# Components Required for V2V HAZARD ALERT

## Core Components
| Component | Quantity | Purpose |
| :--- | :--- | :--- |
| ESP32 Development Board | 2 | Main processing and communication controller |
| SX1278 LoRa Module | 2 | Long-range wireless communication |
| 1.3-inch OLED Display (SH1106) | 1 | Display hazard alerts |
| Push Buttons | 2–4 | Trigger emergency alerts |
| Buzzer | 1 | Audio warning indication |
| LEDs | 2–3 | Visual hazard indication |
| Antenna | 2 | LoRa signal transmission |
| Breadboard / PCB | 2 | Circuit assembly |
| Jumper Wires | Multiple | Hardware connections |
| Power Supply / Battery | 2 | Portable operation |

### ESP32 Development Board
**Purpose:**
- Controls LoRa communication
- Processes hazard data
- Drives OLED, buzzer, and LEDs

### SX1278 LoRa Module
**Purpose:**
- Long-range wireless communication
- Peer-to-peer data transfer
- Low-power communication protocol

### OLED Display
**Purpose:**
- Displays hazard warnings
- Provides real-time alert visualization

### Buzzer
**Purpose:**
- Generates audio alert during emergency situations

### LEDs
**Purpose:**
- Provides visual emergency indication

## Circuit Diagram Connections

### SX1278 LoRa ↔ ESP32
| SX1278 Pin | ESP32 Pin |
| :--- | :--- |
| VCC | 3.3V |
| GND | GND |
| SCK | GPIO 5 |
| MISO | GPIO 19 |
| MOSI | GPIO 27 |
| NSS | GPIO 18 |
| RST | GPIO 14 |
| DIO0 | GPIO 26 |

### OLED Display ↔ ESP32
| OLED Pin | ESP32 Pin |
| :--- | :--- |
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

### Buzzer ↔ ESP32
| Buzzer | ESP32 |
| :--- | :--- |
| Positive | GPIO 25 |
| Negative | GND |

### LEDs ↔ ESP32
| LED | ESP32 |
| :--- | :--- |
| Red LED | GPIO 2 |
| Green LED | GPIO 4 |

### Push Buttons ↔ ESP32
| Button | ESP32 |
| :--- | :--- |
| Hazard Button | GPIO 32 |
| Emergency Button | GPIO 33 |
