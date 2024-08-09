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

	for (uint16_t i = 0; i <= 47; i++) {
		strip.SetPixelColor(i, redish);
	}
	strip.Show();
	delay(200);
	for (uint16_t i = 0; i <= 47; i++) {
		strip.SetPixelColor(i, black);
	}
	strip.Show();	
	delay(200);
}

void all_off(){
	for (uint16_t i = 0; i <= 47; i++) {
		strip.SetPixelColor(i, black);
	}
	strip.Show();
}

void righen(){
		strip.SetPixelColor(24, amber);
		strip.SetPixelColor(25, amber);
		strip.SetPixelColor(26, amber);
		strip.SetPixelColor(27, amber);
		delay(100);
		strip.Show();
		strip.SetPixelColor(28, amber);
		strip.SetPixelColor(29, amber);
		strip.SetPixelColor(30, amber);
		strip.SetPixelColor(31, amber);
		delay(100);
		strip.Show();
		strip.SetPixelColor(32, amber);
		strip.SetPixelColor(33, amber);
		strip.SetPixelColor(34, amber);
		strip.SetPixelColor(35, amber);
		delay(100);
		strip.Show();
		strip.SetPixelColor(36, amber);
		strip.SetPixelColor(37, amber);
		strip.SetPixelColor(38, amber);
		strip.SetPixelColor(39, amber);
		delay(100);
		strip.Show();
		strip.SetPixelColor(40, amber);
		strip.SetPixelColor(41, amber);
		strip.SetPixelColor(42, amber);
		strip.SetPixelColor(43, amber);
		delay(100);
		strip.Show();
		strip.SetPixelColor(44, amber);
		strip.SetPixelColor(45, amber);
		strip.SetPixelColor(46, amber);
		strip.SetPixelColor(47, amber);
		delay(100);
		strip.Show();
		delay(100);
}

void leften(){

		strip.SetPixelColor(23, amber);
		strip.SetPixelColor(22, amber);
		strip.SetPixelColor(21, amber);
		strip.SetPixelColor(20, amber);
		delay(100);
		strip.Show();
		strip.SetPixelColor(19, amber);
		strip.SetPixelColor(18, amber);
		strip.SetPixelColor(17, amber);
		strip.SetPixelColor(16, amber);
		delay(100);
		strip.Show();
		strip.SetPixelColor(15, amber);
		strip.SetPixelColor(14, amber);
		strip.SetPixelColor(13, amber);
		strip.SetPixelColor(12, amber);
		delay(100);
		strip.Show();
		strip.SetPixelColor(11, amber);
		strip.SetPixelColor(10, amber);
		strip.SetPixelColor(9, amber);
		strip.SetPixelColor(8, amber);
		delay(100);
		strip.Show();
		strip.SetPixelColor(7, amber);
		strip.SetPixelColor(6, amber);
		strip.SetPixelColor(5, amber);
		strip.SetPixelColor(4, amber);
		delay(100);
		strip.Show();
		strip.SetPixelColor(3, amber);
		strip.SetPixelColor(2, amber);
		strip.SetPixelColor(1, amber);
		strip.SetPixelColor(0, amber);
		delay(100);
		strip.Show();
		delay(100);
}

void breaken(){
		strip.SetPixelColor(24, red);
		strip.SetPixelColor(25, red);
		strip.SetPixelColor(26, red);
		strip.SetPixelColor(27, red);
		strip.SetPixelColor(23, red);
		strip.SetPixelColor(22, red);
		strip.SetPixelColor(21, red);
		strip.SetPixelColor(20, red);
		delay(100);
		strip.Show();
		strip.SetPixelColor(28, red);
		strip.SetPixelColor(29, red);
		strip.SetPixelColor(30, red);
		strip.SetPixelColor(31, red);
		strip.SetPixelColor(19, red);
		strip.SetPixelColor(18, red);
		strip.SetPixelColor(17, red);
		strip.SetPixelColor(16, red);
		delay(100);
		strip.Show();
		strip.SetPixelColor(32, red);
		strip.SetPixelColor(33, red);
		strip.SetPixelColor(34, red);
		strip.SetPixelColor(35, red);
		strip.SetPixelColor(15, red);
		strip.SetPixelColor(14, red);
		strip.SetPixelColor(13, red);
		strip.SetPixelColor(12, red);
		delay(100);
		strip.Show();
		strip.SetPixelColor(36, red);
		strip.SetPixelColor(37, red);
		strip.SetPixelColor(38, red);
		strip.SetPixelColor(39, red);
		strip.SetPixelColor(11, red);
		strip.SetPixelColor(10, red);
		strip.SetPixelColor(9, red);
		strip.SetPixelColor(8, red);
		delay(100);
		strip.Show();
		strip.SetPixelColor(40, red);
		strip.SetPixelColor(41, red);
		strip.SetPixelColor(42, red);
		strip.SetPixelColor(43, red);
		strip.SetPixelColor(7, red);
		strip.SetPixelColor(6, red);
		strip.SetPixelColor(5, red);
		strip.SetPixelColor(4, red);
		delay(100);
		strip.Show();
		strip.SetPixelColor(44, red);
		strip.SetPixelColor(45, red);
		strip.SetPixelColor(46, red);
		strip.SetPixelColor(47, red);
		strip.SetPixelColor(3, red);
		strip.SetPixelColor(2, red);
		strip.SetPixelColor(1, red);
		strip.SetPixelColor(0, red);
		delay(100);
		strip.Show();
		delay(100);
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
