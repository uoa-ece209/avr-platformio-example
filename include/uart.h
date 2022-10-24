#ifndef UART_H
#define UART_H

#include <avr/io.h>
#include <stdint.h>

/**
 * @brief initialise the UART peripheral.
 *
 * @param baud baud rate to use.
 */
void uart_init(uint32_t baud);

/**
 * @brief transmit a byte of data over UART, blocking until the data has
 * transferred.
 *
 * @param data data to transfer.
 */
void uart_transmit(uint8_t data);

#endif