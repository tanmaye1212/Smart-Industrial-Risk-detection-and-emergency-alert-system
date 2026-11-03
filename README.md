#### Smart Industrial Risk Detection and Emergency Alert System ####


## Project Overview

The **Smart Industrial Risk Detection and Emergency Alert System** is an embedded-based industrial safety monitoring system developed using the **LPC2129 ARM7 Microcontroller** and Embedded C.

The system is designed to continuously monitor industrial environments and detect potential hazards such as high temperature, gas leakage, fire, abnormal vibration, current overload, and high humidity.

When an unsafe condition is detected, the system generates visual and audible alerts, sends wireless notifications, records fault events, and activates relay-based protection to disconnect the affected machine during emergency conditions.


## Objectives

- Monitor multiple industrial safety parameters in real time.
- Detect potential industrial hazards automatically.
- Generate immediate visual and audible emergency alerts.
- Send wireless notifications through Bluetooth.
- Automatically disconnect machinery during critical conditions.
- Record fault events with timestamps for future analysis.
- Enable communication between monitoring nodes using CAN protocol.


## Hardware Components

| Component | Purpose |
|---|---|
| LPC2129 ARM7 | Main microcontroller |
| DHT11 | Temperature and humidity monitoring |
| MQ2 Gas Sensor | Gas leakage detection |
| Flame Sensor | Fire detection |
| Vibration Sensor | Abnormal vibration detection |
| ACS712 | Current monitoring |
| 16×2 LCD | Display system status and alerts |
| HC-05 Bluetooth | Wireless notifications |
| MCP2551 CAN Transceiver | CAN communication |
| DS1307 RTC | Timestamp generation |
| 24C256 EEPROM | Fault data storage |
| Relay Module | Automatic machine disconnection |
| LEDs and Buzzer | Visual and audible alerts |


## Software and Technologies

- Programming Language: Embedded C
- Microcontroller: LPC2129 ARM7
- IDE: Keil µVision
- Flashing Utility: Flash Magic
- Communication Protocols: UART, I2C, SPI and CAN
- Peripherals: GPIO, ADC and Interrupts


## Working Principle

1. **System Initialization:** Initializes the microcontroller peripherals, sensors, communication interfaces and output devices.
2. **Sensor Monitoring:** Continuously collects temperature, humidity, gas, vibration and current readings.
3. **Condition Evaluation:** Compares sensor readings against predefined safety thresholds.
4. **Hazard Detection:** Identifies abnormal conditions and classifies them as Safe, Warning or Emergency.
5. **Alert Generation:** Activates LEDs, buzzer and LCD messages according to the detected condition.
6. **Wireless Communication:** Sends emergency notifications through the HC-05 Bluetooth module.
7. **Automatic Protection:** Activates the relay-based shutdown mechanism during critical conditions.
8. **Event Logging:** Records fault information using RTC and EEPROM/SD-card storage.
9. **CAN Communication:** Broadcasts emergency information to other monitoring nodes.


## Key Features

- Real-time industrial safety monitoring.
- Multi-sensor hazard detection.
- Interrupt-driven fire detection.
- Threshold-based decision-making.
- Automatic relay-based protection.
- Bluetooth emergency notifications.
- CAN-based industrial communication.
- Timestamped fault logging.
- Modular Embedded C architecture.


## Limitations

- Uses predefined thresholds rather than machine-learning algorithms.
- Sensor calibration is required.
- Bluetooth communication has limited range.
- Industrial-scale deployment requires additional hardware protection and ruggedisation.


## Future Enhancements

- IoT-based remote monitoring.
- Cloud-based industrial dashboards.
- Mobile application integration.
- AI-based predictive maintenance.
- Wireless industrial communication using Zigbee or LoRa.
- Multi-machine monitoring.
- Camera-based fire and smoke detection.


## Project Domain

Embedded Systems | Industrial Automation | ARM7 Microcontrollers | Industrial Safety Monitoring
