void follow() {
  while (1) {
a:
    reading();
    if (sensor == 0b001100) {
      side = 's';
      go(8, 8);
    }

    else if (sensor == 0b001000) {
      side = 's';
      go(6, 8);
    } else if (sensor == 0b011000) {
      side = 's';
      go(5, 9);
    } else if (sensor == 0b010000) {
      side = 's';
      go(3, 10);
    } else if (sensor == 0b110000) {
      side = 'r';
      go(0, 10);
    } else if (sensor == 0b100000) {
      side = 'r';
      go(-5, 10);
    }

    else if (sensor == 0b000100) {
      side = 's';
      go(8, 6);
    } else if (sensor == 0b000110) {
      side = 's';
      go(9, 5);
    } else if (sensor == 0b000010) {
      side = 's';
      go(10, 3);
    } else if (sensor == 0b000011) {
      side = 'l';
      go(10, 0);
    } else if (sensor == 0b000001) {
      side = 'l';
      go(10, -5);
    }

    if (sum == 0) {
      if (flag == 's' && side == 's') {
        t1 = millis();
        go(5, 5);
        while (sum == 0) {
          reading();
          if (millis() - t1 > 20) break;
        }
        brake();
        go(5, -5);
        while (sum == 0) reading();
      } 
      
      else if (flag == 's' && side == 'l') {
        go(10, -10);
        while (!sum) reading();
      }

      else if (flag == 's' && side == 'r') {
        go(-10, 10);
        while (!sum) reading();
      }

      else {
        go(5, 5);
        delay(20);
        brake();
        (flag == 'l') ? go(-5, 5) : go(5, -5);
        while (sum) reading();
        while (!sum) reading();
        delay(20);
        brake();
        flag = 's';
      }
    }

    else if (sum == 6) {
      t1 = millis();
      go(5, 5);
      while (millis() - t1 < 100) {
        reading();
        if (sum != 6) {
          flag = 'l';
          t1 = millis();
          goto a;
        }
      }
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

    if (counter == -1) break;

    if ((s[2] || s[3]) && s[0] && !s[5]) {
      flag = 'l';
      t1 = millis();
    }

    else if ((s[2] || s[3]) && s[0] && !s[5]) {
      flag = 'r';
      t1 = millis();
    }

    if (millis() - t1 > 1000) flag = 's';
  }
}