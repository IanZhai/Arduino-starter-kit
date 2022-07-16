int led1 = 6;
int s1 = 11;
int switchState = 0;
int preSwitchState = 0;
int counter = 0;
void setup() {
  // put your setup code here, to run once:
pinMode(led1, OUTPUT);
pinMode(s1, INPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedl
switchState = digitalRead(s1);  

if (switchState == HIGH){
  if(switchState != preSwitchState){
    counter ++;
    Serial.println(counter);
    

  }
  
  
  digitalWrite(led1, HIGH);
  
}
else {
  digitalWrite(led1, LOW);
}
preSwitchState = switchState;

}
