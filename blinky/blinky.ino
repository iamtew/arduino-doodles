/*
 * blinky.ino - Just do some blinky stuff!
 */

#include "LedControl.h"

int Intensity = 2; // Intensity between 0 to 15
/*
 * Create a new controler
 * Params :
 * int dataPin    The pin on the Arduino where data gets shifted out
 * int clockPin   The pin for the clock
 * int csPin      The pin for selecting the device when data is to be sent
 * int numDevices The maximum number of devices that can be controled
*/
/* using VCC, GND, DIN 21, CS 21, CLK 5 for the MAX7219 */

// Baduino compatible
int dataPin = 10;
int clockPin = 12;
int csPin = 11;
int numDevices = 2;

LedControl lc=LedControl(dataPin, clockPin, csPin, numDevices);

void setup()
{
	int c;
	for (c = 0; c < numDevices; c++)
	{
  	lc.shutdown(c, false); // turn off power saving, enables display
  	lc.setIntensity(c, Intensity); // sets brightness (0~15 possible values)
  	lc.clearDisplay(c);    // clear screen
  }
}

void loop()
{
	const int intDelay = 25;

  for (int row=0; row<8; row++)
  {
    for (int col=0; col<8; col++)
    {
    	for (int d = 0; d < numDevices; d++)
    	{
    		if (d % 1)
    		{
      		lc.setLed(d, col,row,true); // turns on LED at col, row
      	} else {
      		lc.setLed(d, col,row,false); // turns on LED at col, row
      	}
      }
      delay(intDelay);
    }
  }

  for (int row=0; row<8; row++)
  {
    for (int col=0; col<8; col++)
    {
    	for (int d = 0; d < numDevices; d++)
    	{
    		if (d % 1)
    		{
      		lc.setLed(d, col,row,false); // turns on LED at col, row
      	} else {
      		lc.setLed(d, col,row,true); // turns on LED at col, row
      	}
      }
      delay(intDelay);
    }
  }
}

