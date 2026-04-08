//.................Sensor Reading...................
//..................................................
void reading() {
  sum = 0;
  sensor = 0;
  for (int i = 0; i < 6; i++) {
    s[i] = analogRead(ir[i]);
    (s[i] > mid[i]) ? s[i] = 0 : s[i] = 1;
    sensor += s[i] * base[i];
    sum += s[i];
  }
}

//...............Sensor Calibration.................
//..................................................
void calibration() {
  clr_page();
  oled.setCursor(0, 3);
  oled.set2X();
  oled.println("Calibrating");
  oled.print("   .....");
  oled.set1X();
  delay(500);
  for (byte i = 0; i < 6; i++) {
    maximum[i] = 0;
    minimum[i] = 1023;
  }
  go(4, -4);
  t1 = millis();
  while (millis() - t1 < 2500) {
    for (int i = 0; i < 6; i++) {
      s[i] = analogRead(ir[i]);
      maximum[i] = max(maximum[i], s[i]);
      minimum[i] = min(minimum[i], s[i]);
    }
  }
  for (int i = 0; i < 6; i++) {
    mid[i] = (maximum[i] + minimum[i]) / cal;
  }
  brake();
  for (byte i = 0; i < 6; i++) {
    EEPROM.write(i, maximum[i] / 4);
    delay(10);
    EEPROM.write(i + 6, minimum[i] / 4);
    delay(10);
  }
  value();
}