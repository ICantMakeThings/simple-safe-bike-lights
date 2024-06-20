
#include <NeoPixelBus.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     -1
#define SCREEN_ADDRESS 0x3C ///0x3D, 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const uint16_t PixelCount = 16; // this example assumes 4 pixels, making it smaller will cause a failure
const uint8_t PixelPin = 9;  // make sure to set this to the correct pin, ignored for Esp8266

#define colorSaturation 128

#define left 2
#define right 3
#define break 10
bool emo = 1;
bool emo1 = 1;
bool emo2 = 1;


// three element pixels, in different order and speeds
NeoPixelBus<NeoGrbFeature, NeoWs2812xMethod> strip(PixelCount, PixelPin);
//NeoPixelBus<NeoRgbFeature, Neo400KbpsMethod> strip(PixelCount, PixelPin);

RgbColor red(colorSaturation, 0, 0);
RgbColor green(0, colorSaturation, 0);
RgbColor blue(0, 0, colorSaturation);
RgbColor white(10, 0, 0);
RgbColor black(0);
RgbColor amber(255,191,0);
RgbColor bem(3, 9, 33);

HslColor hslRed(red);
HslColor hslGreen(green);
HslColor hslBlue(blue);
HslColor hslWhite(white);
HslColor hslBlack(black);
HslColor hslamber(amber);
HslColor hslbem(bem);


void default3(){


    strip.SetPixelColor(0, white);
    strip.SetPixelColor(1, white);
    strip.SetPixelColor(2, white);
    strip.SetPixelColor(3, white);
    strip.SetPixelColor(4, white);
    strip.SetPixelColor(5, white);
    strip.SetPixelColor(6, white);
    strip.SetPixelColor(7, white);
    strip.SetPixelColor(8, white);
    strip.SetPixelColor(9, white);
    strip.SetPixelColor(10, white);
    strip.SetPixelColor(11, white);
    strip.SetPixelColor(12, white);
    strip.SetPixelColor(13, white);
    strip.SetPixelColor(14, white);
    strip.SetPixelColor(15, white);
    strip.Show();
}

void alloff(){


    strip.SetPixelColor(0, black);
    strip.SetPixelColor(1, black);
    strip.SetPixelColor(2, black);
    strip.SetPixelColor(3, black);
    strip.SetPixelColor(4, black);
    strip.SetPixelColor(5, black);
    strip.SetPixelColor(6, black);
    strip.SetPixelColor(7, black);
    strip.SetPixelColor(8, black);
    strip.SetPixelColor(9, black);
    strip.SetPixelColor(10, black);
    strip.SetPixelColor(11, black);
    strip.SetPixelColor(12, black);
    strip.SetPixelColor(13, black);
    strip.SetPixelColor(14, black);
    strip.SetPixelColor(15, black);
    strip.Show();
}

void righen(){
    strip.SetPixelColor(8, amber);
    delay(100);
    strip.Show();
    strip.SetPixelColor(9, amber);
    delay(100);
    strip.Show();
    strip.SetPixelColor(10, amber);
    delay(100);
    strip.Show();
    strip.SetPixelColor(11, amber);
    delay(100);
    strip.Show();
    strip.SetPixelColor(12, amber);
    delay(100);
    strip.Show();
    strip.SetPixelColor(13, amber);
    delay(100);
    strip.Show();
    strip.SetPixelColor(14, amber);
    delay(100);
    strip.Show();
    strip.SetPixelColor(15, amber);
    delay(100);
    strip.Show();
}

void leften(){
    strip.SetPixelColor(7, amber);
    delay(100);
    strip.Show();
    strip.SetPixelColor(6, amber);
    delay(100);
    strip.Show();
    strip.SetPixelColor(5, amber);
    delay(100);
    strip.Show();
    strip.SetPixelColor(4, amber);
    delay(100);
    strip.Show();
    strip.SetPixelColor(3, amber);
    delay(100);
    strip.Show();
    strip.SetPixelColor(2, amber);
    delay(100);
    strip.Show();
    strip.SetPixelColor(1, amber);
    delay(100);
    strip.Show();
    strip.SetPixelColor(0, amber);
    delay(100);
    strip.Show();
}

void breaken(){

    delay(100);
    strip.SetPixelColor(0, red);
    strip.SetPixelColor(15, red);
    delay(100);
    strip.Show();
    strip.SetPixelColor(1, red);
    strip.SetPixelColor(14, red);
    delay(100);
    strip.Show();
    strip.SetPixelColor(2, red);
    strip.SetPixelColor(13, red);
    delay(100);
    strip.Show();
    strip.SetPixelColor(3, red);
    strip.SetPixelColor(12, red);
    delay(100);
    strip.Show();
    strip.SetPixelColor(4, red);
    strip.SetPixelColor(11, red);
    delay(100);
    strip.Show();
    strip.SetPixelColor(5, red);
    strip.SetPixelColor(10, red);
    delay(100);
    strip.Show();
    strip.SetPixelColor(6, red);
    strip.SetPixelColor(9, red);
    delay(100);
    strip.Show();
    strip.SetPixelColor(7, red);
    strip.SetPixelColor(8, red);
    delay(100);
    strip.Show();
}



void setup()
{
    Wire.begin(6, 7);
    display.begin(SSD1306_SWITCHCAPVCC);
    display.display();
    delay(2000); 
    display.clearDisplay();
    display.drawPixel(10, 10, SSD1306_WHITE);
    display.display();

    pinMode(left, INPUT_PULLUP);
    pinMode(right, INPUT_PULLUP);
    pinMode(break, INPUT_PULLUP);
    digitalWrite(left, HIGH);
    digitalWrite(right, HIGH);
    digitalWrite(break, HIGH);

    // this resets all the neopixels to an off state
    strip.Begin();
    strip.Show();

}


void loop()
{
/*
  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 0);
  display.println("scroll");
  display.display();      // Show initial text
*/
    delay(10);
    default3();

  emo = digitalRead(right);
  if (emo == 0){
    righen();
  }

  emo1 = digitalRead(left);
  if (emo1 == 0){
    leften();
  }

  emo2 = digitalRead(break);
  if (emo2 == 0){
    breaken();
  }


}
