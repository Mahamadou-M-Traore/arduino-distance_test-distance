# Smart Recycling: Fill-Level Forecasting and Dynamic Routing

Interdisciplinary project, Computer Engineering, Istanbul Arel University (Fall 2026).

We build a small system for campus recycling bins. A sensor node measures how full a bin is. We forecast the fill level and plan a route only for the bins that will be full.

**Status: work in progress.**

## What is in this repository

| Folder or file | Content |
|---|---|
| `arduino/distance_test/distance_test.ino` | Test code for the HC-SR04 sensor on the NodeMCU |
| `data/test_results.csv` | Results of the chocolate box test |
| `images/` | Photos of the test setup (to be added) |

## Hardware

- NodeMCU V3 ESP8266 ESP-12E (CH340)
- HC-SR04 ultrasonic sensor
- Breadboard, jumper wires, 1k and 1.8k resistors, micro USB cable

## Wiring (test setup)

| HC-SR04 | NodeMCU |
|---|---|
| VCC | 5V |
| GND | GND |
| TRIG | D5 |
| ECHO | D6, through a **voltage divider** (1k and 1.8k resistors, about 3.2 V). The Echo pin gives 5 V, but the ESP8266 pin accepts only 3.3 V. |

Note: the 5V pin (VV/VU) of one NodeMCU does not work. We built the same circuit on both boards. We powered the circuit of the broken board from the 5V pin of the working board, at a different time.

## Test result: chocolate box (14 cm)

| Chocolate height (cm) | Expected distance (cm) | Measured distance (cm) |
|---|---|---|
| 0 (empty box) | 14.0 | 14.8 |
| 3 | 11.0 | 11.5 |
| 4 | 10.0 | 10.7 |

Mean error (MAE): about 0.7 cm.

## Done and not done

**Done**
- First test of the board and the sensor
- First distance test in a 14 cm box

**Not done yet**
- Real data from a campus bin
- Simulation
- Forecast (Holt-Winters and ARIMA)
- Route planning (Clarke-Wright)
- LEDs and OLED display (parts not received yet)

## Public datasets we plan to use

- COMPOSITION Fill Level Sensors: https://zenodo.org/records/3375560
- Netvox R718X bin sensor (Melbourne): https://discover.data.vic.gov.au/en_AU/dataset/netvox-r718x-bin-sensor/resource/8aa57ce9-2939-4c70-92f7-c20e436fdd99
