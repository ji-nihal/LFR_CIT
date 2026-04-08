//..................Motor Control...................
//..................................................
void go(short a, short b) {
  if (a >= 0) {
    short x = abs(a) * spd;
    if (x > 255) x = 255;
    analogWrite(m[0], x);
    analogWrite(m[1], 0);
  } else {
    short x = abs(a) * spd;
    if (x > 255) x = 255;
    if (a < -10) a = -10;
    analogWrite(m[1], x);
    analogWrite(m[0], 0);
  }
  if (b >= 0) {
    short x = abs(b) * spd;
    if (x > 255) x = 255;
    analogWrite(m[2], x);
    analogWrite(m[3], 0);
  } else {
    short x = abs(b) * spd;
    if (x > 255) x = 255;
    analogWrite(m[3], x);
    analogWrite(m[2], 0);
  }
  l = a;
  r = b;
}

//...................Motor Brake....................
//..................................................
void brake() {
  if (l >= 0 && r >= 0) go(-10, -10);
  if (l < 0 && r < 0) go(10, 10);
  if (l < 0 && r >= 0) go(10, -10);
  if (l >= 0 && r < 0) go(-10, 10);
  delay(30);
  go(0, 0);
}

//.......................RUN........................
//..................................................
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