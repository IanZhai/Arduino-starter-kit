const int controlPin = 2;
void setup() {
  // put your setup code here, to run once:
pinMode(controlPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(controlPin, HIGH);
delay(10000);
digitalWrite(controlPin,LOW);
delay(3000);
}
