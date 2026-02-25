bool u() {
  short i = 0;
  if (digitalRead(sw[0]) == 0) {
    buz(1);
    while (digitalRead(sw[0]) == 0) {
      delay(1);
      i++;
      if (i > 2) buz(0);
    }
    buz(0);
  }
  (i > 15) ? i = 1 : i = 0;
  return i;
}
bool d() {
  short i = 0;
  if (digitalRead(sw[1]) == 0) {
    buz(1);
    while (digitalRead(sw[1]) == 0) {
      delay(1);
      i++;
      if (i > 2) buz(0);
    }
    buz(0);
  }
  (i > 15) ? i = 1 : i = 0;
  return i;
}
byte c() {
  short i = 0;
  if (digitalRead(sw[2]) == 0) {
    buz(1);
    while (digitalRead(sw[2]) == 0) {
      delay(1);
      i++;
      if (i > 2) buz(0);
      if (i >= 200) led(1);
    }
    buz(0);
    led(0);
  }
  if (i > 200) i = 2;
  else if (i > 15) i = 1;
  else i = 0;
  return i;
}