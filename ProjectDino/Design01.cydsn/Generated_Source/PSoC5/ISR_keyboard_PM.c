/*******************************************************************************
* File Name: ISR_keyboard_PM.c
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

#include "ISR_keyboard.h"

static ISR_keyboard_backupStruct ISR_keyboard_backup;


/*******************************************************************************
* Function Name: ISR_keyboard_SaveConfig
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
*  ISR_keyboard_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void ISR_keyboard_SaveConfig(void) 
{
    #if (!ISR_keyboard_UsingFixedFunction)
        ISR_keyboard_backup.TimerUdb = ISR_keyboard_ReadCounter();
        ISR_keyboard_backup.InterruptMaskValue = ISR_keyboard_STATUS_MASK;
        #if (ISR_keyboard_UsingHWCaptureCounter)
            ISR_keyboard_backup.TimerCaptureCounter = ISR_keyboard_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!ISR_keyboard_UDB_CONTROL_REG_REMOVED)
            ISR_keyboard_backup.TimerControlRegister = ISR_keyboard_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: ISR_keyboard_RestoreConfig
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
*  ISR_keyboard_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void ISR_keyboard_RestoreConfig(void) 
{   
    #if (!ISR_keyboard_UsingFixedFunction)

        ISR_keyboard_WriteCounter(ISR_keyboard_backup.TimerUdb);
        ISR_keyboard_STATUS_MASK =ISR_keyboard_backup.InterruptMaskValue;
        #if (ISR_keyboard_UsingHWCaptureCounter)
            ISR_keyboard_SetCaptureCount(ISR_keyboard_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!ISR_keyboard_UDB_CONTROL_REG_REMOVED)
            ISR_keyboard_WriteControlRegister(ISR_keyboard_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: ISR_keyboard_Sleep
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
*  ISR_keyboard_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void ISR_keyboard_Sleep(void) 
{
    #if(!ISR_keyboard_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(ISR_keyboard_CTRL_ENABLE == (ISR_keyboard_CONTROL & ISR_keyboard_CTRL_ENABLE))
        {
            /* Timer is enabled */
            ISR_keyboard_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            ISR_keyboard_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    ISR_keyboard_Stop();
    ISR_keyboard_SaveConfig();
}


/*******************************************************************************
* Function Name: ISR_keyboard_Wakeup
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
*  ISR_keyboard_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void ISR_keyboard_Wakeup(void) 
{
    ISR_keyboard_RestoreConfig();
    #if(!ISR_keyboard_UDB_CONTROL_REG_REMOVED)
        if(ISR_keyboard_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                ISR_keyboard_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
