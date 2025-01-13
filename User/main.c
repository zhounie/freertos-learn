#include "stm32f10x.h"                  // Device header
#include "FreeRTOS.h"
#include "task.h"


static void BSP_Init(void);

int main(void)	
{
	
	BSP_Init();
	while(1){
	
	}
}

static void LED_Task(void)
{
	while(1)
	{
		
	}
}


static void BSP_Init(void)
{
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	
	
}