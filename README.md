7seg
====

7seg and Led library for Arduino. You can feel free for use on your code. Profitable projects send to me a message about
the project and the company.


Introduction
------------

Library for 1-digit 7 segment display. Tested on Brasuino BS1 (same specs of Arduino) equipped with ATMega328.

RoadMap
-------

- proper documentation for users
- code documentation
- Abstraction for 4-digits 7 segment display.

Usage
-----

main.c

    int arduinoPort = 6; // Keep in mind I need 8 ports IO6 to IO13. (a,b,c,d,e,f,g,dp)
    char cathod = 0; //Anode 7 Seg display
    char on = 0;
    SeteSeg * seg = seteSeg_create (arduinoPort, cathod, on);
        
    seteSeg_set_dot (seg, on); // Decimal point dot
    seteSeg_print_hex (seg, 0xa); // Show "A" on display

Compile
-------

You will need avr-gcc package. Check Makefile, you can change processor.

    make clean && make
    
Load to Arduino
---------------

You must install avrdude and arduino package.

    make load
