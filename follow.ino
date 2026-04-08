void follow() {
  eeprom();
  while (1) {
a:
    reading();
    if (sensor == 0b001100) {
      side = 's';
      go(8, 8);
    }

    else if (sensor == 0b001000) {
      side = 's';
      go(7, 8);
    } else if (sensor == 0b011000) {
      side = 's';
      go(5, 8);
    } else if (sensor == 0b010000) {
      side = 's';
      go(0, 9);
    } else if (sensor == 0b110000) {
      side = 'r';
      go(-5, 9);
    } else if (sensor == 0b100000) {
      side = 'r';
      go(-10, 10);
    }

    else if (sensor == 0b000100) {
      side = 's';
      go(8, 7);
    } else if (sensor == 0b000110) {
      side = 's';
      go(8, 5);
    } else if (sensor == 0b000010) {
      side = 's';
      go(9, 0);
    } else if (sensor == 0b000011) {
      side = 'l';
      go(9, -5);
    } else if (sensor == 0b000001) {
      side = 'l';
      go(10, -10);
    }

    if (!sum) {
      if (side == 'l') {
        go(8, -8);
        while (!sum) {
          reading();
        }
      } else if (side == 'r') {
        go(-8, 8);
        while (!sum) {
          reading();
        }
      } else {
        go(6, 6);
        t1 = millis();
        while (!sum) {
          reading();
          if (millis() - t1 > 50) {
            brake();
            go(6, -6);
            while (!sum) reading();
            break;
          }
        }
      }
    }

    if (sum == 6) {
      go(6, 6);
      t1 = millis();
      while (sum == 6) {
        reading();
        if (millis() - t1 > 50) {
          brake();
          while (1) {
            byte z = c();
            if (z == 1) goto a;
            else if (z == 2) {
              counter = -1;
              break;
            }
          }
        }
      }
      flag = 'l';
    }
    if (counter == -1) break;
  }
}