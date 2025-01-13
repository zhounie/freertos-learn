#include "stm32f10x.h"                  // Device header
#include "FreeRTOS.h"
#include "task.h"
#include "Led.h"
#include "Usart.h"

static TaskHandle_t AppTaskCreate_Handle = NULL;
static TaskHandle_t LED_Task_Handle = NULL;


static void BSP_Init(void);
static void LED_Task(void);
static void AppTaskCreate(void);

int main(void)	
{
	
	BaseType_t xReturn = pdPASS;
	
	BSP_Init();
	
	printf("AAAa");
	
	xReturn = xTaskCreate(
		(TaskFunction_t)AppTaskCreate,
		"AppTaskCreate",
		512,
		NULL,
		1,
		&AppTaskCreate_Handle
	);
	
	if (pdPASS == xReturn) {
		vTaskStartScheduler();
	} else {
		return -1;
	}
	
	while(1);
}



static void AppTaskCreate(void)
{
	taskENTER_CRITICAL();
	
	xTaskCreate(
		(TaskFunction_t)LED_Task,
		"LED_Task",
		512,
		NULL,
		2,
		&LED_Task_Handle
	);
	
	vTaskDelete(AppTaskCreate_Handle);
	
	taskEXIT_CRITICAL();
}




static void LED_Task(void)
{
	while(1)
	{
		LED_ON();
		vTaskDelay(500);
		LED_OFF();
		vTaskDelay(500);
	}
}


static void BSP_Init(void)
{
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	
	LED_GPIO_CONFIG();
	
	USART_Config();
}
