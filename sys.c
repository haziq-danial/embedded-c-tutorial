#include "global.h"

int32_t SYS_ERROR_NUM;

void SYS_Fatal_Error(int32_t err) {
  DDRB |= 0x20;
  PORTB |= 0x20;
  for(;;);
}

uint32_t SYS_Init(void) {
  SYS_Error_Check(GPIO_Init());
  SYS_Error_Check(GPIO_Write(LED_DEBUG_PIN, GPIO_OUTPUT));
  SYS_Error_Check(GPIO_Mode(LED_DEBUG_PIN, GPIO_OUTPUT));

  return SYS_SUCCESS;
}