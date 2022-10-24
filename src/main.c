#include <stdio.h>

#include <avr/io.h>
#include <util/delay.h>

#include "common.h"
#include "uart.h"

/**
 * @brief LED on the xplained mini board
 */
#define LED PB5

int main(void) {
  uart_init(9600);
  PINB_OUT(LED);

  while (1) {
    printf("on!\n");
    PINB_ON(LED);
    _delay_ms(1000);

    printf("off!\n");
    PINB_OFF(LED);
    _delay_ms(1000);
  }
}
