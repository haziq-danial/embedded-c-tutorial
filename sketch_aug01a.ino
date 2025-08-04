#include "global.h"

#define LED_DEBUG_PIN   14

int32_t SYS_ERROR_NUM;

void SYS_Fatal_Error(int32_t err) {
  DDRB |= 0x20;
  PORTB |= 0x20;
  for(;;);
}

void SYS_Init(void) {
  SYS_ERROR_NUM = GPIO_Init();
  if(SYS_ERROR_NUM != GPIO_SUCCESS) SYS_Fatal_Error(SYS_ERROR_NUM);

  // if(GPIO_Init() != GPIO_SUCCESS) SYS_Fatal_Error();

  if((SYS_ERROR_NUM = GPIO_Write(LED_DEBUG_PIN, GPIO_OUTPUT)) != GPIO_SUCCESS) SYS_Fatal_Error(SYS_ERROR_NUM);
  if((SYS_ERROR_NUM = GPIO_Mode(LED_DEBUG_PIN, GPIO_OUTPUT)) != GPIO_SUCCESS) SYS_Fatal_Error(SYS_ERROR_NUM);
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