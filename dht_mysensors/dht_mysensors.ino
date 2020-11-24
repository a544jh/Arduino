#define MY_DEBUG

#define MY_RADIO_NRF24
#define MY_RF24_PA_LEVEL RF24_PA_MIN
#define MY_NODE_ID 1

#include <MySensors.h>
#include <DHT.h>

#define TEMPERATURE_ID 1
#define HUMIDITY_ID 2

DHT dht(3, DHT22);

void presentation() {
  sendSketchInfo("DHT test", "1");

  present(TEMPERATURE_ID, S_TEMP);
  present(HUMIDITY_ID, S_HUM);
}

void setup() {
  // put your setup code here, to run once:
  dht.begin();
  Serial.print("Test temperature: ");
  Serial.println(dht.readTemperature());
}

void loop() {
  // put your main code here, to run repeatedly:
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  MyMessage tempMsg(TEMPERATURE_ID, V_TEMP);
  tempMsg.set(temperature, 1);
  send(tempMsg);

  MyMessage humMsg(HUMIDITY_ID, V_HUM);
  humMsg.set(humidity, 1);
  send(humMsg);

  sleep(3000);
}
