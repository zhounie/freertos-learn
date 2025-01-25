#include "stm32f10x.h"                  // Device header
#include "Led.h"

void LED_GPIO_CONFIG(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = LED1_PIN | LED2_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_SetBits(GPIOB, LED1_PIN);
	GPIO_SetBits(GPIOB, LED2_PIN);
}

void LED1_ON(void)
{
	GPIO_ResetBits(GPIOB, LED1_PIN);
}

void LED1_OFF(void)
{
	GPIO_SetBits(GPIOB, LED1_PIN);
}

void LED2_ON(void)
{
	GPIO_ResetBits(GPIOB, LED2_PIN);
}

void LED2_OFF(void)
{
	GPIO_SetBits(GPIOB, LED2_PIN);
}
