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
void blinkMorse_Tanish() {
  // T: -
  dash(); letterSpace();
  // A: .-
  dot(); dash(); letterSpace();
  // N: -.
  dash(); dot(); letterSpace();
  // I: ..
  dot(); dot(); letterSpace();
  // S: ...
  dot(); dot(); dot(); letterSpace();
  // H: ....
  dot(); dot(); dot(); dot(); letterSpace();
}
void loop() {
  blinkMorse_Tanish();   
  wordSpace();         
}
