/*
 * Ultrasonic Simple
 * Prints the distance read by an ultrasonic sensor in
 * centimeters. They are supported to four pins ultrasound
 * sensors (liek HC-SC04) and three pins (like PING)))
 * and Seeed Studio sesores).
 *
 * The circuit:
 * * Module HR-SC04 (four pins) or PING))) (and other with
 *   three pins), attached to digital pins as follows:
 * ---------------------    ---------------------
 * | HC-SC04 | Arduino |    | 3 pins  | Arduino |
 * ---------------------    ---------------------
 * |   Vcc   |   5V    |    |   Vcc   |   5V    |
 * |   Trig  |   12    | OR |   SIG   |   13    |
 * |   Echo  |   13    |    |   Gnd   |   GND   |
 * |   Gnd   |   GND   |    ---------------------
 * ---------------------
 * Note: You need not obligatorily use the pins defined above
 * 
 * By default, the distance returned by the distanceRead()
 * method is in centimeters, to get the distance in inches,
 * pass INC as a parameter.
 * Example: ultrasonic.distanceRead(INC)
 *
 * created 3 Apr 2014
 * by Erick Simões (github: @ErickSimoes | twitter: @AloErickSimoes)
 * modified 23 Jan 2017
 * by Erick Simões (github: @ErickSimoes | twitter: @AloErickSimoes)
 * modified 03 Mar 2017
 * by Erick Simões (github: @ErickSimoes | twitter: @AloErickSimoes)
 *
 * This example code is released into the MIT License.
 */

#include <Ultrasonic.h>

#define LEDS_START_PIN 3
#define LEDS 9

/*
 * Pass as a parameter the trigger and echo pin, respectively,
 * or only the signal pin (for sensors 3 pins), like:
 * Ultrasonic ultrasonic(13);
 */
Ultrasonic ultrasonic(12, 13);

void setup() {
  for (int i = LEDS_START_PIN; i < LEDS_START_PIN + LEDS; i++) {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  Serial.print("Distance in CM: ");
  // Pass INC as a parameter to get the distance in inches
  int distance = ultrasonic.distanceRead();
  Serial.println(distance);
  displayDecimal(distance);
  delay(1000);
}

void displayDecimal(int num) {

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
