#include <stdio.h>

#include <avr/io.h>
#include <util/delay.h>

#include "uart.h"

#define LED PB5

#define PIN_OUT(p) DDRB |= (1 << (p))
#define PIN_ON(p) PORTB |= (1 << (p))
#define PIN_OFF(p) PORTB &= ~(1 << (p))

int main(void) {
  uart_init(9600);
  PIN_OUT(LED);

  while (1) {
    printf("on!\n");
    PIN_ON(LED);
    _delay_ms(1000);

    printf("off!\n");
    PIN_OFF(LED);
    _delay_ms(1000);
  }
}
