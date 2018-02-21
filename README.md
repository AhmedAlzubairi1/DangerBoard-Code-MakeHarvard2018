# DangerBoard-Code-MakeHarvard2018
This is the code for the DangerBoard, a long board my team created that detects incoming objects and warns the rider by causing the LEDs on the side of the long board that the impact is expected to occur to flicker red. The board and code was created in MakeHarvard 2018.


My team had 4 members. One member created the 3d printed holdings for the ultra sonic sensors, another member created the code (lcd.h) that controled how the lcd stips light up, and another team mate was working on the accelometer. The intended purpose of the accelometer was to use it to show the velocity of the rider, but we couldn't get that working. I was the one that created the main code. I used the lcd.h provided to me from my teammate and created code that controled when and which LCD strips changge colors (Blue,Green, or blinking red) depending on the readings detected from the 2 ultrasonic sensors used as well as whether or not the board in in motion. Since we couldn't get the velocity to be displayed, we sticked with just utalizing the info of the status of the board, whether it is moving or not.
