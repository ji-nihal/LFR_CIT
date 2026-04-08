//...................Read EEPROM....................
//..................................................
void eeprom() {
  for (byte i = 0; i < 6; i++) {
    maximum[i] = EEPROM.read(i) * 4;
    minimum[i] = EEPROM.read(i + 6) * 4;
    mid[i] = (maximum[i] + minimum[i]) / cal;
  }
}