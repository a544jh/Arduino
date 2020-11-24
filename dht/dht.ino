#include <DHT.h>

DHT dht(3, DHT22);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(500);
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  Serial.print(temperature);
  Serial.print(" ");
  Serial.print(humidity);
  Serial.print("\n");
}
