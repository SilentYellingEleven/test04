#include <Servo.h>  //调用舵机库文件
#include <Adafruit_NeoPixel.h>  //调用LED彩灯的库文件

#define mic_pin A0 //定义光敏传感器引脚为A0
#define Sev_Pin 6
#define PIN 8   //led灯控制引脚
#define PIN_NUM 2  //允许接的led灯的个数


Servo myservo;  //定义舵机名称
Adafruit_NeoPixel ColorLED = Adafruit_NeoPixel(2, 8, NEO_GRB + NEO_KHZ800);
//定义彩灯(8)引脚以及数量(2)
int state; //定义一个整数变量state


void setup() {
  Serial.begin(9600); //设置串口波特率为9600
  pinMode(mic_pin, INPUT); //设置声音传感器引脚为输入状态
  myservo.attach(Sev_Pin);  //设置舵机引脚
  ColorLED.begin();  //设置彩灯初始状态
}

void loop() {
  myservo.write(90);
  state = analogRead(mic_pin); //将光敏传感器引脚的值赋给变量state
  if (state > 361){
    state = 361;
  }
  Serial.print("Sound:"); //在串口监视器里打印文字 Sound：
  Serial.println(state); //在串口监视器里打印变量state的值，并换行
  delay(3000); //延时100毫秒打印
 if (state == 181) { //当sta的值大于200时，亮红灯
   
    ColorLED.setPixelColor(0, ColorLED.Color(0, 255, 0)); //正确控制音量,亮绿灯
    ColorLED.setPixelColor(1, ColorLED.Color(0, 255, 0)); 
    ColorLED.show();  //显示彩灯效果
    delay(1000);
  }
  else {
    if (state < 181) {
      ColorLED.setPixelColor(0, ColorLED.Color(0, 0, 255)); //音量太小,亮蓝灯
      ColorLED.setPixelColor(1, ColorLED.Color(0, 0, 255)); 
      myservo.write((181-state)/2);
      delay(500);
      myservo.write(90);
    }
    else {
      ColorLED.setPixelColor(0, ColorLED.Color(255, 0, 0)); //音量太小,亮红灯
      ColorLED.setPixelColor(1, ColorLED.Color(255, 0, 0)); 
      myservo.write((state-181)/2);
      delay(500);
      myservo.write(90);
    }
  }
}
