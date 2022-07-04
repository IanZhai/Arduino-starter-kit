const int sensorPin = A0;
const float baselineTemp = 20.0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);//open a port
for(int pinNumber = 2; pinNumber<5; pinNumber++){
  pinMode(pinNumber,OUTPUT);
  digitalWrite(pinNumber,LOW);//led1-3,off
}
}

void loop() {
  // put your main code here, to run repeatedly:
int sensorVal = analogRead(sensorPin);
Serial.print("Sensor Value ");
Serial.print(sensorVal);//print sensor value
float voltage = (sensorVal/1024.0) * 5.0;//transform sensor value to voltage
Serial.print(", Volts: ");
Serial.print(voltage);//print voltage
Serial.print(", degrees C:  ");
float temp = (voltage - .5)*100;//transform voltage to tem
Serial.println(temp);
if(temp < baselineTemp){
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);//temp<baselinetemp,led1-3,off
}else if(temp >= baselineTemp+2 && temp < baselineTemp+4){
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);//baselinetemp+2 <= temp < baselinetemp+4，led1 is on
}else if(temp >= baselineTemp+4 && temp < baselineTemp+6){
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);//baselinetemp+4 <= temp < baselinetemp+6，led1,2 are on
}else if(temp >= baselineTemp+6){
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);//temp > baselinetemp+6, 3leds are on
}//to choose the temp range by if else loop
delay(10);

}
