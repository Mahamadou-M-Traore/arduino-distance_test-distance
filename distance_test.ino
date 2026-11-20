// Smart Recycling: HC-SR04 distance test on NodeMCU ESP8266
// This code only checks that the board and the sensor work.
//
// Wiring:
//   HC-SR04 VCC  -> 5V pin of the NodeMCU
//   HC-SR04 GND  -> GND
//   HC-SR04 TRIG -> D5
//   HC-SR04 ECHO -> D6 through a voltage divider (1k and 1.8k resistors).
//                    The Echo pin gives 5 V, but the ESP8266 pin accepts only 3.3 V.

const int trigPin = D5;
const int echoPin = D6;

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW);
}

void loop() {
  // Send the trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin, LOW);

  // Measure the echo time (timeout: 30000 microseconds)
  long duration = pulseIn(echoPin, HIGH, 30000);

  if (duration > 0) {
    // Speed of sound: 0.0343 cm per microsecond. Divide by 2 (go and return).
    float distance = (duration * 0.0343) / 2.0;
    Serial.print("Distance: ");
    Serial.print(distance, 1);
    Serial.println(" cm");
  } else {
    Serial.println("Distance: NO_ECHO");
  }

  delay(200);
}
