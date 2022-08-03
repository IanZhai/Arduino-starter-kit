
int ir = A0;
int led = 12;
void setup() {
  // put your setup code here, to run once:
pinMode(ir,INPUT);
pinMode(led,OUTPUT);
digitalWrite(led, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(ir) == LOW){
  digitalWrite(led, HIGH);
 delay(3000);
}
else{
  digitalWrite(led, LOW);
}
}
