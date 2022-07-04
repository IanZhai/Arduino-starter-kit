int notes[] = {262,294,330,349};//定义一个四个整数组成的数组
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);//打开串口9600
}

void loop() {
  // put your main code here, to run repeatedly:
int keyVal = analogRead(A0);//定义键位，读取A0的值
Serial.println(keyVal);
if(keyVal == 1023){
  tone(8, notes[0]);
}//如果键位值为1023，输出频率1
else if(keyVal >= 990 && keyVal <= 1010){
  tone(8, notes[1]);
}//如果键位值在990和1010之间，输出频率2
else if(keyVal >= 505 && keyVal <=515){
  tone(8, notes[2]);
}//如果键位值在505和515之间，输出频率3
else if(keyVal >= 5 && keyVal <= 10) {
  tone(8, notes[3]);
}//如果键位值在5和10之间，输出频率4
else{
  noTone(8);//否则没有输出
}
}
