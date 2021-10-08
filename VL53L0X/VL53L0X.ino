#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;

int a;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin();

  sensor.setTimeout(500);
  if(!sensor.init()){
    Serial.println("Failed");
  }
  
  #if defined LONG_RANGE
    sensor.setSignalRateLimit(0.1);
    sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
    sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);
  #endif

  #if defined HIGH_SPEED
    sensor.setMeasurementTimingBudget(20000);
  #elif defined HIGH_ACCURACY
    sensor.setMeasurementTimingBudget(20000);
  #endif
    
//  pinMode(7, OUTPUT);
//
//  digitalWrite(7, LOW);
//
//  delay(500);
//
//  digitalWrite(7, HIGH);
//  delay(150);
//  delay(100);
//  sensor.setAddress((uint8_t)01);
//
//  sensor.startContinuous();

}

void loop() {
  // put your main code here, to run repeatedly:
  a = sensor.readRangeContinuousMillimeters();

  Serial.println(a);

  delay(500);
}
