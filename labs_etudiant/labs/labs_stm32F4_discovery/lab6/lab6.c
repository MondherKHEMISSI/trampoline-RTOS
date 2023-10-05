#include "tp_ups.h"
#include "tpl_os.h"

#define APP_Task_read_button_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{
  initBoard(BUTTON_NOIT);
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

TASK(read_button)
{
	TickRefType ticks;
	    WaitEvent(ev_0 | ev_1);
    GetEvent(a_task, &event_got);
    ClearEvent(event_got);
  
  if (readButton() == BUTTON_PRESSED) {
   if (event_got == NULL){
    	ActivateTask(Init);
	SetRelAlarm (blink_blink, 100 , 100);}
	
	//SetEvent(a_task, ev_0);
					
		}
		else
		{
			CancelAlarm (blink_blink);
			SetEvent(a_task, ev_1);
			ledOff(GREEN);
			//ActivateTask(Final);
		}
  }
	TerminateTask();
}

TASK(a_task)
{

  EventMaskType event_got;
  while(1)
  {
      
    WaitEvent(ev_0 | ev_1);
    GetEvent(a_task, &event_got);
    ClearEvent(event_got);
  
    if (event_got & ev_0)
    	ActivateTask(Init);
    	
    if (event_got & ev_1)
    	ActivateTask(Final);
    	
  }

  TerminateTask();
}

TASK(blink)
{

  ledToggle(GREEN);
  TerminateTask();
}

TASK(Init)
{

  ledOn(BLUE);
  delay(200);
  ledOff(BLUE);
  TerminateTask();
}

TASK(Final)
{

  ledOn(RED);
  delay(200);
  ledOff(RED);
  TerminateTask();
}
#define APP_Task_read_button_STOP_SEC_CODE
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*
 * This is necessary for ST libraries
 */
FUNC(void, OS_CODE) assert_failed(uint8_t* file, uint32_t line)
{
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

