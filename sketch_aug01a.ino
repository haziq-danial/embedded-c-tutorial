#include "global.h"

#define LED_DEBUG_PIN   20
#define SYS_Error_Check(x)  if(( SYS_ERROR_NUM = (x)) != 0) SYS_Fatal_Error(SYS_ERROR_NUM)

int32_t SYS_ERROR_NUM;

void SYS_Fatal_Error(int32_t err) {
  DDRB |= 0x20;
  PORTB |= 0x20;
  Serial.println(err);
  for(;;);
}

void SYS_Init(void) {
  Serial.begin(9600);

  SYS_Error_Check(GPIO_Init());
  SYS_Error_Check(GPIO_Write(LED_DEBUG_PIN, GPIO_OUTPUT));
  SYS_Error_Check(GPIO_Mode(LED_DEBUG_PIN, GPIO_OUTPUT));

  SYS_ERROR_NUM = GPIO_Init();
  if(SYS_ERROR_NUM != GPIO_SUCCESS) SYS_Fatal_Error(SYS_ERROR_NUM);

}


int main(void) {
  volatile uint32_t delay;

  SYS_Init();

  for(;;) {
    GPIO_Write(LED_DEBUG_PIN, GPIO_HIGH);
    for (delay = 0; delay < 100000; delay++);
    GPIO_Write(LED_DEBUG_PIN, GPIO_LOW);
    for (delay = 0; delay < 100000; delay++);
  }
}