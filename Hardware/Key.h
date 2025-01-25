#ifndef __KEY_H
#define __KEY_H

#define KEY1_PIN GPIO_Pin_0
#define KEY2_PIN GPIO_Pin_1

void KEY_GPIO_CONFIG(void);

uint8_t KEY1_GetNum(void);
uint8_t KEY2_GetNum(void);

#endif
