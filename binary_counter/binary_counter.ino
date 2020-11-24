#define LEDS_START_PIN 3
#define LEDS 9

int number = 0;

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  for (int i = LEDS_START_PIN; i < LEDS_START_PIN + LEDS; i++) {
    pinMode(i, OUTPUT);
    //Serial.print("Setting pin ");
    //Serial.println(i);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  displayBinary(number);
  delay(10);
  number++;
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

