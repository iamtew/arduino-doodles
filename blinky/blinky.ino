/*
 * blinky.ino - Just do some blinky stuff!
 */

#include "LedControl.h"

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

int numDevices = 1;
int Intensity = 0; // Intensity between 0 to 15

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
	const int intDelay = 20;
  int xoff = 160;
  int yoff = 100;

  int x,y,z,k;
  for (int z=50; z<100; z++)
  {
    for (int x=0; x<8; x++)
    {
      for (int y=0; y<8; y++)
      {
        k = ((x + xoff) * (y + yoff) / z) % 2;
        if (k == 1)
        {
          lc.setLed(0, x, y, true);
        } else {
          lc.setLed(0, x, y, false);
        }
        // printf(" %d", k);
      }
      delay(intDelay);
      // printf("\n");
    }
  }
  loop();
}



