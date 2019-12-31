
#include "MicroBit.h"

MicroBit uBit;

int main()
{
    // Initialise the micro:bit runtime.
    uBit.init();
    uBit.display.setBrightness(32); //max brightness

    uBit.display.scroll("Hello world!");

    // Insert your code here!
    //uBit.display.scroll("1+1==2");
    //uBit.display.scroll("2+2==4");
    //uBit.display.scroll("4+4==8");
    //uBit.display.scroll("8+8==16");
    //uBit.display.scroll("16+16==32");
    //uBit.display.scroll("32+32==64");
    //uBit.display.scroll("64+64==128");
    //uBit.display.scroll("128+128==256");

    // show your smiley on the screen...
    uBit.display.setBrightness(16); //max brightness

    MicroBitImage smiley("0,32,0,32, 0\n0,255,0,255,0\n0,0,0,0,0\n255,0,0,0,255\n0,255,255,255,0\n");
    for (int y=4; y >= 0; y--) {
        uBit.display.setBrightness((256 - 64*y)); //max brightness
        uBit.display.image.paste(smiley,0,y);
        uBit.sleep(500);
    }

    // If main exits, there may still be other fibers running or registered event handlers etc.
    // Simply release this fiber, which will mean we enter the scheduler. Worse case, we then
    // sit in the idle task forever, in a power efficient sleep.
    release_fiber();
}

