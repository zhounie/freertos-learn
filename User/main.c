#include "stm32f10x.h"                  // Device header
#include "FreeRTOS.h"
#include "task.h"
#include "Led.h"
#include "Key.h"
#include "Usart.h"
#include "Delay.h"
#include "stdio.h"

static TaskHandle_t AppTaskCreate_Handle = NULL;
static TaskHandle_t LED1_Task_Handle = NULL;
static TaskHandle_t LED2_Task_Handle = NULL;
static TaskHandle_t KEY1_Task_Handle = NULL;
static TaskHandle_t KEY2_Task_Handle = NULL;

static void BSP_Init(void);
static void AppTaskCreate(void * pvParameters);
static void LED1_Task(void);
static void LED2_Task(void);
static void KEY1_Task(void);
static void KEY2_Task(void);

int main(void)	
{
	
	BaseType_t xReturn = pdPASS;
	
	BSP_Init();

	xReturn = xTaskCreate(
		(TaskFunction_t)AppTaskCreate,
		"AppTaskCreate",
		128,
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

static void AppTaskCreate(void * pvParameters)
{
	taskENTER_CRITICAL();

	xTaskCreate(
		(TaskFunction_t)LED1_Task,
		"LED1_Task",
		128,
		NULL,
		4,
		&LED1_Task_Handle
	);
	
	xTaskCreate(
		(TaskFunction_t)LED2_Task,
		"LED2_Task",
		128,
		NULL,
		4,
		&LED2_Task_Handle
	);
	
	xTaskCreate(
		(TaskFunction_t)KEY1_Task,
		"KEY1_Task",
		128,
		NULL,
		4,
		&KEY1_Task_Handle
	);
	
	xTaskCreate(
		(TaskFunction_t)KEY2_Task,
		"KEY2_Task",
		128,
		NULL,
		4,
		&KEY2_Task_Handle
	);
	
	vTaskDelete(NULL);
	
	taskEXIT_CRITICAL();
}

static void LED1_Task(void)
{
	while(1)
	{
		LED1_ON();
		vTaskDelay(500);
		LED1_OFF();
		vTaskDelay(500);
	}
}

static void LED2_Task(void)
{
	while(1)
	{
		LED2_ON();
		vTaskDelay(500);
		LED2_OFF();
		vTaskDelay(500);
	}
}

static void KEY1_Task(void)
{
	while(1)
	{
		if (KEY1_GetNum() == 1) {
			vTaskSuspend(LED1_Task_Handle);
			vTaskSuspend(LED2_Task_Handle);
		}
	}
}

static void KEY2_Task(void)
{
	while(1)
	{
		if (KEY2_GetNum() == 1) {
			vTaskResume(LED2_Task_Handle);
			vTaskResume(LED1_Task_Handle);
		}
	}
}

static void BSP_Init(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	
	LED_GPIO_CONFIG();
	
	KEY_GPIO_CONFIG();
	
	USART_Config();
}
