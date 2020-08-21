//---------------------------------------------------------------------------------------------------------------------------------------
void Serialprint64(uint64_t n)
{
  print64(&Serial, n);
  Serial.println();
}
//---------------------------------------------------------------------------------------------------------------------------------------
size_t print64(Print* pr, uint64_t n)
{
  char buf[21];
  char *str = &buf[sizeof(buf) - 1];
  *str = '\0';
  do {
    uint64_t m = n;
    n /= 10;
    *--str = m - 10 * n + '0';
  } while (n);
  pr->print(str);
}
//---------------------------------------------------------------------------------------------------------------------------------------
size_t print64(Print* pr, int64_t n)
{
  size_t s = 0;
  if (n < 0) {
    n = -n;
    s = pr->print('-');
  }  return s + print64(pr, (uint64_t)n);
}
//---------------------------------------------------------------------------------------------------------------------------------------
size_t println64(Print* pr, int64_t n)
{
  return print64(pr, n) + pr->println();
}
//---------------------------------------------------------------------------------------------------------------------------------------
size_t println64(Print* pr, uint64_t n)
{
  return print64(pr, n) + pr->println();
}
//---------------------------------------------------------------------------------------------------------------------------------------
void waitForSerialInput()
{
  static const char *waitMessage = "Press SEND in Serial Monitor ";
  int c = 0;
  while (Serial.available() == 0)
  {
    Serial.print(waitMessage[c++]);
    c %= 30;
    delay(250);
  }
  Serial.println(".");
}
