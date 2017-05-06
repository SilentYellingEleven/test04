#include <Adafruit_NeoPixel.h>  //调用LED彩灯的库文件

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
  E4, G4, D5, C5, G4, F4,
  E4, G4, G4, A4, B4, C5, C5,
  D5, G4, B4, A4, G4, E4, G4, C5,
  A4, C5, D5, C5, B4, G4,
  E4, G4, D5, C5, G4, F4,
  E4, G4, G4, A4, B4, C5, C5,
};

/*------------定义歌曲节奏的数组------------*/

int beats[] = {
6000, 3000, 9000, 6000, 3000, 9000,
6000, 3000, 3000, 3000, 3000, 9000, 9000,
6000, 3000, 3000, 3000, 3000, 6000, 3000, 9000,
6000, 3000, 6000, 3000, 9000, 9000,
6000, 3000, 9000, 6000, 3000, 9000,
6000, 3000, 3000, 3000, 3000, 9000, 9000,
};
Adafruit_NeoPixel ColorLED = Adafruit_NeoPixel(2, 8, NEO_GRB + NEO_KHZ800); 
//定义彩灯引脚以及数量
int i; //定义整数变量i

void setup() {
  pinMode(buzzer_pin, OUTPUT); //定义蜂鸣器引脚为输出状态
  ColorLED.begin();  //设置彩灯初始状态
}

void loop() {
  for ( int i = 0; i < 40; i++) {

/*------------设置i在歌曲长度内递增，这样就能逐一执行数组中的数据------------*/

    tone(buzzer_pin, notes[i]); //播放音乐
    delay(beats[i]/10); //播放间隔

    noTone(buzzer_pin);
    delay(100);

/*------------设置i令LED灯呼吸亮光------------*/
    if (i % 3 == 0) {
      ColorLED.setPixelColor(0, ColorLED.Color(255, 0, 0)); 
      ColorLED.setPixelColor(0, ColorLED.Color(0, 255, 0));//彩灯变化
      ColorLED.show(); //显示彩灯效果
    }
    if (i % 3 == 1) {
      ColorLED.setPixelColor(0, ColorLED.Color(0, 255, 0)); 
      ColorLED.setPixelColor(0, ColorLED.Color(0, 0, 255));//彩灯变化
      ColorLED.show(); //显示彩灯效果
    }
    if (i % 3 == 2) {
      ColorLED.setPixelColor(0, ColorLED.Color(0, 0, 255)); 
      ColorLED.setPixelColor(0, ColorLED.Color(255, 0, 0));//彩灯变化
      ColorLED.show(); //显示彩灯效果
    }

  }
}
