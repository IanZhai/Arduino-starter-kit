#include <Servo.h>//调用伺服库函数
Servo myServo;//定义伺服名称
int const potPin = A0;//定义电位器输入端口A0
int potVal;//定义电位器数值
int angle;//定义伺服角度

void setup() {
  // put your setup code here, to run once:
myServo.attach(9);//定义伺服控制端口9
Serial.begin(9600);//打开端口

}

void loop() {
  // put your main code here, to run repeatedly:
potVal = analogRead(potPin);//读取电位器数值
Serial.print("potVal: ");
Serial.print(potVal);//打印电位器数值
angle = map(potVal, 0, 1023, 0, 179);//使用map函数将电位器数值转化为角度
Serial.print(", angle: ");
Serial.println(angle);//打印角度
myServo.write(angle);//输出角度到舵机
delay(15);
}
