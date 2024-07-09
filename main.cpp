/////////////////////////////////////////////////////////
///////////  simple-safe-bike-lights  //////////////////
///////////////////////////////////////////////////////
///// OSHW PL000018 ////// CC-BY-SA-4.0 //////////////
/////////////////////////////////////////////////////


#include <NeoPixelBus.h>
#include <cstdint>

#define FLOODLIGHT 10
#define PIXEL_PIN 1

#define LEFT 5
#define RIGHT 6
#define BREAK 7
#define FLDIN 8

#define PIXEL_COUNT 16 // this example assumes 4 pixels, making it smaller will cause a failure
#define COLOR_SATURATION 128

NeoPixelBus<NeoGrbFeature, NeoWs2812xMethod> strip(PIXEL_COUNT, PIXEL_PIN);

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
HslColor hslRedish(redish);
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
}

void leften(){
	for (uint16_t i = 8; i <= 15; i++) {
		strip.SetPixelColor(15-i, amber);
		delay(100);
		strip.Show();
	}
}

void breaken(){
	for (uint16_t i = 0; i <= 7; i++) {
		strip.SetPixelColor(i, red);
		strip.SetPixelColor(15-i, red);
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
