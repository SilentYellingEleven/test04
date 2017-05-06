#include <Adafruit_NeoPixel.h>  //调用LED彩灯的库文件

Adafruit_NeoPixel ColorLED = Adafruit_NeoPixel(1, 8, NEO_GRB + NEO_KHZ800);
//定义彩灯引脚以及数量

int sta; //定义一个整数变量state
int state; //定义一个整数变量state

void setup() {
  Serial.begin(9600); //设置串口波特率为9600
  pinMode(A0, INPUT); //设置MIC传感器引脚为输入状态
  pinMode(A2, INPUT); //设置光敏传感器引脚为输入状态
  ColorLED.begin(); //设置彩灯初始状态
}

void loop() {
  sta = analogRead(A0); //将LIGHT传感器引脚的值赋给变量sta
  Serial.print("Light:"); //在串口监视器里打印文字 sta：
  Serial.println(sta); //在串口监视器里打印变量sta的值，并换行
  state = analogRead(A2);//将MIC传感器引脚的值赋给变量state
  Serial.print("MIC:");
  Serial.println(state);
  delay(100); //延时100毫秒打印
 if (sta < 50) { //当state的值小于50时
 if (state > 200) { //当sta的值大于200时，亮红灯
   
    ColorLED.setPixelColor(0, ColorLED.Color(255, 0, 0)); //亮红灯
    ColorLED.show();  //显示彩灯效果
  }
else { //否则，关灯
    ColorLED.setPixelColor(0, ColorLED.Color(0, 0, 0));  //关灯
    ColorLED.show();  //显示彩灯效果
  }
  } else { //否则关灯
    ColorLED.setPixelColor(0, ColorLED.Color(0, 0, 0));  //关灯
    ColorLED.show(); //显示彩灯效果
  }

}
