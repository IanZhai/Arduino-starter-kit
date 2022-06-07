
void setup() {
  // put your setup code here, to run once:

pinMode(3,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
for(int i=0;i<180;i++){
  analogWrite(3,read_eeprom(i));
  write(eep
  delay(20);
}
for(int i=100;i>0;i--){
  analogWrite(3,i);
  delay(20);
}
}
array {1, .0175
2, .0349
3, .0523
}
