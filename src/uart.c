#include "uart.h"

#include <avr/io.h>
#include <stdarg.h>
#include <stdio.h>

static int uart_debug_printf(char c, FILE *stream) {
  uart_transmit((uint8_t)c);
  return 0;
}

static FILE uart_stdout =
    FDEV_SETUP_STREAM(uart_debug_printf, NULL, _FDEV_SETUP_WRITE);

void uart_init(uint32_t baud) {
  stdout = &uart_stdout;

  UCSR0B |= (1 << TXEN0); // Enable UART transmitter
  UBRR0 = (F_CPU / ((uint32_t)16 * baud)) -
          1; // Calculate UBRR0 value and set baud rate
}

void uart_transmit(uint8_t data) {
  // Wait for the data buffer to be empty
  while ((UCSR0A & (1 << UDRE0)) == 0)
    ;

  UDR0 = data;
}
