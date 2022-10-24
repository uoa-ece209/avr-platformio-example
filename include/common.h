#ifndef COMMON_H
#define COMMON_H

/**
 * @brief tell the compiler that a parameter is deliberately unused
 */
#define UNUSED_PARAM(x) ((void)(x))

/**
 * @brief put a pin on PORTB into output mode
 */
#define PINB_OUT(p) DDRB |= (1 << (p))

/**
 * @brief set a pin on PORTB to HIGH
 */
#define PINB_ON(p) PORTB |= (1 << (p))

/**
 * @brief set a pin on PORTB to LOW
 */
#define PINB_OFF(p) PORTB &= ~(1 << (p))

#endif