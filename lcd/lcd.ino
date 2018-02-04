#include "lcd.h"

const int colorR = 255;
const int colorG = 0;
const int colorB = 0;

void setup() 
{
    // set up the LCD's number of columns and rows:
    lcd_setup();
    
    lcd_set_color(colorR, colorG, colorB);
    
    // Print a message to the LCD.
    lcd_print("hello starshine,");
    lcd_move_cursor(0,1);
    lcd_print("Earth says hello");
}

void loop() 
{
  
}
