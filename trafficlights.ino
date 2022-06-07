/*int REDLED1 = 3;
int GREENLED1 = 4;
int YELLOWLED1 = 5;
int REDLED2 = 6;
int GREENLED2 = 7;
int YELLOWLED2 = 8;//定义3-8号端口为红绿黄灯*/
void setup() {
  // put your setup code here, to run once:
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);//定义3-8号端口为输出
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(3,HIGH);
digitalWrite(4,LOW);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,HIGH);
digitalWrite(8,LOW);//红灯1亮5秒,绿灯2亮5秒
delay(5000);
digitalWrite(3,HIGH);
digitalWrite(4,LOW);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,HIGH);
delay(500);
digitalWrite(8,LOW);
delay(500);
digitalWrite(8,HIGH);
delay(500);
digitalWrite(8,LOW);
delay(500);
digitalWrite(8,HIGH);
delay(500);
digitalWrite(8,LOW);
delay(500);//红灯1保持亮，绿灯2熄灭，黄灯2闪烁三下
digitalWrite(3,LOW);
digitalWrite(4,HIGH);
digitalWrite(5,LOW);
digitalWrite(6,HIGH);
digitalWrite(7,LOW);
digitalWrite(8,LOW);
delay(5000);//绿灯1亮起，红灯2亮起，持续5秒
digitalWrite(3,LOW);
digitalWrite(4,LOW);
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
digitalWrite(7,LOW);
digitalWrite(8,LOW);
delay(500);
digitalWrite(5,LOW);
delay(500);
digitalWrite(5,HIGH);
delay(500);
digitalWrite(5,LOW);
delay(500);digitalWrite(5,HIGH);
delay(500);
digitalWrite(5,LOW);
delay(500);//绿灯1熄灭，红灯2保持亮，黄灯1闪烁三次



}
