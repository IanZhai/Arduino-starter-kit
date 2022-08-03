#include<LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 11, 12);
int timer1;
int timer2;
float Time;

float distance = 5.0;
float speed;

int ir_s1 = A0;
int ir_s2 = A1;

void setup() {
  // put your setup code here, to run once:
pinMode(ir_s1, INPUT);
pinMode(ir_s2, INPUT);
lcd.begin(16, 2);

}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(ir_s1) == LOW){
  timer1 = millis();
}
if(digitalRead(ir_s2) == LOW){
  timer2 = millis();
}
Time = timer2 - timer1;
Time = Time/3600000;//trans ms to h;
speed = (distance/Time);//v=d/t;
if(speed == 0){
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("No Car");
}
else{
  lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Speed:");
lcd.print(speed);
lcd.print("Km/Hr");
}

}
