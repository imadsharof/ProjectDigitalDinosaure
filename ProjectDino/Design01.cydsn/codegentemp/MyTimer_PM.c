/*******************************************************************************
* File Name: MyTimer_PM.c
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

#include "MyTimer.h"

static MyTimer_backupStruct MyTimer_backup;


/*******************************************************************************
* Function Name: MyTimer_SaveConfig
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
*  MyTimer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void MyTimer_SaveConfig(void) 
{
    #if (!MyTimer_UsingFixedFunction)
        MyTimer_backup.TimerUdb = MyTimer_ReadCounter();
        MyTimer_backup.InterruptMaskValue = MyTimer_STATUS_MASK;
        #if (MyTimer_UsingHWCaptureCounter)
            MyTimer_backup.TimerCaptureCounter = MyTimer_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!MyTimer_UDB_CONTROL_REG_REMOVED)
            MyTimer_backup.TimerControlRegister = MyTimer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: MyTimer_RestoreConfig
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
*  MyTimer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void MyTimer_RestoreConfig(void) 
{   
    #if (!MyTimer_UsingFixedFunction)

        MyTimer_WriteCounter(MyTimer_backup.TimerUdb);
        MyTimer_STATUS_MASK =MyTimer_backup.InterruptMaskValue;
        #if (MyTimer_UsingHWCaptureCounter)
            MyTimer_SetCaptureCount(MyTimer_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!MyTimer_UDB_CONTROL_REG_REMOVED)
            MyTimer_WriteControlRegister(MyTimer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: MyTimer_Sleep
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
*  MyTimer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void MyTimer_Sleep(void) 
{
    #if(!MyTimer_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(MyTimer_CTRL_ENABLE == (MyTimer_CONTROL & MyTimer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            MyTimer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            MyTimer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    MyTimer_Stop();
    MyTimer_SaveConfig();
}


/*******************************************************************************
* Function Name: MyTimer_Wakeup
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
*  MyTimer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void MyTimer_Wakeup(void) 
{
    MyTimer_RestoreConfig();
    #if(!MyTimer_UDB_CONTROL_REG_REMOVED)
        if(MyTimer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                MyTimer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
