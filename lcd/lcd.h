#ifndef LED_H
#define LED_H

#include "rgb_lcd.h"

rgb_lcd lcd;

void lcd_setup() {
  lcd.begin(16,2);
}

// if I had time, and cared, I would unify this with the led colors
void lcd_set_color(uint8_t red, uint8_t green, uint8_t blue) {
  lcd.setRGB(red, green, blue);
}

void lcd_print(char* msg) {
  lcd.print(msg);
}

void lcd_move_cursor(uint8_t col, uint8_t row) {
  lcd.setCursor(col, row);
}

#endif
