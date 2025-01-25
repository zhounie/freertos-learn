#ifndef __LED_H
#define __LED_H

#define LED1_PIN GPIO_Pin_0

#define LED2_PIN GPIO_Pin_1

void LED_GPIO_CONFIG(void);

void LED1_ON(void);

void LED1_OFF(void);

void LED2_ON(void);

void LED2_OFF(void);
#endif
