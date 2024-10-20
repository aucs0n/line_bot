#include <QTRSensors.h>

QTRSensors qtr;
const uint8_t sensorCount = 3; // Change to 5 if using 5 sensors
uint16_t sensorValues[sensorCount];

#define MOTOR_LEFT 9
#define MOTOR_RIGHT 10
#define SENSOR_3 A2
#define SENSOR_2 A3
#define SENSOR_1 A4
#define LED_CTRL A5

void setup() {
  Serial.begin(9600);

  // Initialize QTR sensor array
  qtr.setTypeAnalog();
  qtr.setSensorPins((const uint8_t[]) {SENSOR_3, SENSOR_2, SENSOR_1}, sensorCount);

  // Set motor pins as output
  pinMode(MOTOR_LEFT, OUTPUT);
  pinMode(MOTOR_RIGHT, OUTPUT);
  
  // Initialize motor control
  digitalWrite(MOTOR_LEFT, LOW);
  digitalWrite(MOTOR_RIGHT, LOW);
}

void loop() {
  int position = qtr.readLineBlack(sensorValues); // Get the position of the black line
  Serial.println(position);  // Output position for debugging

  if (position < 1000) {
    // Turn left
    analogWrite(MOTOR_LEFT, 100);
    analogWrite(MOTOR_RIGHT, 255);
  } else if (position > 2000) {
    // Turn right
    analogWrite(MOTOR_LEFT, 255);
    analogWrite(MOTOR_RIGHT, 100);
  } else {
    // Move forward
    analogWrite(MOTOR_LEFT, 255);
    analogWrite(MOTOR_RIGHT, 255);
  }

  delay(50);  // Adjust delay for smoother movements
}
