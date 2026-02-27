#include <EEPROM.h>
#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

#define I2C_ADDRESS 0x3C
SSD1306AsciiWire oled;

byte sw[3] = { 1, 0, 12 }, spd = 25, cal = 2, letter = 6;
short ir[6] = { A7, A6, A3, A2, A1, A0 }, s[6], sum, sensor;
short base[6] = { 32, 16, 8, 4, 2, 1 };
short m[4] = { 6, 9, 11, 10 }, maximum[6], minimum[6], mid[6];
short counter = -1, l, r;
unsigned long t1 = 0;

void setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(s[i], INPUT);
  }
  for (int i = 0; i < 4; i++) {
    pinMode(m[i], OUTPUT);
  }
  for (int i = 0; i < 3; i++) {
    pinMode(sw[i], INPUT);
  }
  pinMode(2, OUTPUT);
  pinMode(13, OUTPUT);

  Wire.begin();
  Wire.setClock(400000L);
  oled.begin(&Adafruit128x64, I2C_ADDRESS);
  oled.setFont(Adafruit5x7);
  eeprom();
  start();
}
void loop() {
  if (millis() - t1 > 50) {
    sensor_value();
    t1 = millis();
  }
  bool x = u();
  bool y = d();
  byte z = c();

  if (x) {
    counter--;
    if (counter < 0) counter++;
    short i = counter % 3;
    select(i);
  }
  if (y) {
    counter++;
    if (counter > 2) counter--;
    short i = counter % 3;
    select(i);
  }
  if (z) {
    if (z == 2 || counter == -1) counter = counter;
    else if (counter == 0) run();
    else if (counter == 1) value();
    else if (counter == 2) calibration();
  }
}
