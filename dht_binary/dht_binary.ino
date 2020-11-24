#include <DHT.h>

#define LEDS_START_PIN 3
#define LEDS 9

DHT dht(2, DHT22);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  for (int i = LEDS_START_PIN; i < LEDS_START_PIN + LEDS; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  displayDecimal(dht.readTemperature());
  delay(1000);
  displayDecimal(dht.readHumidity());
  delay(1000);
}

void displayBinary(int num) {
  Serial.print("Putting bit ");
  for (int i = LEDS_START_PIN; i < LEDS_START_PIN + LEDS; i++) {
    int bit = (bitRead(num, i - LEDS_START_PIN) ? HIGH : LOW);
    digitalWrite(i, bit);

    //Serial.print(bit);
  }
  //Serial.println();
}

void displayDecimal(float fnum) {

  int num = fnum * 10;
  //Serial.println(num);
  String str(num);
  //Serial.println(str);
  for (int pos = 0; pos < str.length(); pos++) {
    //Serial.println(pos);
    int digit = int(str.charAt(pos)) - 48;
    //Serial.println(digit);
    
    allOff();
    delay(200);
    for (int i = LEDS_START_PIN; i < LEDS_START_PIN + digit; i++) {
      digitalWrite(i, HIGH);
    }
    delay(600);
  }
  allOff();
}

void allOff() {
  for (int i = LEDS_START_PIN; i < LEDS_START_PIN + LEDS; i++) {
    digitalWrite(i, LOW);
  }
}

