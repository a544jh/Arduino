
// include the library code:
#include <LiquidCrystal.h>
#include <DHT.h>
#include <Ultrasonic.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte tempChar[] = {
  B00100,
  B01010,
  B01010,
  B01110,
  B01110,
  B01110,
  B11111,
  B01110
};

byte humidityChar[] = {
  B00100,
  B00100,
  B01010,
  B01010,
  B10001,
  B10001,
  B10001,
  B01110
};

byte ultrasonicChar[] = {
  B00100,
  B00000,
  B01010,
  B00100,
  B10001,
  B01110,
  B00000,
  B11111
};

#define DHT_PIN 8
DHT dht(DHT_PIN, DHT22);

#define US_TRIG 9
#define US_ECHO 10
Ultrasonic ultrasonic(US_TRIG, US_ECHO);

void setup() {
  dht.begin();
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  lcd.createChar(0, tempChar);
  lcd.createChar(1, humidityChar);
  lcd.createChar(2, ultrasonicChar);

}

void loop() {
  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();
  float dist = ultrasonic.distanceRead();
  lcd.clear();
  lcd.write(byte(0));
  lcd.print(":" + String(temp,1) + "\xdf" + "C ");
  lcd.write(1);
  lcd.print(":" + String(humidity,1) + "%");
  lcd.setCursor(0,1);
  lcd.write(2);
  lcd.print(":" + String(dist,0) + "cm");
  delay(1000);
}

