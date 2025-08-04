#include "global.h"

#define LED_DEBUG_PIN   14

int32_t SYS_ERROR_NUM;

void SYS_Fatal_Error(int32_t err) {
  DDRB |= 0x20;
  PORTB |= 0x20;
  for(;;);
}

void SYS_Init(void) {
  if(GPIO_Init() != GPIO_SUCCESS) SYS_Fatal_Error();
  if(GPIO_Write(LED_DEBUG_PIN, GPIO_OUTPUT) != GPIO_SUCCESS) SYS_Fatal_Error();
  if(GPIO_Mode(LED_DEBUG_PIN, GPIO_OUTPUT) != GPIO_SUCCESS) SYS_Fatal_Error();
  // GPIO_Init();
  // GPIO_Mode(LED_DEBUG_PIN, GPIO_OUTPUT);
}


int main(void) {
  volatile uint32_t delay;

  for(;;) {
    GPIO_Write(LED_DEBUG_PIN, GPIO_HIGH);
    for (delay = 0; delay < 100000; delay++);
    GPIO_Write(LED_DEBUG_PIN, GPIO_LOW);
    for (delay = 0; delay < 100000; delay++);
  }
}