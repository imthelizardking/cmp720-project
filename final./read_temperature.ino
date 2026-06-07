#include <Wire.h>
#include <Adafruit_BME280.h>

Adafruit_BME280 bme;

void setup() {
  Serial.begin(9600);

  if (!bme.begin(0x76)) {       // try 0x77 if this fails
    Serial.println("BME280 not found!");
    while (1);
  }

  Serial.println("BME280 ready.");
}

void loop() {
  float temp     = bme.readTemperature();          // °C
  float humidity = bme.readHumidity();             // %

  Serial.print("Temp: ");     Serial.print(temp);     Serial.println(" C");
  Serial.print("Humidity: "); Serial.print(humidity); Serial.println(" %");

  delay(2000);
}