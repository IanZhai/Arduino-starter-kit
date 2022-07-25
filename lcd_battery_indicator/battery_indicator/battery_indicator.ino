#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
float rawV = 0.0;
int batC =0;
int graph = 0;
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
lcd.clear();
}
void loop(){
  // put your main code here, to run repeatedly:
rawV = analogRead(A0)*5/1024;
if(rawV < 3.6){
  batC = 0;
  graph = 0;
}
if(rawV > 3.5 && rawV < 3.7){
  batC = 2;
  graph = 1;
}
if(rawV > 3.6 && rawV < 3.8){
  batC = 12;
  graph = 4;
}
if(rawV > 3.7 && rawV < 3.9){
  batC = 42;
  graph = 7;
}
if(rawV > 3.8 && rawV < 4.0){
  batC = 62;
  graph = 10;
}
if(rawV > 3.9 && rawV < 4.1){
  batC = 79;
  graph = 13;
}
if(rawV > 4.0 && rawV < 4.2){
  batC = 81;
  graph = 15;
}
if(rawV > 4.19){
  batC = 100;
  graph = 16;
}
lcd.setCursor(0,0);
lcd.print("V:");
lcd.setCursor(3,0);
lcd.print(rawV);
lcd.setCursor(10,0);
lcd.print("%:");
lcd.setCursor(13,0);
lcd.print(batC);
lcd.setCursor(0,1);
for(int m = 0; m < graph; m ++){
  lcd.write(255);
}
delay(1000);
lcd.clear();


}
