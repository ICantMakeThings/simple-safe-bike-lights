#include <NeoPixelBus.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <cstdint>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C // 0x3D, 0x3C
#define PIXEL_COUNT 16 // this example assumes 4 pixels, making it smaller will cause a failure
#define PIXEL_PIN 9 // make sure to set this to the correct pin, ignored for Esp8266
#define COLOR_SATURATION 128
#define LEFT 2
#define RIGHT 3
#define BREAK 10


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
// three element pixels, in different order and speeds
NeoPixelBus<NeoGrbFeature, NeoWs2812xMethod> strip(PIXEL_COUNT, PIXEL_PIN);
// NeoPixelBus<NeoRgbFeature, Neo400KbpsMethod> strip(PIXEL_COUNT, PIXEL_PIN);

RgbColor red(COLOR_SATURATION, 0, 0);
RgbColor green(0, COLOR_SATURATION, 0);
RgbColor blue(0, 0, COLOR_SATURATION);
RgbColor redish(10, 0, 0);
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


void default_state(){

	for (uint16_t i = 0; i <= 15; i++) {
		strip.SetPixelColor(i, redish);
	}
	strip.Show();
}

void all_off(){
	for (uint16_t i = 0; i <= 15; i++) {
		strip.SetPixelColor(i, black);
	}
	strip.Show();
}

void righen(){
	for (uint16_t i = 8; i <= 15; i++) {
		strip.SetPixelColor(i, amber);
		delay(100);
		strip.Show();
	}
	default_state();
}

void leften(){
	for (uint16_t i = 7; i >= 0; i--) {
		strip.SetPixelColor(i, amber);
		delay(100);
		strip.Show();
	}
	default_state();
}

void breaken(){
	for (uint16_t i = 0; i <= 15; i++) {
		strip.SetPixelColor(i, red);
		strip.SetPixelColor(15-i, red);
		delay(100);
		strip.Show();
	}
	default_state();
}


void setup()
{
	Wire.begin(6, 7);
	display.begin(SSD1306_SWITCHCAPVCC);
	display.clearDisplay();
	display.drawPixel(10, 10, SSD1306_WHITE);
	display.display();

	pinMode(LEFT, INPUT_PULLUP);
	pinMode(RIGHT, INPUT_PULLUP);
	pinMode(BREAK, INPUT_PULLUP);
	digitalWrite(LEFT, HIGH);
	digitalWrite(RIGHT, HIGH);
	digitalWrite(BREAK, HIGH);

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
	   display.display(); // Show initial text
	   */

	default_state();

	if (digitalRead(RIGHT) == 0) {
		righen();
	}

	if (digitalRead(LEFT) == 0) {
		leften();
	}

	if (digitalRead(BREAK) == 0) {
		breaken();
	}

	delay(10);
}
