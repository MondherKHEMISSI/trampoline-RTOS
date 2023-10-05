/**
 * @file AsMemMap.h
 *
 * @section desc File description
 *
 * Memory mapping using Metrowerks CodeWarrior pragmas
 * Memory Mapping of Application lab1
 * Automatically generated by goil on Wed Oct  4 15:34:44 2023
 * from root OIL file lab5.oil
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#define MEMMAP_ERROR

/*=============================================================================
 * OS memory mapping
 *
 * Code section
 */
#ifdef OS_START_SEC_CODE
  #undef OS_START_SEC_CODE
  #ifdef CURRENT_LINKER_CODE_SECTION
    #error "Starting a .osCode section while a section is already started"
  #else
    #undef MEMMAP_ERROR
.section .osCode, "ax"
    #define CURRENT_LINKER_CODE_SECTION
  #endif
#endif

#ifdef OS_STOP_SEC_CODE
  #undef OS_STOP_SEC_CODE
  #ifdef CURRENT_LINKER_CODE_SECTION
    #undef MEMMAP_ERROR
    #undef CURRENT_LINKER_CODE_SECTION
  #else
    #error "No section .osCode started"
  #endif
#endif

#ifdef OS_START_SEC_VECTBL
  #undef OS_START_SEC_VECTBL
  #ifdef CURRENT_LINKER_CODE_SECTION
    #error "Starting a .vectbl section while a section is already started"
  #else
    #undef MEMMAP_ERROR
.section .vectbl, "ax"
    #define CURRENT_LINKER_CODE_SECTION
  #endif
#endif

#ifdef OS_STOP_SEC_VECTBL
  #undef OS_STOP_SEC_VECTBL
  #ifdef CURRENT_LINKER_CODE_SECTION
    #undef MEMMAP_ERROR
    #undef CURRENT_LINKER_CODE_SECTION
  #else
    #error "No section .vectbl started"
  #endif
#endif

#ifdef OS_START_SEC_VAR
  #undef OS_START_SEC_VAR
  #ifdef CURRENT_LINKER_DATA_SECTION
    #error "Starting a .osVar data section while a section is already started"
  #else
    #undef MEMMAP_ERROR
.section .osVar, "aw"
    #define CURRENT_LINKER_DATA_SECTION
  #endif
#endif
#ifdef OS_STOP_SEC_VAR
  #undef OS_STOP_SEC_VAR
  #ifdef CURRENT_LINKER_DATA_SECTION
    #undef MEMMAP_ERROR
    #undef CURRENT_LINKER_DATA_SECTION
  #else
    #error "No section started"
  #endif
#endif

/*
 * Const, Calibration, Carto, Configuration data sections
 */
#ifdef OS_START_SEC_CONST
  #undef OS_START_SEC_CONST
  #ifdef CURRENT_LINKER_DATA_SECTION
    #error "Starting a .osConst data section while a section is already started"
  #else
    #undef MEMMAP_ERROR
.section .osConst, "a"
    #define CURRENT_LINKER_DATA_SECTION
  #endif
#endif

#ifdef OS_STOP_SEC_CONST
  #undef OS_STOP_SEC_CONST
  #ifdef CURRENT_LINKER_DATA_SECTION
    #undef MEMMAP_ERROR
    #undef CURRENT_LINKER_DATA_SECTION
  #else
    #error "No section started"
  #endif
#endif

#ifdef OS_START_SEC_STACKS
  #undef OS_START_SEC_STACKS
  #ifdef CURRENT_LINKER_DATA_SECTION
    #error "Starting a .stacks data section while a section is already started"
  #else
    #undef MEMMAP_ERROR
.section .stacks, "aw"
    #define CURRENT_LINKER_DATA_SECTION
  #endif
#endif

#ifdef OS_STOP_SEC_STACKS
  #undef OS_STOP_SEC_STACKS
  #ifdef CURRENT_LINKER_DATA_SECTION
    #undef MEMMAP_ERROR
    #undef CURRENT_LINKER_DATA_SECTION
  #else
    #error "No section started"
  #endif
#endif


/* .ltorg */
#ifdef OS_START_LTORG
  #undef OS_START_LTORG
  #ifdef CURRENT_LINKER_LTORG
    #error "Starting a .ltorg section while one is already started"
  #else
    #undef MEMMAP_ERROR
.ltorg
    #define CURRENT_LINKER_LTORG
  #endif
#endif

#ifdef OS_STOP_LTORG
  #undef OS_STOP_LTORG
  #ifdef CURRENT_LINKER_LTORG
    #undef MEMMAP_ERROR
    #undef CURRENT_LINKER_LTORG
  #else
    #error "No .ltorg started"
  #endif
#endif

#ifdef OS_START_SEC_TEXT
  #undef OS_START_SEC_TEXT
  #ifdef CURRENT_LINKER_CODE_SECTION
    #error "Starting a .text section while a section is already started"
  #else
    #undef MEMMAP_ERROR
.text
    #define CURRENT_LINKER_CODE_SECTION
  #endif
#endif

#ifdef OS_STOP_SEC_TEXT
  #undef OS_STOP_SEC_TEXT
  #ifdef CURRENT_LINKER_CODE_SECTION
    #undef MEMMAP_ERROR
    #undef CURRENT_LINKER_CODE_SECTION
  #else
    #error "No section .text started"
  #endif
#endif

#ifdef API_START_SEC_CODE
  #undef API_START_SEC_CODE
  #ifdef CURRENT_LINKER_CODE_SECTION
    #error "Starting a .osApiCode section while a section is already started"
  #else
    #undef MEMMAP_ERROR
    #undef CURRENT_LINKER_CODE_SECTION_NAME
.section .osApiCode, "ax"
    #define CURRENT_LINKER_CODE_SECTION
  #endif
#endif

#ifdef API_STOP_SEC_CODE
  #undef API_STOP_SEC_CODE
  #ifdef CURRENT_LINKER_CODE_SECTION
    #undef MEMMAP_ERROR
    #undef CURRENT_LINKER_CODE_SECTION
  #else
    #error "No section .osApiCode started"
  #endif
#endif

#ifdef API_START_SEC_CONST_UNSPECIFIED
  #undef API_START_SEC_CONST_UNSPECIFIED
  #ifdef CURRENT_LINKER_DATA_SECTION
    #error "Starting a .osApiConst section while a section is already started"
  #else
    #undef MEMMAP_ERROR
.section .osApiConst, "a"
    #define CURRENT_LINKER_DATA_SECTION
  #endif
#endif

#ifdef API_STOP_SEC_CONST_UNSPECIFIED
  #undef API_STOP_SEC_CONST_UNSPECIFIED
  #ifdef CURRENT_LINKER_DATA_SECTION
    #undef MEMMAP_ERROR
    #undef CURRENT_LINKER_DATA_SECTION
  #else
    #error "No section .osApiConst started"
  #endif
#endif

#ifdef MEMMAP_ERROR
  #error "MemMap.h, wrong section command"
#endif

