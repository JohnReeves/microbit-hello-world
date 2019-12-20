/*
The MIT License (MIT)

Copyright (c) 2016 British Broadcasting Corporation.
This software is provided by Lancaster University by arrangement with the BBC.

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

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

