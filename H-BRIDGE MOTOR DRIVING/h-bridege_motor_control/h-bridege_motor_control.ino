const int controlPin1 = 2;//定义一号控制引脚为2号口；
const int// controlPin2 = 3;//定义二号控制引脚为3号口；
const int enablePin = 9;//定义使能引脚为9号口；
const int directionSwitchPin = 4;//定义方向开关状态引脚为4号口；
const int onOffSwitchStatePin = 5;//定义开关状态引脚为5号口；
const int potPin = A0;//定义电位器引脚为A0；

int onOffSwitchState = 0;//定义开关状态为0；
int previousOnOffSwitchState = 0;//定义原来的开关状态为0；
int directionSwitchState = 0;//定义方向状态为0；
int previousDirectionSwitchState = 0;//定义原来的方向状态为0；

int motorEnabled = 0;//定义电机使能为0；
int motorSpeed = 0;//定义电机速度为0；
int motorDirection = 1;//定义电机方向为1；

void setup() {
  // put your setup code here, to run once:
pinMode(directionSwitchPin, INPUT);//方向状态引脚为输入；
pinMode(onOffSwitchStatePin, INPUT);//开关状态引脚为输入；
pinMode(controlPin1, OUTPUT);//控制引脚1为输出；
pinMode(controlPin2, OUTPUT);//控制引脚2为输出；
pinMode(enablePin, OUTPUT);//使能引脚为输出；

digitalWrite(enablePin, LOW);//使能引脚初始状态为0；


}

void loop() {
  // put your main code here, to run repeatedly:
onOffSwitchState = 
digitalRead(onOffSwitchStatePin);//读取开关状态；
delay(1);
directionSwitchState = 
digitalRead(directionSwitchPin);//读取方向状态；
motorSpeed = analogRead(potPin)/4;//读取转速；
if(onOffSwitchState != previousOnOffSwitchState){
  if(onOffSwitchState == HIGH){
    motorEnabled = !motorEnabled;
  }
}//判断开关状态；
if(directionSwitchState != 
previousDirectionSwitchState){
  if(directionSwitchState == HIGH){
    motorDirection = !motorDirection;
  }
}//判断方向状态；
if(motorDirection == 1){
  digitalWrite(controlPin1, HIGH);
  digitalWrite(controlPin2, LOW);
}
else{
  digitalWrite(controlPin1, LOW);
  digitalWrite(controlPin2, HIGH);
}//控制电机转动方向；
if(motorEnabled == 1){
  analogWrite(enablePin, motorSpeed);
}
else{
  analogWrite(enablePin, 0);
}//控制电机开关；

previousDirectionSwitchState = directionSwitchState;//将现在的方向状态赋值给原来的方向状态，准备下一个循环；
previousOnOffSwitchState = onOffSwitchState;//将现在的开关状态赋值给原来的方向状态，准备下一个循环；










}
