const int switchPin = 8;//定义倾斜开关为8号引脚；
unsigned long previousTime = 0;//定义长字节之前的时间；
int switchState = 0;//开关状态为0；
int prevSwitchState = 0;//之前开关状态为0；
int led = 2;//定义2号引脚为led输出；
long interval = 6000;//定义间隔时间600000ms；

void setup() {
  for(int x = 2;x<8;x++){
  pinMode(x, OUTPUT);
}//定义2-7号引脚为led输出；
pinMode(switchPin, INPUT);//定义倾斜开关为输入；
}

void loop() {
  unsigned long currentTime = millis();//定义实时时间；
if(currentTime - previousTime > interval){
  previousTime = currentTime;
  digitalWrite(led, HIGH);
  led++;
  if(led == 7){
    
  }
}
switchState = digitalRead(switchPin);
if(switchPin != prevSwitchState){
  for(int x = 2;x<8;x++){
    digitalWrite(x,LOW);
  }
  led = 2;
  previousTime = currentTime;
}
prevSwitchState = switchState;
}
