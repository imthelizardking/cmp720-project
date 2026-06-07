#define IN1 8
#define IN2 9
#define PULSE_MS 50 

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  // Start with both low — no current through coil
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void openValve() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  delay(PULSE_MS);
  digitalWrite(IN1, LOW);   // cut power — valve latches open
  digitalWrite(IN2, LOW);
}

void closeValve() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  delay(PULSE_MS);
  digitalWrite(IN1, LOW);   // cut power — valve latches closed
  digitalWrite(IN2, LOW);
}

void loop() {
  openValve();
  delay(2000);   // wait 2 seconds
  closeValve();
  delay(2000);
}