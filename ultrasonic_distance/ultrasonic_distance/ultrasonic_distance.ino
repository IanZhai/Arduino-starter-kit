const int TrigPin = 2;
const int EchoPin = 3;
const int TonePin = 5;
float range_cm;
void setup() {
  // put your setup code here, to run once:
pinMode(TrigPin, OUTPUT);
pinMode(EchoPin, INPUT);
pinMode(TonePin, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(TrigPin, LOW);
delayMicroseconds(2);
digitalWrite(TrigPin, HIGH);
delayMicroseconds(10);
digitalWrite(TrigPin, LOW);

range_cm = pulseIn(EchoPin, HIGH) / 58.8;
range_cm = (int(range_cm * 100)) / 100;
if( range_cm < 10.0){
  tone(TonePin, 500);
}
else{
  noTone(TonePin);
}
Serial.print("distance:");
Serial.print(range_cm);
Serial.print("cm");
Serial.println();
delay(100);
}
