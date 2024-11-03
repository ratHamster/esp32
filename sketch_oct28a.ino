int const PinGS = A0;
int LED_Safe = 7;
int LED_Warning = 6;

void setup() {
  Serial.begin(9600);
  pinMode(LED_Safe, OUTPUT);
  pinMode(LED_Warning, OUTPUT);
  pinMode(PinGS, INPUT);
}

void loop() {
  int value = analogRead(PinGS);
  Serial.println(value);
  if (value > 150) {
    digitalWrite(LED_Safe, LOW);
    digitalWrite(LED_Warning, HIGH);
    delay(1000);
  } else {
    digitalWrite(LED_Safe, HIGH);
    digitalWrite(LED_Warning, LOW);
    delay(1000);
  }
  delay(1000);
}
