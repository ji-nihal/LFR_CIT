void start() {
  oled.clear();
  oled.println("   Creative Juniors");
  oled.println("     Advanced LFR     ");
  oled.println();
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
  oled.print("  ");
  delay(200);
  for (int i = 3; i <= 6; i++) {
    oled.clearField(0, i, 22);
  }
  oled.setCursor(0, 3);
  oled.println("     0 0 0 0 0 0");
  oled.println();
  oled.print(" ");
  oled.print("RUN");
  oled.print("  ");
  oled.print("Menu");
  oled.print("  ");
  oled.print("Calibrate");
}
void select(short i) {
  if (i == 0) {
    oled.clearField(0, 5, 22);
    oled.setInvertMode(1);
    oled.setCursor(0, 5);
    oled.print(" RUN ");
    oled.setInvertMode(0);
    oled.print(" Menu  Calibrate ");
  } else if (i == 1) {
    oled.clearField(0, 5, 22);
    oled.setCursor(0, 5);
    oled.print(" RUN ");
    oled.setInvertMode(1);
    oled.print(" Menu ");
    oled.setInvertMode(0);
    oled.print(" Calibrate ");
  } else if (i == 2) {
    oled.clearField(0, 5, 11);
    oled.setCursor(0, 5);
    oled.print(" RUN  Menu ");
    oled.setInvertMode(1);
    oled.print(" Calibrate ");
    oled.setInvertMode(0);
  }
}
void sensor() {
  reading();
  oled.clearField(0, 3, 22);
  oled.print("     ");
  for (int i = 0; i < 6; i++) {
    oled.print(s[i]);
      oled.print(" ");
  }
}