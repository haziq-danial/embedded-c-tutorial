#include "global.h"

int main(void) {
  volatile uint32_t delay;

  SYS_Error_Check(SYS_Init());

  for(;;) {
    SYS_Error_Check(GPIO_Write(LED_DEBUG_PIN, GPIO_HIGH));
    for (delay = 0; delay < 100000; delay++);
    SYS_Error_Check(GPIO_Write(LED_DEBUG_PIN, GPIO_LOW));
    for (delay = 0; delay < 100000; delay++);
  }
}