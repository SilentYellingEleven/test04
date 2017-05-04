### code1 音乐
/*------------音符对应蜂鸣器频率------------*/

#define B0  31
#define C1  33
#define CS1 35
#define D1  37
#define DS1 39
#define E1  41
#define F1  44
#define FS1 46
#define G1  49
#define GS1 52
#define A1  55
#define AS1 58
#define B1  62
#define C2  65
#define CS2 69
#define D2  73
#define DS2 78
#define E2  82
#define F2  87
#define FS2 93
#define G2  98
#define GS2 104
#define A2  110
#define AS2 117
#define B2  123
#define C3  131
#define CS3 139
#define D3  147
#define DS3 156
#define E3  165
#define F3  175
#define FS3 185
#define G3  196
#define GS3 208
#define A3  220
#define AS3 233
#define B3  247
#define C4  262
#define CS4 277
#define D4  294
#define DS4 311
#define E4  330
#define F4  349
#define FS4 370
#define G4  392
#define GS4 415
#define A4  440
#define AS4 466
#define B4  494
#define C5  523
#define CS5 554
#define D5  587
#define DS5 622
#define E5  659
#define F5  698
#define FS5 740
#define G5  784
#define GS5 831
#define A5  880
#define AS5 932
#define B5  988
#define C6  1047
#define CS6 1109
#define D6  1175
#define DS6 1245
#define E6  1319
#define F6  1397
#define FS6 1480
#define G6  1568
#define GS6 1661
#define A6  1760
#define AS6 1865
#define B6  1976
#define C7  2093
#define CS7 2217
#define D7  2349
#define DS7 2489
#define E7  2637
#define F7  2794
#define FS7 2960
#define G7  3136
#define GS7 3322
#define A7  3520
#define AS7 3729
#define B7  3951
#define C8  4186
#define CS8 4435
#define D8  4699
#define DS8 4978

#define buzzer_pin 10 //定义蜂鸣器引脚

/*------------定义歌曲音调的数组------------*/

int notes[] = {
A4, C5, E5, C5, A4, C5,A4,C5,A4,C5,A4,C5,E5,D5,E5,C5,A4
};

/*------------定义歌曲节奏的数组------------*/

byte beats[] = {
400, 300, 100, 200, 200, 800, 200, 200, 200, 200, 200, 600, 200, 200, 200, 200, 600
};

void setup() {
pinMode(buzzer_pin, OUTPUT); //定义蜂鸣器引脚为输出状态
}

void loop() {
for ( int i = 0; i < 17; i++) {

/*------------设置i在歌曲长度内递增，这样就能逐一执行数组中的数据------------*/

tone(buzzer_pin, notes[i]); //播放音乐
delay(beats[i]); //播放间隔

noTone(buzzer_pin);
delay(10);
}
}


### code2 光声控等
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





## THE RECORD OF DOING XXX

这是一个小的灯光报警装置，当灯光不足时会以闪灯的方式提示您要开启灯光




### How to do

利用microduino提供的模块，具体使用的是core、usb、插线板、led＊2、触碰开关和光敏传感器



### How to use

点击触碰开关开启，此时光不足会闪光报警
再点击触碰开关则关闭

### code

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
ColorLED.setPixelColor(0, ColorLED.Color(0, 0, 0)); //关灯
ColorLED.setPixelColor(1, ColorLED.Color(0, 0, 0)); 
ColorLED.show();  //显示彩灯效果
} } else {
ColorLED.setPixelColor(0, ColorLED.Color(0, 0, 0)); //关灯
ColorLED.setPixelColor(1, ColorLED.Color(0, 0, 0));
ColorLED.show();  //显示彩灯效果
}
delay(15);
}


### pictures
