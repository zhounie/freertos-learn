#include "stm32f10x.h"                  // Device header
#include "Key.h"
#include "Delay.h"
#include "Usart.h"


void KEY_GPIO_CONFIG(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = KEY1_PIN | KEY2_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

uint8_t KEY1_GetNum(void)
{
	uint8_t num = 0;
	if (GPIO_ReadInputDataBit(GPIOA, KEY1_PIN) == 0)
	{

		num = 1;
	}
	return num;
}

uint8_t KEY2_GetNum(void)
{
	uint8_t num = 0;
	if (GPIO_ReadInputDataBit(GPIOA, KEY2_PIN) == 0)
	{
		num = 1;
	}
	return num;
}
