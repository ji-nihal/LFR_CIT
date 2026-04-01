void follow() {
  while (1) {
    reading();
    if (sensor == 0b001100) go(8, 8);

    else if (sensor == 0b001000) go(6, 8);
    else if (sensor == 0b011000) go(5, 9);
    else if (sensor == 0b010000) go(3, 10);
    else if (sensor == 0b110000) go(0, 10);
    else if (sensor == 0b100000) go(-5, 10);

    else if (sensor == 0b000100) go(8, 6);
    else if (sensor == 0b000110) go(9, 5);
    else if (sensor == 0b000010) go(10, 3);
    else if (sensor == 0b000011) go(10, 0);
    else if (sensor == 0b000001) go(10, -5);
  }
}