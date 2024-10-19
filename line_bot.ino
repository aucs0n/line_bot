#include <QTRSensors.h>

QTRSensors qtr;
const uint8_t sensorCount = 3;
uint16_t sensorValues[sensorCount];

#define SENSOR_5 A0
#define SENSOR_4 A1
#define SENSOR_3 A2
#define SENSOR_2 A3
#define SENSOR_1 A4
#define LED_CTRL A5

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  qtr.setTypeAnalog();
  qtr.setSensorPins((const uint8_t[]) {A3, A2, A1}, sensorCount);


  // pinMode(SENSOR_5, INPUT);
  // pinMode(SENSOR_4, INPUT);
  // pinMode(SENSOR_3, INPUT);
  // pinMode(SENSOR_2, INPUT);
  // pinMode(SENSOR_1, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  int position = qtr.readLineBlack(sensorValues);

  Serial.println(position);

  // int val_5 = analogRead(SENSOR_5);
  // int val_4 = analogRead(SENSOR_4);
  // int val_3 = analogRead(SENSOR_3);
  // int val_2 = analogRead(SENSOR_2);
  // int val_1 = analogRead(SENSOR_1);
  
  // Serial.print(val_5 + val_4 + val_3 + val_2 + val_1);
}
