#include <Adafruit_NeoPixel.h>  //调用LED彩灯的库文件
#include <Microduino_Key.h> //调用开关的库文件

Key KeyA(6, INPUT_PULLUP); //定义开关参数
Adafruit_NeoPixel ColorLED = Adafruit_NeoPixel(2, 8, NEO_GRB + NEO_KHZ800);
//定义彩灯引脚以及数量

boolean sta = false; //定义布尔变量为假
int state; //定义一个整数变量state

void setup()
{
  ColorLED.begin();
  pinMode(A0, INPUT); //设置光敏传感器引脚为输入状态
  Serial.begin(9600); //设置串口波特率为9600
  pinMode(6, INPUT); //设置开关引脚为输入状态
}
void loop()
{
   if (KeyA.read()==SHORT_PRESS) { //当读取到开关按下时
    sta = !sta; //反转布尔变量值
  }
  if (sta) { //当布尔变量为真时
  state = analogRead(A0);
  Serial.print("state:");
  Serial.println(state);
  delay(100);
  if (state < 299) { //当state的值小于50时，亮红灯
 
  ColorLED.setPixelColor(0, ColorLED.Color(250, 66, 0));  //设置彩灯颜色为红色
  
  ColorLED.setPixelColor(1, ColorLED.Color(111, 99, 0));  //设置彩灯颜色为绿色
 
  ColorLED.show();  //显示彩灯效果
  delay(500);  //保持1秒(1000毫秒)

  ColorLED.setPixelColor(1, ColorLED.Color(0, 255, 0));  //设置彩灯颜色为红色
  
  ColorLED.setPixelColor(0, ColorLED.Color(0, 77, 233));  //设置彩灯颜色为红色

  ColorLED.show();  //显示彩灯效果
  delay(500);  //保持1秒(1000毫秒)
  } else { //否则，关灯
    ColorLED.setPixelColor(0, ColorLED.Color(0, 0, 0)); 
    ColorLED.setPixelColor(1, ColorLED.Color(0, 0, 0)); //设置彩灯颜色为红色
    ColorLED.show();  //显示彩灯效果
  } } else {
    ColorLED.setPixelColor(0, ColorLED.Color(0, 0, 0)); //关灯
    ColorLED.setPixelColor(1, ColorLED.Color(0, 0, 0));
    ColorLED.show();  //显示彩灯效果
  }
  delay(15);
}

