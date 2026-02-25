void reading() {
  sum = 0;
  for (int i = 0; i < 6; i++) {
    s[i] = analogRead(ir[i]);
    (s[i] > mid) ? s[i] = 0 : s[i] = 1;
    sum += i;
  }
}

void calibration() {
  oled.clearField(0, 2, 22);
  oled.clearField(0, 3, 22);
  oled.clearField(0, 4, 22);
  oled.clearField(0, 5, 22);
  oled.clearField(0, 6, 22);
  oled.clearField(0, 7, 22);
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
  go(2, -2);
  t1 = millis();
  while (millis() - t1 < 2440) {
    for (int i = 0; i < 6; i++) {
      s[i] = analogRead(ir[i]);
      maximum[i] = max(maximum[i], s[i]);
      minimum[i] = min(minimum[i], s[i]);
    }
  }
  brake();
  delay(200);

  for (byte i = 0; i < 6; i++) {
    mid[i] = (maximum[i] + minimum[i]) / cal;
    EEPROM.write(i, mid[i] / 4);
    delay(10);
    EEPROM.write(i + 6, maximum[i] / 4);
    delay(10);
    EEPROM.write(i + 12, minimum[i] / 4);
    delay(10);
  }
  value();
}