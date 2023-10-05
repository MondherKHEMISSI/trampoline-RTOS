/**
 * @file tpl_app_interrupts.c
 *
 * @section descr File description
 *
 * Generated functions related to interrupts.
 *
 * Generated from application lab1
 * Automatically generated by goil on Wed Oct  4 15:34:44 2023
 * from root OIL file lab5.oil
 *
 * @section infos File informations
 *
 */

#include "tpl_compiler.h"
#include "tpl_cortex_definitions.h"
#include "tpl_os_interrupt_kernel.h"
#include "cmsis_wrapper.h"


#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*=============================================================================
 * Initialize the priorities in the NVIC according to the priorities defined
 * in the OIL/ARXML file
 */
FUNC(void, OS_CODE) tpl_init_it_priority(void)
{
}

/*=============================================================================
 * To disable the OS interrupts, the corresponding ICER
 * are set
 */
FUNC(void, OS_CODE) tpl_disable_os_interrupts(void)
{
}

/*=============================================================================
 * To enable the OS interrupts, the corresponding ISER
 * are set
 */
FUNC(void, OS_CODE) tpl_enable_os_interrupts(void)
{
}


#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_app_interrupts.c */