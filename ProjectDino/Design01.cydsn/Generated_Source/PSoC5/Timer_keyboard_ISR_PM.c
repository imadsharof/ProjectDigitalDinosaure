/*******************************************************************************
* File Name: Timer_keyboard_ISR_PM.c
* Version 2.80
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "Timer_keyboard_ISR.h"

static Timer_keyboard_ISR_backupStruct Timer_keyboard_ISR_backup;


/*******************************************************************************
* Function Name: Timer_keyboard_ISR_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_keyboard_ISR_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Timer_keyboard_ISR_SaveConfig(void) 
{
    #if (!Timer_keyboard_ISR_UsingFixedFunction)
        Timer_keyboard_ISR_backup.TimerUdb = Timer_keyboard_ISR_ReadCounter();
        Timer_keyboard_ISR_backup.InterruptMaskValue = Timer_keyboard_ISR_STATUS_MASK;
        #if (Timer_keyboard_ISR_UsingHWCaptureCounter)
            Timer_keyboard_ISR_backup.TimerCaptureCounter = Timer_keyboard_ISR_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Timer_keyboard_ISR_UDB_CONTROL_REG_REMOVED)
            Timer_keyboard_ISR_backup.TimerControlRegister = Timer_keyboard_ISR_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Timer_keyboard_ISR_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_keyboard_ISR_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_keyboard_ISR_RestoreConfig(void) 
{   
    #if (!Timer_keyboard_ISR_UsingFixedFunction)

        Timer_keyboard_ISR_WriteCounter(Timer_keyboard_ISR_backup.TimerUdb);
        Timer_keyboard_ISR_STATUS_MASK =Timer_keyboard_ISR_backup.InterruptMaskValue;
        #if (Timer_keyboard_ISR_UsingHWCaptureCounter)
            Timer_keyboard_ISR_SetCaptureCount(Timer_keyboard_ISR_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Timer_keyboard_ISR_UDB_CONTROL_REG_REMOVED)
            Timer_keyboard_ISR_WriteControlRegister(Timer_keyboard_ISR_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Timer_keyboard_ISR_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_keyboard_ISR_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Timer_keyboard_ISR_Sleep(void) 
{
    #if(!Timer_keyboard_ISR_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Timer_keyboard_ISR_CTRL_ENABLE == (Timer_keyboard_ISR_CONTROL & Timer_keyboard_ISR_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Timer_keyboard_ISR_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Timer_keyboard_ISR_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Timer_keyboard_ISR_Stop();
    Timer_keyboard_ISR_SaveConfig();
}


/*******************************************************************************
* Function Name: Timer_keyboard_ISR_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_keyboard_ISR_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_keyboard_ISR_Wakeup(void) 
{
    Timer_keyboard_ISR_RestoreConfig();
    #if(!Timer_keyboard_ISR_UDB_CONTROL_REG_REMOVED)
        if(Timer_keyboard_ISR_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Timer_keyboard_ISR_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
