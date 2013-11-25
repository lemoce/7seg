#include "7seg.h"
#include <avr/io.h>
#include <stdlib.h>
#include <inttypes.h>
#include "led.h"

static char seven_hex_digits[16][7] =
  {
    { 1,1,1,1,1,1,0 },  
    { 0,1,1,0,0,0,0 },  
    { 1,1,0,1,1,0,1 },
    { 1,1,1,1,0,0,1 }, 
    { 0,1,1,0,0,1,1 }, 
    { 1,0,1,1,0,1,1 },
    { 1,0,1,1,1,1,1 },
    { 1,1,1,0,0,0,0 },
    { 1,1,1,1,1,1,1 },
    { 1,1,1,0,0,1,1 },
    { 1,1,1,0,1,1,1 },
    { 0,0,1,1,1,1,1 },
    { 1,0,0,1,1,1,0 },
    { 0,1,1,1,1,0,1 },
    { 1,0,0,1,1,1,1 },
    { 1,0,0,0,1,1,1 }

  };

static char seven_clean[7] = 
  { 0,0,0,0,0,0,0 };

static char error[7] = 
  { 1,0,0,1,0,0,0 };


SeteSeg * seteSeg_create (char initPort, char isCathod, char isOn)
{
  SeteSeg * my7Seg = (SeteSeg *) malloc (sizeof(SeteSeg));

  for (int i = 0; i < 8; i++) 
    {
      my7Seg->segs[i] = led_create (initPort+i,(isCathod)?isOn:!isOn);
    }

  my7Seg->cathod = isCathod;

  return my7Seg;
}

void seteSeg_set_seg (SeteSeg * my7Seg, int i, char isOn)
{
  if ((my7Seg->cathod)?isOn:!isOn)
    led_on (my7Seg->segs[i]);
  else
    led_off (my7Seg->segs[i]);
}

void seteSeg_print (SeteSeg * my7Seg, char pattern[])
{
  for (int i = 0; i<7; i++)
    {
      seteSeg_set_seg (my7Seg, i, pattern[i]);
    }
}

void seteSeg_clean (SeteSeg * my7Seg) 
{
  seteSeg_print (my7Seg, seven_clean);
}

void seteSeg_print_hex (SeteSeg * my7Seg, int hex) 
{
  if (hex > 0xf || hex < 0x0)
    {
      seteSeg_print (my7Seg, error);
    }
  else
    {
      seteSeg_print (my7Seg, seven_hex_digits[hex]);
    }
}

void seteSeg_set_dot (SeteSeg * my7Seg, char isOn)
{
  seteSeg_set_seg (my7Seg, 7, isOn);
}

void seteSeg_destroy (SeteSeg * my7Seg)
{
  for (int i = 0; i<8; i++) 
    {
      led_destroy (my7Seg->segs[i]);
    }
  free (my7Seg);
}
