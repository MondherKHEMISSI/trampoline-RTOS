#include "tp_ups.h"
#include "tpl_os.h"

#define APP_Task_a_task_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{
  initBoard(BUTTON_NOIT);
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

DeclareTask(task_0);
DeclareTask(task_1);

TASK(a_task)
{
  while (readButton() != BUTTON_PRESSED);
  ledOn(LED3);
  delay(1000);
  while (readButton() != BUTTON_PRESSED);
  ActivateTask(task_0);
  delay(1000);
  while (readButton() != BUTTON_PRESSED);
  ActivateTask(task_1);
  delay(1000);
  while (readButton() != BUTTON_PRESSED);
  ledOn(LED6);
  delay(1000);
  while (readButton() != BUTTON_PRESSED);
  
  StatusType error = ActivateTask(task_0);
  
  if (error == E_OS_ID)
	ledOff(LED4);
  if (error == E_OS_RESOURCE)
	ledOff(LED5);
  if (error == E_OS_CALLEVEL)
	ledOff(LED6);
 if (error == E_OS_LIMIT)
	ledOff(LED3);
 TerminateTask();
  
  /*
  while(1){
  StatusType error = ChainTask(task_0);
  
  if (error == E_OS_ID)
	ledOff(LED3);
  if (error == E_OS_RESOURCE)
	ledOff(LED5);
  if (error == E_OS_CALLEVEL)
	ledOff(LED6);
 if (error == E_OS_LIMIT)
	ledOff(LED4);
}
*/
 
}
#define APP_Task_a_task_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_task_0_START_SEC_CODE
#include "tpl_memmap.h"
TASK(task_0)
{
  ledToggle(LED4);
  TerminateTask();
}
#define APP_Task_task_0_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_task_1_START_SEC_CODE
#include "tpl_memmap.h"
TASK(task_1)
{
  ledToggle(LED5);
  TerminateTask();
}
#define APP_Task_task_1_STOP_SEC_CODE
#include "tpl_memmap.h"

/*
 * This is necessary for ST libraries
 */
#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(void, OS_CODE) assert_failed(uint8_t* file, uint32_t line)
{
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

