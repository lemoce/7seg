#ifndef _LED_H_
#define _LED_H_

#include <inttypes.h>

typedef struct Led Led;

struct Led
{
  volatile uint8_t * port;
  volatile uint8_t * ddr_port;
  uint8_t pin;
  char isOn;
};

Led * led_create (int numPort, char isOn);
void led_on (Led * myLed);
void led_off (Led * myLed);
void led_toogle (Led * myLed);
void led_destroy (Led * myLed);

#endif

