#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

#define I2C_ADDRESS 0x3C
SSD1306AsciiWire oled;

byte sw[3] = { 1, 0, 12 };
short ir[6] = { A7, A6, A3, A2, A1, A0 }, s[6], sum;
short m[4] = { 6, 9, 10, 11 };
short counter = -1;
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

  start();
}
void loop() {
  if (millis() - t1 > 200) {
    sensor();
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
}
