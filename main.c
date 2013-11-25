#include <avr/io.h>
#include <util/delay.h>
#include "7seg.h"

#include <inttypes.h>

int main (void)
{
  SeteSeg * seg;

  char on = 0;
  seg = seteSeg_create (6, 0, on);
  int hex = 0x10;
  while (1) 
    {
      for (int i = hex; i >= 0; i--)
	{
	  on = !on;
	  seteSeg_set_dot (seg, on);
	  seteSeg_print_hex (seg, i);
	  _delay_ms (1000);
	}
      seteSeg_clean (seg);
      _delay_ms (1000);
    }
  
  seteSeg_destroy( seg );
  
  return 0;
}
