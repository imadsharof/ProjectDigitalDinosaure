/*******************************************************************************
* File Name: MyTimer.h
* Version 2.80
*
*  Description:
*     Contains the function prototypes and constants available to the timer
*     user module.
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_TIMER_MyTimer_H)
#define CY_TIMER_MyTimer_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 MyTimer_initVar;

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Timer_v2_80 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */


/**************************************
*           Parameter Defaults
**************************************/

#define MyTimer_Resolution                 16u
#define MyTimer_UsingFixedFunction         1u
#define MyTimer_UsingHWCaptureCounter      0u
#define MyTimer_SoftwareCaptureMode        0u
#define MyTimer_SoftwareTriggerMode        0u
#define MyTimer_UsingHWEnable              0u
#define MyTimer_EnableTriggerMode          0u
#define MyTimer_InterruptOnCaptureCount    0u
#define MyTimer_RunModeUsed                0u
#define MyTimer_ControlRegRemoved          0u

#if defined(MyTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG)
    #define MyTimer_UDB_CONTROL_REG_REMOVED            (0u)
#elif  (MyTimer_UsingFixedFunction)
    #define MyTimer_UDB_CONTROL_REG_REMOVED            (0u)
#else 
    #define MyTimer_UDB_CONTROL_REG_REMOVED            (1u)
#endif /* End MyTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG */


/***************************************
*       Type defines
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for Timer Component
 *************************************************************************/
typedef struct
{
    uint8 TimerEnableState;
    #if(!MyTimer_UsingFixedFunction)

        uint16 TimerUdb;
        uint8 InterruptMaskValue;
        #if (MyTimer_UsingHWCaptureCounter)
            uint8 TimerCaptureCounter;
        #endif /* variable declarations for backing up non retention registers in CY_UDB_V1 */

        #if (!MyTimer_UDB_CONTROL_REG_REMOVED)
            uint8 TimerControlRegister;
        #endif /* variable declaration for backing up enable state of the Timer */
    #endif /* define backup variables only for UDB implementation. Fixed function registers are all retention */

}MyTimer_backupStruct;


/***************************************
*       Function Prototypes
***************************************/

void    MyTimer_Start(void) ;
void    MyTimer_Stop(void) ;

void    MyTimer_SetInterruptMode(uint8 interruptMode) ;
uint8   MyTimer_ReadStatusRegister(void) ;
/* Deprecated function. Do not use this in future. Retained for backward compatibility */
#define MyTimer_GetInterruptSource() MyTimer_ReadStatusRegister()

#if(!MyTimer_UDB_CONTROL_REG_REMOVED)
    uint8   MyTimer_ReadControlRegister(void) ;
    void    MyTimer_WriteControlRegister(uint8 control) ;
#endif /* (!MyTimer_UDB_CONTROL_REG_REMOVED) */

uint16  MyTimer_ReadPeriod(void) ;
void    MyTimer_WritePeriod(uint16 period) ;
uint16  MyTimer_ReadCounter(void) ;
void    MyTimer_WriteCounter(uint16 counter) ;
uint16  MyTimer_ReadCapture(void) ;
void    MyTimer_SoftwareCapture(void) ;

#if(!MyTimer_UsingFixedFunction) /* UDB Prototypes */
    #if (MyTimer_SoftwareCaptureMode)
        void    MyTimer_SetCaptureMode(uint8 captureMode) ;
    #endif /* (!MyTimer_UsingFixedFunction) */

    #if (MyTimer_SoftwareTriggerMode)
        void    MyTimer_SetTriggerMode(uint8 triggerMode) ;
    #endif /* (MyTimer_SoftwareTriggerMode) */

    #if (MyTimer_EnableTriggerMode)
        void    MyTimer_EnableTrigger(void) ;
        void    MyTimer_DisableTrigger(void) ;
    #endif /* (MyTimer_EnableTriggerMode) */


    #if(MyTimer_InterruptOnCaptureCount)
        void    MyTimer_SetInterruptCount(uint8 interruptCount) ;
    #endif /* (MyTimer_InterruptOnCaptureCount) */

    #if (MyTimer_UsingHWCaptureCounter)
        void    MyTimer_SetCaptureCount(uint8 captureCount) ;
        uint8   MyTimer_ReadCaptureCount(void) ;
    #endif /* (MyTimer_UsingHWCaptureCounter) */

    void MyTimer_ClearFIFO(void) ;
#endif /* UDB Prototypes */

/* Sleep Retention APIs */
void MyTimer_Init(void)          ;
void MyTimer_Enable(void)        ;
void MyTimer_SaveConfig(void)    ;
void MyTimer_RestoreConfig(void) ;
void MyTimer_Sleep(void)         ;
void MyTimer_Wakeup(void)        ;


/***************************************
*   Enumerated Types and Parameters
***************************************/

/* Enumerated Type B_Timer__CaptureModes, Used in Capture Mode */
#define MyTimer__B_TIMER__CM_NONE 0
#define MyTimer__B_TIMER__CM_RISINGEDGE 1
#define MyTimer__B_TIMER__CM_FALLINGEDGE 2
#define MyTimer__B_TIMER__CM_EITHEREDGE 3
#define MyTimer__B_TIMER__CM_SOFTWARE 4



/* Enumerated Type B_Timer__TriggerModes, Used in Trigger Mode */
#define MyTimer__B_TIMER__TM_NONE 0x00u
#define MyTimer__B_TIMER__TM_RISINGEDGE 0x04u
#define MyTimer__B_TIMER__TM_FALLINGEDGE 0x08u
#define MyTimer__B_TIMER__TM_EITHEREDGE 0x0Cu
#define MyTimer__B_TIMER__TM_SOFTWARE 0x10u


/***************************************
*    Initialial Parameter Constants
***************************************/

#define MyTimer_INIT_PERIOD             23999u
#define MyTimer_INIT_CAPTURE_MODE       ((uint8)((uint8)1u << MyTimer_CTRL_CAP_MODE_SHIFT))
#define MyTimer_INIT_TRIGGER_MODE       ((uint8)((uint8)0u << MyTimer_CTRL_TRIG_MODE_SHIFT))
#if (MyTimer_UsingFixedFunction)
    #define MyTimer_INIT_INTERRUPT_MODE (((uint8)((uint8)0u << MyTimer_STATUS_TC_INT_MASK_SHIFT)) | \
                                                  ((uint8)((uint8)0 << MyTimer_STATUS_CAPTURE_INT_MASK_SHIFT)))
#else
    #define MyTimer_INIT_INTERRUPT_MODE (((uint8)((uint8)0u << MyTimer_STATUS_TC_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << MyTimer_STATUS_CAPTURE_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << MyTimer_STATUS_FIFOFULL_INT_MASK_SHIFT)))
#endif /* (MyTimer_UsingFixedFunction) */
#define MyTimer_INIT_CAPTURE_COUNT      (2u)
#define MyTimer_INIT_INT_CAPTURE_COUNT  ((uint8)((uint8)(1u - 1u) << MyTimer_CTRL_INTCNT_SHIFT))


/***************************************
*           Registers
***************************************/

#if (MyTimer_UsingFixedFunction) /* Implementation Specific Registers and Register Constants */


    /***************************************
    *    Fixed Function Registers
    ***************************************/

    #define MyTimer_STATUS         (*(reg8 *) MyTimer_TimerHW__SR0 )
    /* In Fixed Function Block Status and Mask are the same register */
    #define MyTimer_STATUS_MASK    (*(reg8 *) MyTimer_TimerHW__SR0 )
    #define MyTimer_CONTROL        (*(reg8 *) MyTimer_TimerHW__CFG0)
    #define MyTimer_CONTROL2       (*(reg8 *) MyTimer_TimerHW__CFG1)
    #define MyTimer_CONTROL2_PTR   ( (reg8 *) MyTimer_TimerHW__CFG1)
    #define MyTimer_RT1            (*(reg8 *) MyTimer_TimerHW__RT1)
    #define MyTimer_RT1_PTR        ( (reg8 *) MyTimer_TimerHW__RT1)

    #if (CY_PSOC3 || CY_PSOC5LP)
        #define MyTimer_CONTROL3       (*(reg8 *) MyTimer_TimerHW__CFG2)
        #define MyTimer_CONTROL3_PTR   ( (reg8 *) MyTimer_TimerHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define MyTimer_GLOBAL_ENABLE  (*(reg8 *) MyTimer_TimerHW__PM_ACT_CFG)
    #define MyTimer_GLOBAL_STBY_ENABLE  (*(reg8 *) MyTimer_TimerHW__PM_STBY_CFG)

    #define MyTimer_CAPTURE_LSB         (* (reg16 *) MyTimer_TimerHW__CAP0 )
    #define MyTimer_CAPTURE_LSB_PTR       ((reg16 *) MyTimer_TimerHW__CAP0 )
    #define MyTimer_PERIOD_LSB          (* (reg16 *) MyTimer_TimerHW__PER0 )
    #define MyTimer_PERIOD_LSB_PTR        ((reg16 *) MyTimer_TimerHW__PER0 )
    #define MyTimer_COUNTER_LSB         (* (reg16 *) MyTimer_TimerHW__CNT_CMP0 )
    #define MyTimer_COUNTER_LSB_PTR       ((reg16 *) MyTimer_TimerHW__CNT_CMP0 )


    /***************************************
    *    Register Constants
    ***************************************/

    /* Fixed Function Block Chosen */
    #define MyTimer_BLOCK_EN_MASK                     MyTimer_TimerHW__PM_ACT_MSK
    #define MyTimer_BLOCK_STBY_EN_MASK                MyTimer_TimerHW__PM_STBY_MSK

    /* Control Register Bit Locations */
    /* Interrupt Count - Not valid for Fixed Function Block */
    #define MyTimer_CTRL_INTCNT_SHIFT                  0x00u
    /* Trigger Polarity - Not valid for Fixed Function Block */
    #define MyTimer_CTRL_TRIG_MODE_SHIFT               0x00u
    /* Trigger Enable - Not valid for Fixed Function Block */
    #define MyTimer_CTRL_TRIG_EN_SHIFT                 0x00u
    /* Capture Polarity - Not valid for Fixed Function Block */
    #define MyTimer_CTRL_CAP_MODE_SHIFT                0x00u
    /* Timer Enable - As defined in Register Map, part of TMRX_CFG0 register */
    #define MyTimer_CTRL_ENABLE_SHIFT                  0x00u

    /* Control Register Bit Masks */
    #define MyTimer_CTRL_ENABLE                        ((uint8)((uint8)0x01u << MyTimer_CTRL_ENABLE_SHIFT))

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define MyTimer_CTRL2_IRQ_SEL_SHIFT                 0x00u
    #define MyTimer_CTRL2_IRQ_SEL                      ((uint8)((uint8)0x01u << MyTimer_CTRL2_IRQ_SEL_SHIFT))

    #if (CY_PSOC5A)
        /* Use CFG1 Mode bits to set run mode */
        /* As defined by Verilog Implementation */
        #define MyTimer_CTRL_MODE_SHIFT                 0x01u
        #define MyTimer_CTRL_MODE_MASK                 ((uint8)((uint8)0x07u << MyTimer_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC5A) */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Control3 Register Bit Locations */
        #define MyTimer_CTRL_RCOD_SHIFT        0x02u
        #define MyTimer_CTRL_ENBL_SHIFT        0x00u
        #define MyTimer_CTRL_MODE_SHIFT        0x00u

        /* Control3 Register Bit Masks */
        #define MyTimer_CTRL_RCOD_MASK  ((uint8)((uint8)0x03u << MyTimer_CTRL_RCOD_SHIFT)) /* ROD and COD bit masks */
        #define MyTimer_CTRL_ENBL_MASK  ((uint8)((uint8)0x80u << MyTimer_CTRL_ENBL_SHIFT)) /* HW_EN bit mask */
        #define MyTimer_CTRL_MODE_MASK  ((uint8)((uint8)0x03u << MyTimer_CTRL_MODE_SHIFT)) /* Run mode bit mask */

        #define MyTimer_CTRL_RCOD       ((uint8)((uint8)0x03u << MyTimer_CTRL_RCOD_SHIFT))
        #define MyTimer_CTRL_ENBL       ((uint8)((uint8)0x80u << MyTimer_CTRL_ENBL_SHIFT))
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */

    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP */
    #define MyTimer_RT1_SHIFT                       0x04u
    /* Sync TC and CMP bit masks */
    #define MyTimer_RT1_MASK                        ((uint8)((uint8)0x03u << MyTimer_RT1_SHIFT))
    #define MyTimer_SYNC                            ((uint8)((uint8)0x03u << MyTimer_RT1_SHIFT))
    #define MyTimer_SYNCDSI_SHIFT                   0x00u
    /* Sync all DSI inputs with Mask  */
    #define MyTimer_SYNCDSI_MASK                    ((uint8)((uint8)0x0Fu << MyTimer_SYNCDSI_SHIFT))
    /* Sync all DSI inputs */
    #define MyTimer_SYNCDSI_EN                      ((uint8)((uint8)0x0Fu << MyTimer_SYNCDSI_SHIFT))

    #define MyTimer_CTRL_MODE_PULSEWIDTH            ((uint8)((uint8)0x01u << MyTimer_CTRL_MODE_SHIFT))
    #define MyTimer_CTRL_MODE_PERIOD                ((uint8)((uint8)0x02u << MyTimer_CTRL_MODE_SHIFT))
    #define MyTimer_CTRL_MODE_CONTINUOUS            ((uint8)((uint8)0x00u << MyTimer_CTRL_MODE_SHIFT))

    /* Status Register Bit Locations */
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define MyTimer_STATUS_TC_SHIFT                 0x07u
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define MyTimer_STATUS_CAPTURE_SHIFT            0x06u
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define MyTimer_STATUS_TC_INT_MASK_SHIFT        (MyTimer_STATUS_TC_SHIFT - 0x04u)
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define MyTimer_STATUS_CAPTURE_INT_MASK_SHIFT   (MyTimer_STATUS_CAPTURE_SHIFT - 0x04u)

    /* Status Register Bit Masks */
    #define MyTimer_STATUS_TC                       ((uint8)((uint8)0x01u << MyTimer_STATUS_TC_SHIFT))
    #define MyTimer_STATUS_CAPTURE                  ((uint8)((uint8)0x01u << MyTimer_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on TC */
    #define MyTimer_STATUS_TC_INT_MASK              ((uint8)((uint8)0x01u << MyTimer_STATUS_TC_INT_MASK_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on Capture */
    #define MyTimer_STATUS_CAPTURE_INT_MASK         ((uint8)((uint8)0x01u << MyTimer_STATUS_CAPTURE_INT_MASK_SHIFT))

#else   /* UDB Registers and Register Constants */


    /***************************************
    *           UDB Registers
    ***************************************/

    #define MyTimer_STATUS              (* (reg8 *) MyTimer_TimerUDB_rstSts_stsreg__STATUS_REG )
    #define MyTimer_STATUS_MASK         (* (reg8 *) MyTimer_TimerUDB_rstSts_stsreg__MASK_REG)
    #define MyTimer_STATUS_AUX_CTRL     (* (reg8 *) MyTimer_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG)
    #define MyTimer_CONTROL             (* (reg8 *) MyTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG )
    
    #if(MyTimer_Resolution <= 8u) /* 8-bit Timer */
        #define MyTimer_CAPTURE_LSB         (* (reg8 *) MyTimer_TimerUDB_sT16_timerdp_u0__F0_REG )
        #define MyTimer_CAPTURE_LSB_PTR       ((reg8 *) MyTimer_TimerUDB_sT16_timerdp_u0__F0_REG )
        #define MyTimer_PERIOD_LSB          (* (reg8 *) MyTimer_TimerUDB_sT16_timerdp_u0__D0_REG )
        #define MyTimer_PERIOD_LSB_PTR        ((reg8 *) MyTimer_TimerUDB_sT16_timerdp_u0__D0_REG )
        #define MyTimer_COUNTER_LSB         (* (reg8 *) MyTimer_TimerUDB_sT16_timerdp_u0__A0_REG )
        #define MyTimer_COUNTER_LSB_PTR       ((reg8 *) MyTimer_TimerUDB_sT16_timerdp_u0__A0_REG )
    #elif(MyTimer_Resolution <= 16u) /* 8-bit Timer */
        #if(CY_PSOC3) /* 8-bit addres space */
            #define MyTimer_CAPTURE_LSB         (* (reg16 *) MyTimer_TimerUDB_sT16_timerdp_u0__F0_REG )
            #define MyTimer_CAPTURE_LSB_PTR       ((reg16 *) MyTimer_TimerUDB_sT16_timerdp_u0__F0_REG )
            #define MyTimer_PERIOD_LSB          (* (reg16 *) MyTimer_TimerUDB_sT16_timerdp_u0__D0_REG )
            #define MyTimer_PERIOD_LSB_PTR        ((reg16 *) MyTimer_TimerUDB_sT16_timerdp_u0__D0_REG )
            #define MyTimer_COUNTER_LSB         (* (reg16 *) MyTimer_TimerUDB_sT16_timerdp_u0__A0_REG )
            #define MyTimer_COUNTER_LSB_PTR       ((reg16 *) MyTimer_TimerUDB_sT16_timerdp_u0__A0_REG )
        #else /* 16-bit address space */
            #define MyTimer_CAPTURE_LSB         (* (reg16 *) MyTimer_TimerUDB_sT16_timerdp_u0__16BIT_F0_REG )
            #define MyTimer_CAPTURE_LSB_PTR       ((reg16 *) MyTimer_TimerUDB_sT16_timerdp_u0__16BIT_F0_REG )
            #define MyTimer_PERIOD_LSB          (* (reg16 *) MyTimer_TimerUDB_sT16_timerdp_u0__16BIT_D0_REG )
            #define MyTimer_PERIOD_LSB_PTR        ((reg16 *) MyTimer_TimerUDB_sT16_timerdp_u0__16BIT_D0_REG )
            #define MyTimer_COUNTER_LSB         (* (reg16 *) MyTimer_TimerUDB_sT16_timerdp_u0__16BIT_A0_REG )
            #define MyTimer_COUNTER_LSB_PTR       ((reg16 *) MyTimer_TimerUDB_sT16_timerdp_u0__16BIT_A0_REG )
        #endif /* CY_PSOC3 */
    #elif(MyTimer_Resolution <= 24u)/* 24-bit Timer */
        #define MyTimer_CAPTURE_LSB         (* (reg32 *) MyTimer_TimerUDB_sT16_timerdp_u0__F0_REG )
        #define MyTimer_CAPTURE_LSB_PTR       ((reg32 *) MyTimer_TimerUDB_sT16_timerdp_u0__F0_REG )
        #define MyTimer_PERIOD_LSB          (* (reg32 *) MyTimer_TimerUDB_sT16_timerdp_u0__D0_REG )
        #define MyTimer_PERIOD_LSB_PTR        ((reg32 *) MyTimer_TimerUDB_sT16_timerdp_u0__D0_REG )
        #define MyTimer_COUNTER_LSB         (* (reg32 *) MyTimer_TimerUDB_sT16_timerdp_u0__A0_REG )
        #define MyTimer_COUNTER_LSB_PTR       ((reg32 *) MyTimer_TimerUDB_sT16_timerdp_u0__A0_REG )
    #else /* 32-bit Timer */
        #if(CY_PSOC3 || CY_PSOC5) /* 8-bit address space */
            #define MyTimer_CAPTURE_LSB         (* (reg32 *) MyTimer_TimerUDB_sT16_timerdp_u0__F0_REG )
            #define MyTimer_CAPTURE_LSB_PTR       ((reg32 *) MyTimer_TimerUDB_sT16_timerdp_u0__F0_REG )
            #define MyTimer_PERIOD_LSB          (* (reg32 *) MyTimer_TimerUDB_sT16_timerdp_u0__D0_REG )
            #define MyTimer_PERIOD_LSB_PTR        ((reg32 *) MyTimer_TimerUDB_sT16_timerdp_u0__D0_REG )
            #define MyTimer_COUNTER_LSB         (* (reg32 *) MyTimer_TimerUDB_sT16_timerdp_u0__A0_REG )
            #define MyTimer_COUNTER_LSB_PTR       ((reg32 *) MyTimer_TimerUDB_sT16_timerdp_u0__A0_REG )
        #else /* 32-bit address space */
            #define MyTimer_CAPTURE_LSB         (* (reg32 *) MyTimer_TimerUDB_sT16_timerdp_u0__32BIT_F0_REG )
            #define MyTimer_CAPTURE_LSB_PTR       ((reg32 *) MyTimer_TimerUDB_sT16_timerdp_u0__32BIT_F0_REG )
            #define MyTimer_PERIOD_LSB          (* (reg32 *) MyTimer_TimerUDB_sT16_timerdp_u0__32BIT_D0_REG )
            #define MyTimer_PERIOD_LSB_PTR        ((reg32 *) MyTimer_TimerUDB_sT16_timerdp_u0__32BIT_D0_REG )
            #define MyTimer_COUNTER_LSB         (* (reg32 *) MyTimer_TimerUDB_sT16_timerdp_u0__32BIT_A0_REG )
            #define MyTimer_COUNTER_LSB_PTR       ((reg32 *) MyTimer_TimerUDB_sT16_timerdp_u0__32BIT_A0_REG )
        #endif /* CY_PSOC3 || CY_PSOC5 */ 
    #endif

    #define MyTimer_COUNTER_LSB_PTR_8BIT       ((reg8 *) MyTimer_TimerUDB_sT16_timerdp_u0__A0_REG )
    
    #if (MyTimer_UsingHWCaptureCounter)
        #define MyTimer_CAP_COUNT              (*(reg8 *) MyTimer_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define MyTimer_CAP_COUNT_PTR          ( (reg8 *) MyTimer_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define MyTimer_CAPTURE_COUNT_CTRL     (*(reg8 *) MyTimer_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
        #define MyTimer_CAPTURE_COUNT_CTRL_PTR ( (reg8 *) MyTimer_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
    #endif /* (MyTimer_UsingHWCaptureCounter) */


    /***************************************
    *       Register Constants
    ***************************************/

    /* Control Register Bit Locations */
    #define MyTimer_CTRL_INTCNT_SHIFT              0x00u       /* As defined by Verilog Implementation */
    #define MyTimer_CTRL_TRIG_MODE_SHIFT           0x02u       /* As defined by Verilog Implementation */
    #define MyTimer_CTRL_TRIG_EN_SHIFT             0x04u       /* As defined by Verilog Implementation */
    #define MyTimer_CTRL_CAP_MODE_SHIFT            0x05u       /* As defined by Verilog Implementation */
    #define MyTimer_CTRL_ENABLE_SHIFT              0x07u       /* As defined by Verilog Implementation */

    /* Control Register Bit Masks */
    #define MyTimer_CTRL_INTCNT_MASK               ((uint8)((uint8)0x03u << MyTimer_CTRL_INTCNT_SHIFT))
    #define MyTimer_CTRL_TRIG_MODE_MASK            ((uint8)((uint8)0x03u << MyTimer_CTRL_TRIG_MODE_SHIFT))
    #define MyTimer_CTRL_TRIG_EN                   ((uint8)((uint8)0x01u << MyTimer_CTRL_TRIG_EN_SHIFT))
    #define MyTimer_CTRL_CAP_MODE_MASK             ((uint8)((uint8)0x03u << MyTimer_CTRL_CAP_MODE_SHIFT))
    #define MyTimer_CTRL_ENABLE                    ((uint8)((uint8)0x01u << MyTimer_CTRL_ENABLE_SHIFT))

    /* Bit Counter (7-bit) Control Register Bit Definitions */
    /* As defined by the Register map for the AUX Control Register */
    #define MyTimer_CNTR_ENABLE                    0x20u

    /* Status Register Bit Locations */
    #define MyTimer_STATUS_TC_SHIFT                0x00u  /* As defined by Verilog Implementation */
    #define MyTimer_STATUS_CAPTURE_SHIFT           0x01u  /* As defined by Verilog Implementation */
    #define MyTimer_STATUS_TC_INT_MASK_SHIFT       MyTimer_STATUS_TC_SHIFT
    #define MyTimer_STATUS_CAPTURE_INT_MASK_SHIFT  MyTimer_STATUS_CAPTURE_SHIFT
    #define MyTimer_STATUS_FIFOFULL_SHIFT          0x02u  /* As defined by Verilog Implementation */
    #define MyTimer_STATUS_FIFONEMP_SHIFT          0x03u  /* As defined by Verilog Implementation */
    #define MyTimer_STATUS_FIFOFULL_INT_MASK_SHIFT MyTimer_STATUS_FIFOFULL_SHIFT

    /* Status Register Bit Masks */
    /* Sticky TC Event Bit-Mask */
    #define MyTimer_STATUS_TC                      ((uint8)((uint8)0x01u << MyTimer_STATUS_TC_SHIFT))
    /* Sticky Capture Event Bit-Mask */
    #define MyTimer_STATUS_CAPTURE                 ((uint8)((uint8)0x01u << MyTimer_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define MyTimer_STATUS_TC_INT_MASK             ((uint8)((uint8)0x01u << MyTimer_STATUS_TC_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define MyTimer_STATUS_CAPTURE_INT_MASK        ((uint8)((uint8)0x01u << MyTimer_STATUS_CAPTURE_SHIFT))
    /* NOT-Sticky FIFO Full Bit-Mask */
    #define MyTimer_STATUS_FIFOFULL                ((uint8)((uint8)0x01u << MyTimer_STATUS_FIFOFULL_SHIFT))
    /* NOT-Sticky FIFO Not Empty Bit-Mask */
    #define MyTimer_STATUS_FIFONEMP                ((uint8)((uint8)0x01u << MyTimer_STATUS_FIFONEMP_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define MyTimer_STATUS_FIFOFULL_INT_MASK       ((uint8)((uint8)0x01u << MyTimer_STATUS_FIFOFULL_SHIFT))

    #define MyTimer_STATUS_ACTL_INT_EN             0x10u   /* As defined for the ACTL Register */

    /* Datapath Auxillary Control Register definitions */
    #define MyTimer_AUX_CTRL_FIFO0_CLR             0x01u   /* As defined by Register map */
    #define MyTimer_AUX_CTRL_FIFO1_CLR             0x02u   /* As defined by Register map */
    #define MyTimer_AUX_CTRL_FIFO0_LVL             0x04u   /* As defined by Register map */
    #define MyTimer_AUX_CTRL_FIFO1_LVL             0x08u   /* As defined by Register map */
    #define MyTimer_STATUS_ACTL_INT_EN_MASK        0x10u   /* As defined for the ACTL Register */

#endif /* Implementation Specific Registers and Register Constants */

#endif  /* CY_TIMER_MyTimer_H */


/* [] END OF FILE */
