#include<Servo.h>//调用伺服库
Servo myServo;//定义伺服name
const int piezo = A0;
const int switchPin = 2;
const int yellowLed = 3;
const int greenLed = 4;
const int redLed = 5;//声明led灯以及模拟输入的引脚
int knockVal;
int switchVal;//创建变量来存储开关及蜂鸣器的值
const int quietKnock = 10;
const int loudKnock = 100;//设置敲击次数的范围
boolean locked = false;//利用布尔运算来初始化伺服的状态
int numberOfKnocks = 0;
void setup() {
  // put your setup code here, to run once:
myServo.attach(9);
pinMode(yellowLed, OUTPUT);
pinMode(redLed, OUTPUT);
pinMode(greenLed, OUTPUT);
pinMode(switchPin, INPUT);
Serial.begin(9600);
digitalWrite(greenLed, HIGH);
myServo.write(0);
Serial.print("The box is unlocked!");//定义引脚输入输出状态及初始化伺服位置为0
}

void loop() {
  // put your main code here, to run repeatedly:
if(locked == false){
  switchVal = digitalRead(switchPin);
  if(switchVal == HIGH){
    locked = true;
    digitalWrite(greenLed, LOW);
    digitalWrite(redLed, HIGH);
    myServo.write(90);
    Serial.println("The box is locked");//初始状态下按下开关，盒子上锁，绿灯灭，红灯亮，串口显示盒子上锁
    delay(1000);
  }
}
if(locked == true){
  knockVal = analogRead(piezo);
  if(numberOfKnocks < 3 && knockVal >0){
    if(checkForKnock(knockVal) == true){
      numberOfKnocks++;
    }
    Serial.print(3-numberOfKnocks);
    Serial.println("more knocks to go");//判断是否有敲击值输入，并通过判断语句统计敲击数量
  }
  if(numberOfKnocks >= 3){
    locked = false;
    myServo.write(0);
    delay(20);
    digitalWrite(greenLed, HIGH);
    digitalWrite(redLed, LOW);
    Serial.println("The box is unlocked");//当敲击数量达到3时解锁
  }
}
}
boolean checkForKnock(int value){//定义一个函数来判断敲击是否有效
  if(value > quietKnock && value < loudKnock){
    digitalWrite(yellowLed, HIGH);
    delay(50);
    digitalWrite(yellowLed, LOW);
    Serial.print("Valid knock of value");
    Serial.println(value);
    return true;
  }
  else{
    Serial.print("Bad knock value");
    Serial.println(value);
    return true;
  }
}
