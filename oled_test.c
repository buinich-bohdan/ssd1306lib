#define F_CPU 16000000UL

#include "oled.h"
#include <avr/io.h>


int main()
{
  /* output by letter? (not related to lib) */
  bool byletter = false;

  sei();
  OLED oled;
  uint8_t fb[1024] = {0};
  OLED_init(&oled, 128, 64, fb, 200000, 0b0111100);

  /* Try to decrease frequency and see what happens without lock */
  OLED_WITH_SPINLOCK(&oled) {
    OLED_put_rectangle(&oled, 0, 0, 127, 63, OLED_FILL | 0);
    OLED_put_rectangle(&oled, 2, 2, 125, 61, OLED_FILL | 1);
    OLED_put_rectangle(&oled, 4, 4, 123, 57, 0);
  }
  if (byletter) OLED_refresh(&oled);
    OLED_WITH_SPINLOCK(&oled) {
    OLED_put_roundRect(&oled, 10, 10, 40, 20, 5, OLED_FILL | 0 );
    OLED_put_roundRect(&oled, 14, 14, 90, 25, 7, 0);
    //OLED_put_line(&oled,10, 10, 120, 25, OLED_FILL | 0 );
    }
    OLED_refresh(&oled);

  while (1) {
  }
}