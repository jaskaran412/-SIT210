const int ledPin = LED_BUILTIN;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void dot() {
  digitalWrite(ledPin, HIGH);
  delay(200);
  digitalWrite(ledPin, LOW);
  delay(200);
}

void dash() {
  digitalWrite(ledPin, HIGH);
  delay(600);
  digitalWrite(ledPin, LOW);
  delay(200);
}

void letterSpace() {
  delay(600);
}

void wordSpace() {
  delay(1400);
}

void blinkMorse_Jaskaran() {
  // J: .---
  dot(); dash(); dash(); dash(); letterSpace();

  // A: .-
  dot(); dash(); letterSpace();

  // S: ...
  dot(); dot(); dot(); letterSpace();

  // K: -.-
  dash(); dot(); dash(); letterSpace();

  // A: .-
  dot(); dash(); letterSpace();

  // R: .-.
  dot(); dash(); dot(); letterSpace();

  // A: .-
  dot(); dash(); letterSpace();

  // N: -.
  dash(); dot(); letterSpace();
}

void loop() {
  blinkMorse_Jaskaran();
  wordSpace();
}
