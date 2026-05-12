# IR Temperature Sensor

An Arduino project that uses the **MLX90614 non-contact IR sensor** to measure and log human body (object) temperature over time via the Serial Monitor.

## Hardware

- Arduino (Uno, Nano, or compatible)
- Melexis MLX90614 IR thermometer module
- Jumper wires

### Wiring (I2C)

| MLX90614 Pin | Arduino Pin |
|---|---|
| VCC | 3.3V or 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

> **Note:** The MLX90614 communicates over I2C at address `0x5A`.

## Dependencies

Install via the Arduino Library Manager:

- [Adafruit MLX90614 Library](https://github.com/adafruit/Adafruit-MLX90614-Library)
- Adafruit BusIO (installed automatically as a dependency)

## Usage

1. Wire the sensor as described above.
2. Upload `IRTempSensor.ino` to your Arduino.
3. Open the Serial Monitor at **9600 baud**.
4. Temperature readings will print every second in °C.

**Example output:**
```
Human Body Temperature Monitor
At time = 0 seconds, the calibrated Object temperature is: 36.85 °C
At time = 1 seconds, the calibrated Object temperature is: 36.90 °C
```
