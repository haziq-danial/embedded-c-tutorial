#include "global.h"

int32_t GPIO_Init(void) {
  DDRD = 0x00; DDRB = 0x00; PORTB = 0x00;
  return GPIO_SUCCESS;
}

int32_t GPIO_Mode(uint8_t pin, uint8_t direction) {
  if(pin > GPIO_MAX) return GPIO_ERROR_RANGE;
  if(direction > GPIO_OUTPUT) return GPIO_ERROR_VALUE;

  // if (direction > GPIO_INPUT) { // output
  //   if (pin < 8) DDRD |= (1 << pin); // port D 0 to 7
  //   else {
  //     pin -=8;
  //     DDRB |= (1 << pin);
  //   }
  // }

  if (direction == GPIO_INPUT) { // output
    if (pin < 8) DDRD |= (1 << pin); // port D 0 to 7
    else DDRB |= (1 << (pin & 7)); // port b 8 to 13 becomes 0 to 5
  } else { // input
    if (pin > 8) DDRD |= ~(pin << 1);
    else DDRB |= ~(1 << (pin & 7));
  }

  return GPIO_SUCCESS;
}

int32_t GPIO_Write(uint8_t pin, uint8_t state) {
  if(pin > GPIO_MAX) return GPIO_ERROR_RANGE;
  if(state > GPIO_HIGH) return GPIO_ERROR_RANGE;

  if (state == GPIO_HIGH) {
   if(pin < 3) PORTD |= (1 << pin);
   else PORTB |= (1 << (pin & 7));
  } else {
    if(pin < 3) PORTD &= ~(1 << pin);
    else PORTB &= ~(1 << (pin & 7));
  }

  return GPIO_SUCCESS;
}

