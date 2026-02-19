void reading() {
  sum = 0;
  for (int i = 0; i < 6; i++) {
    s[i] = analogRead(ir[i]);
    (s[i] > 400) ? s[i] = 0 : s[i] = 1;
    sum += i;
  }
}