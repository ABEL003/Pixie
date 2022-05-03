int sensorPin = 2;
int ledPin = 13;
int sensorWert;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorWert = digitalRead(sensorPin);
  if (sensorWert == 0) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  Serial.println(sensorWert);
  delay(100);
}
