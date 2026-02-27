void start() {
  oled.clear();
  oled.print("  ");
  oled.setInvertMode(1);
  oled.print(" ");
  oled.setInvertMode(0);
  oled.print(" Creative Juniors");
  oled.println();
  oled.print("    ");
  oled.setInvertMode(1);
  oled.print(" ");
  oled.setInvertMode(0);
  oled.print(" Advanced LFR");
  oled.setCursor(0, 3);
  oled.println("     Starting...");
  delay(200);
  oled.println();
  oled.print("  ");
  oled.setInvertMode(1);
  for (int i = 0; i < 18; i++) {
    delay(50);
    oled.print(" ");
  }
  oled.setInvertMode(0);
  delay(200);
  clr_page();
  menu_1();
}


void clr_page() {
  for (int i = 2; i <= 7; i++) {
    oled.clearField(0, i, 22);
  }
}


void menu_1() {
  oled.setCursor(0, 7);
  oled.print(" ");
  oled.print("RUN");
  oled.print("  ");
  oled.print("Menu");
  oled.print("  ");
  oled.print("Calibrate");
}


void select(short i) {
  if (i == 0) {
    oled.clearField(0, 7, 22);
    oled.setCursor(0, 7);
    oled.setInvertMode(1);
    oled.print(" RUN ");
    oled.setInvertMode(0);
    oled.print(" Menu  Calibrate ");
  } else if (i == 1) {
    oled.clearField(0, 7, 22);
    oled.setCursor(0, 7);
    oled.print(" RUN ");
    oled.setInvertMode(1);
    oled.print(" Menu ");
    oled.setInvertMode(0);
    oled.print(" Calibrate ");
  } else if (i == 2) {
    oled.clearField(0, 7, 11);
    oled.setCursor(0, 7);
    oled.print(" RUN  Menu ");
    oled.setInvertMode(1);
    oled.print(" Calibrate ");
    oled.setInvertMode(0);
  }
}


void sensor_value() {
  reading();
  oled.clearField(0, 3, 22);
  oled.clearField(0, 4, 22);
  oled.clearField(0, 5, 22);
  oled.setCursor(0, 3);
  for (byte i = 1; i < 5; i++) {
    oled.setCursor(letter * (5 * (i - 1) + 1), 3);
    oled.print(analogRead(ir[i]));
  }
  oled.setCursor(0, 4);
  oled.print(analogRead(ir[0]));
  oled.setCursor(letter * 17, 4);
  oled.print(analogRead(ir[5]));
  oled.setCursor(0, 5);
  oled.print("     ");
  for (int i = 0; i < 6; i++) {
    oled.print(s[i]);
    oled.print(" ");
  }
}


void value() {
  eeprom();
  clr_page();

  oled.setCursor(0, 2);
  oled.print(" mid=");
  for (byte i = 0; i < 3; i++) {
    oled.clearField(letter * (6 * (i + 1) - i), 2, 4);
    oled.setCursor(letter * (6 * (i + 1) - i), 2);
    oled.print(mid[i]);
  }
  for (byte i = 0; i < 3; i++) {
    oled.clearField(letter * (6 * (i + 1) - i), 3, 4);
    oled.setCursor(letter * (6 * (i + 1) - i), 3);
    oled.print(mid[i + 3]);
  }

  oled.setCursor(0, 4);
  oled.print(" min=");
  for (byte i = 0; i < 3; i++) {
    oled.clearField(letter * (6 * (i + 1) - i), 4, 4);
    oled.setCursor(letter * (6 * (i + 1) - i), 4);
    oled.print(minimum[i]);
  }
  for (byte i = 0; i < 3; i++) {
    oled.clearField(letter * (6 * (i + 1) - i), 5, 4);
    oled.setCursor(letter * (6 * (i + 1) - i), 5);
    oled.print(minimum[i + 3]);
  }

  oled.setCursor(0, 6);
  oled.println(" max=");
  for (byte i = 0; i < 3; i++) {
    oled.clearField(letter * (6 * (i + 1) - i), 6, 4);
    oled.setCursor(letter * (6 * (i + 1) - i), 6);
    oled.print(maximum[i]);
  }
  for (byte i = 0; i < 3; i++) {
    oled.clearField(letter * (6 * (i + 1) - i), 7, 4);
    oled.setCursor(letter * (6 * (i + 1) - i), 7);
    oled.print(maximum[i + 3]);
  }

  while (1) {
    byte z = c();
    if (z) {
      clr_page();
      menu_1();
      select(1);
      break;
    }
  }
}