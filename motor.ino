void go(short a, short b) {
  if (a >= 0) {
    analogWrite(m[0], a * spd);
    analogWrite(m[1], 0);
  } else {
    analogWrite(m[1], abs(a) * spd);
    analogWrite(m[0], 0);
  }
  if (b >= 0) {
    analogWrite(m[2], b * spd);
    analogWrite(m[3], 0);
  } else {
    analogWrite(m[3], abs(b) * spd);
    analogWrite(m[2], 0);
  }
  l = a;
  r = b;
}

void brake() {
  if (l >= 0 && r >= 0) go(-10, -10);
  if (l < 0 && r < 0) go(10, 10);
  if (l < 0 && r >= 0) go(10, -10);
  if (l >= 0 && r < 0) go(-10, 10);
  delay(20);
  go(0, 0);
}

void run() {
  delay(500);
  go(2, -2);
  delay(500);
  brake();
  delay(200);
  go(-2, 2);
  delay(800);
  brake();
  delay(200);
  go(2, -2);
  delay(550);
  brake();
  delay(200);
}