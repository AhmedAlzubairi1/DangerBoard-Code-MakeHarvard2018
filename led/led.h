// I don't have the capacity right now to figure out how this terrible IDE
// deals with compilation, so just don't include this header in more than
// one file b/c it'll throw multiple definition errors

#ifndef LED_H
#define LED_H

#include <Adafruit_NeoPixel.h>

#define LED_PIN 11
// split into 3 segments, 24-12-24
#define LED_COUNT 60

Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

struct color {
  uint8_t red;
  uint8_t green;
  uint8_t blue;
};
typedef color color_t;

void led_setup() {
  leds.begin();
  for( int i = 0; i < LED_COUNT; i++ ) {
    leds.setPixelColor(i, 0x000000);
  }
  leds.show();
  return;
}

void set_color(uint8_t start_led_index, uint8_t end_led_index, color_t color);
void flash_red(uint8_t start_led_index, uint8_t end_led_index, unsigned int flash_dur);

#define LEFT_START 0
#define LEFT_END 23
#define CENT_START 24
#define CENT_END 35
#define RIGHT_START 36
#define RIGHT_END 59

// convenience shortcuts to one of the specific strings
set_color_left(color_t color) {
  set_color(LEFT_START, LEFT_END, color);
  return;
}

set_color_center(color_t color) {
  set_color(CENT_START, CENT_END, color);
  return;
}

set_color_right(color_t color) {
  set_color(RIGHT_START, RIGHT_END, color);
  return;
}

void flash_red_left(unsigned int flash_dur) {
  flash_red(LEFT_START, LEFT_END, flash_dur);
  return;
}

void flash_red_center(unsigned int flash_dur) {
  flash_red(CENT_START, CENT_END, flash_dur);
  return;
}

void flash_red_right(unsigned int flash_dur) {
  flash_red(RIGHT_START, RIGHT_END, flash_dur);
  return;
}

/*  BELOW BE DRAGONS
 *  don't touch the stuff down here, it's hardware stuff with no application logic
 */

/* turns the specified LEDs the specified color
 * if the start is after the end, or either is past the end of the string, this won't do anything
 *  start_led_index: the beginning of the red string (as it would be passed to setPixelColor), inclusive
 *  end_led_index: the end of the red string (as it would be passed to setPixelColor), inclusive
 *  color: struct defining the new color
 */
void set_color(uint8_t start_led_index, uint8_t end_led_index, color_t color) {
  if( start_led_index < end_led_index && end_led_index < LED_COUNT ) {
    for( int i = start_led_index; i <= end_led_index; i++ ) {
      leds.setPixelColor(i, color.red, color.green, color.blue);
    }
    leds.show();
  }
  return;
}

/* turns the specified LEDs red for the specified amount of time
 * This blocks because, again, I do not have the capacity right now to think about a non-blocking implementation
 * if the start is after the end, or either is past the end of the string, this won't do anything
 *  start_led_index: the beginning of the red string (as it would be passed to setPixelColor), inclusive
 *  end_led_index: the end of the red string (as it would be passed to setPixelColor), inclusive
 *  flash_dur: length of time, in ms, that the LEDs stay red
 */
void flash_red(uint8_t start_led_index, uint8_t end_led_index, unsigned int flash_dur) {
  color_t red;
  red.red = 0xFF;
  red.green = 0x00;
  red.blue = 0x00;

  color_t off;
  off.red = 0x00;
  red.green = 0x00;
  red.blue = 0x00;
  
  set_color(start_led_index, end_led_index, red);
  delay(flash_dur);
  set_color(start_led_index, end_led_index, off);
  return;
}

#endif
