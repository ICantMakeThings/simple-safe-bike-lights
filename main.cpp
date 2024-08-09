/////////////////////////////////////////////////////////
///////////  simple-safe-bike-lights  //////////////////
///////////////////////////////////////////////////////
///// OSHW PL000018 ////// CC-BY-SA-4.0 //////////////
/////////////////////////////////////////////////////


#include <NeoPixelBus.h>
//#include <Wire.h>
//#include <Adafruit_GFX.h>
//#include <Adafruit_SSD1306.h>
#include <cstdint>

#define FLOODLIGHT 10
#define PIXEL_PIN 1

#define LEFT 5
#define RIGHT 6
#define BREAK 7
#define FLDIN 8

#define LED_MATRIX_HEIGHT 4
#define LED_MATRIX_WIDTH 12

/////// OLED MAY BE ADDED, or not.

/*
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C // 0x3D, 0x3C
*/

#define PIXEL_COUNT 48 // this example assumes 4 pixels, making it smaller will cause a failure
#define COLOR_SATURATION 255


//Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// three element pixels, in different order and speeds
NeoPixelBus<NeoGrbFeature, NeoWs2812xMethod> strip(PIXEL_COUNT, PIXEL_PIN);
// NeoPixelBus<NeoRgbFeature, Neo400KbpsMethod> strip(PIXEL_COUNT, PIXEL_PIN);

RgbColor red(COLOR_SATURATION, 0, 0);
RgbColor green(0, COLOR_SATURATION, 0);
RgbColor blue(0, 0, COLOR_SATURATION);
RgbColor redish(20, 0, 0);
RgbColor black(0);
RgbColor amber(255, 85, 0);
RgbColor bem(3, 9, 33);

HslColor hslRed(red);
HslColor hslGreen(green);
HslColor hslBlue(blue);
HslColor hslRedish(redish);
HslColor hslBlack(black);
HslColor hslamber(amber);
HslColor hslbem(bem);


void default_state(){

	for (uint16_t i = 0; i < 48; i++) {
		strip.SetPixelColor(i, redish);
	}
	strip.Show();
	delay(200);
	for (uint16_t i = 0; i < 48; i++) {
		strip.SetPixelColor(i, black);
	}
	strip.Show();	
	delay(200);
}

void all_off(){
	for (uint16_t i = 0; i < 48; i++) {
		strip.SetPixelColor(i, black);
	}
	strip.Show();
}

void righen(){
	for (uint16_t i = LED_MATRIX_WIDTH/2; i < LED_MATRIX_WIDTH; i++) {
		for (uint16_t j = 0; j < LED_MATRIX_HEIGHT; j++) {
			strip.SetPixelColor(i+j, amber);
		}
		delay(100);
		strip.Show();
	}
}

void leften(){
	for (uint16_t i = LED_MATRIX_WIDTH/2; i < LED_MATRIX_WIDTH; i++) {
		for (uint16_t j = 0; j < LED_MATRIX_HEIGHT; j++) {
			strip.SetPixelColor((LED_MATRIX_WIDTH*LED_MATRIX_HEIGHT)-(i+j), amber);
		}
		delay(100);
		strip.Show();
	}
}

void breaken(){
	for (uint16_t i = LED_MATRIX_WIDTH/2; i < LED_MATRIX_WIDTH; i++) {
		for (uint16_t j = 0; j < LED_MATRIX_HEIGHT; j++) {
			strip.SetPixelColor(i+j, red);
			strip.SetPixelColor((LED_MATRIX_WIDTH*LED_MATRIX_HEIGHT)-(i+j), red);
		}
		delay(100);
		strip.Show();
	}
}

void floodlighten(){
	digitalWrite(FLOODLIGHT, HIGH);
}
void floodlightenoff(){
	digitalWrite(FLOODLIGHT, LOW);
}

void setup()
{
	/*
	Wire.begin(6, 7);
	display.begin(SSD1306_SWITCHCAPVCC);
	display.clearDisplay();
	display.drawPixel(10, 10, SSD1306_WHITE);
	display.display();
	*/

	pinMode(LEFT, INPUT_PULLUP);
	pinMode(RIGHT, INPUT_PULLUP);
	pinMode(BREAK, INPUT_PULLUP);
	pinMode(FLOODLIGHT, OUTPUT);
	pinMode(FLDIN, INPUT_PULLUP);
	digitalWrite(LEFT, HIGH);
	digitalWrite(RIGHT, HIGH);
	digitalWrite(BREAK, HIGH);
	digitalWrite(FLDIN, HIGH);
	digitalWrite(FLOODLIGHT, LOW);

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

	if (digitalRead(FLDIN) == 0) {
		floodlighten();
	} else {
		floodlightenoff();
	}

	delay(10);
}
