#include "stm32f10x.h"                  // Device header
#include "Led.h"

void LED_GPIO_CONFIG(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitStructure.GPIO_Pin = LED_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_SetBits(GPIOB, LED_PIN);
}

void LED_ON(void)
{
	GPIO_ResetBits(GPIOB, LED_PIN);
}

void LED_OFF(void)
{
	GPIO_SetBits(GPIOB, LED_PIN);
}
