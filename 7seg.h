#ifndef _7SEG_H_
#define _7SEG_H_

#include "led.h"

#include <inttypes.h>

typedef struct SeteSeg SeteSeg;

struct SeteSeg
{
  Led * segs[8];
  char cathod;
};

SeteSeg * seteSeg_create (char initPort, char isCathod, char isOn);
void seteSeg_clean (SeteSeg * my7Seg);
void seteSeg_print (SeteSeg * my7Seg, char pattern[]);
void seteSeg_print_hex (SeteSeg * my7Seg, int hex);
void seteSeg_set_dot (SeteSeg * my7Seg, char isOn);
void seteSeg_destroy (SeteSeg * myLed);

#endif

