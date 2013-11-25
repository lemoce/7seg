#include "led.h"
#include <avr/io.h>
#include <stdlib.h>
#include <inttypes.h>

static volatile uint8_t * ports[2] = 
  {
    &PORTD,
    &PORTB
  };

static volatile uint8_t pin[14] = 
  {
    DDD0,
    DDD1,
    DDD2,
    DDD3,
    DDD4,
    DDD5,
    DDD6,
    DDD7,
    DDB0,
    DDB1,
    DDB2,
    DDB3,
    DDB4,
    DDB5
  }; 

Led * led_create (int numPort, char isOn)
{
  Led * led = (Led *) malloc (sizeof(Led));
  
  led->port = ports[numPort / 8];
  led->ddr_port = led->port - 1;
  *(led->ddr_port) |= _BV (pin[numPort]);
  led->pin = pin[numPort];
  led->isOn = isOn;
  
  if (isOn) 
    led_on (led);
  else
    led_off (led);

  return led;
}

void led_on (Led * myLed) 
{
  *(myLed->port) |= _BV (myLed->pin);
}

void led_off (Led * myLed)
{
  *(myLed->port) &= ~_BV (myLed->pin);
}

void led_toggle (Led * myLed) 
{
  myLed->isOn = (myLed->isOn)? 0: 1;
  if (myLed->isOn) 
    led_on (myLed);
  else
    led_off (myLed);
}

void led_destroy (Led * myLed)
{
  free (myLed);
}
