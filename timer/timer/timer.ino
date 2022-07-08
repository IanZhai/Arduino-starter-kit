int second;
int minute;
int hour;
long hourSet = 3600000;
long minSet = 360000;
long secSet = 1000;
unsigned long startTime;
int led = 8;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
startTime = millis();
hour = startTime / hourSet;
minute = (startTime % hourSet) / minSet;
second = ((startTime % hourSet) % minSet) / secSet;
Serial.print(hour);
Serial.print(":");
Serial.print(minute);
Serial.print(":");
Serial.println(second);
if(millis() >= 60000){
  digitalWrite(led, HIGH);
  
}
 

}
