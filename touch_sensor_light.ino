#include <CapacitiveSensor.h>//调用电容传感器库
CapacitiveSensor capSensor = CapacitiveSensor(4,2);//定义四号引脚输出，2号引脚输入
int threshold = 1000;//设置临界点
const int ledPin = 12;//指定12引脚为led输出
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);//打开串口9600
pinMode(ledPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
long sensorValue = capSensor.capacitiveSensor(30);//检测30次
Serial.println(sensorValue);
if(sensorValue > threshold){
  digitalWrite(ledPin, HIGH);//将采样结果与临界值进行对比，决定led是否点亮
}
else{
  digitalWrite(ledPin, LOW);
}
delay(10);
}
