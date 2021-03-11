int pos = 0;
const int buzzer = 4;
int periode=20000;
const byte TRIGGER = 6;
const byte ECHO = 7;
const unsigned long MEASURE_TIMEOUT = 25000UL;
const float SOUND_SPEED = 340.0 / 1000;
int led = 13;
int vert = 11;

void setup() {               
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  pinMode(vert, OUTPUT);
  pinMode(TRIGGER, OUTPUT);
  digitalWrite(TRIGGER, LOW);
  pinMode(ECHO, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);
  
  long measure = pulseIn(ECHO, HIGH, MEASURE_TIMEOUT);
  float distance_mm = measure / 2.0 * SOUND_SPEED;
  float dist = distance_mm / 10.0;
  Serial.print(dist, 2);
  Serial.println("cm de distance");
  if (dist < 100) {
    digitalWrite(led, HIGH);
    digitalWrite(vert, LOW);
    tone(buzzer, 1000);
  }
  else {
    digitalWrite(led, LOW);
    digitalWrite(vert, HIGH);
    noTone(buzzer);
  }
}