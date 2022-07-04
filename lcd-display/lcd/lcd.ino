#include<LiquidCrystal.h>//调用lcd库功能
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);//定义lcd端口
const int switchPin = 6;//定义开关键6号口
int switchState = 0;//定义开关状态为0
int prevSwitchState = 0;//定义原来的开关状态为0
int reply;//定义答复
int counter;
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);//启动lcd，并定义屏幕大小
pinMode(switchPin,INPUT);//开关为输入
lcd.print("ASK THE");//显示文本
lcd.setCursor(0, 1);//移动光标位置到坐标（1，2）第一列第二行
lcd.print("Crystal Ball");//显示文本
counter = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
switchState = digitalRead(switchPin);//读取开关状态
if (switchState != prevSwitchState){//判断开关状态是否变化
  
  if (switchState == LOW){//如果开关状态发生变化且开关release，则执行下面随机选取答复
    counter ++;
    reply = random(8);//调用随机选取函数，并赋值给答复
    lcd.clear();//清空lcd内容
    lcd.setCursor(0,0);//移动光标到
    lcd.print("The ball says:");//显示文本
    lcd.print(counter);
    lcd.setCursor(0,1);//移动光标换行
    switch(reply){//调用case.switch函数，并执行random（8），执行以下8个动作中随机一个并中断。
      case 0:
      lcd.print("YES");
      break;
       case 1:
      lcd.print("Most likely");
      break;
       case 2:
      lcd.print("Certainly");
      break;
       case 3:
      lcd.print("Outlook good");
      break;
       case 4:
      lcd.print("Unsure");
      break;
       case 5:
      lcd.print("Ask again");
      break;
       case 6:
      lcd.print("Doubtful");
      break;
       case 7:
      lcd.print("No");
      break;
    }
  }
}
prevSwitchState = switchState;//将开关状态赋值给原来的开关状态
}
