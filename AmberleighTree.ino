// Backlight
const int RED = 5;
const int GREEN = 6;
const int BLUE = 3;

// Fireflys
const int F3 = 7; // No PWM
const int F4 = 8; // No PWM

const int F0 = 9;
const int F1 = 10;
const int F2 = 11;

// Speed
int s0 = 2;
int s1 = 3;
int s2 = 4;

// Fade Value
int fv0 = 2;
int fv1 = 125;
int fv2 = 220;

int updateSpeed(int sv, int fv) {
  if(fv >= 250 || fv <= 1) {
    sv = -sv;
  }

  return sv;
}

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  
  pinMode(F0, OUTPUT);
  pinMode(F1, OUTPUT);
  pinMode(F2, OUTPUT);
  pinMode(F3, OUTPUT);
  pinMode(F4, OUTPUT);
}

void loop() {
  digitalWrite(F3, HIGH);
  digitalWrite(F4, HIGH);

  s0 = updateSpeed(s0, fv0);
  s1 = updateSpeed(s1, fv1);
  s2 = updateSpeed(s2, fv2);

  fv0 = fv0 + s0;
  fv1 = fv1 + s1;
  fv2 = fv2 + s2;
  
  analogWrite(F0, fv0);
  analogWrite(F1, fv1);
  analogWrite(F2, fv2);

  analogWrite(BLUE, 75);

  delay(30);
}
