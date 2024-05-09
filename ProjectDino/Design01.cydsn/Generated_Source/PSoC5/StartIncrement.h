/*******************************************************************************
* File Name: StartIncrement.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_StartIncrement_H)
#define CY_ISR_StartIncrement_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void StartIncrement_Start(void);
void StartIncrement_StartEx(cyisraddress address);
void StartIncrement_Stop(void);

CY_ISR_PROTO(StartIncrement_Interrupt);

void StartIncrement_SetVector(cyisraddress address);
cyisraddress StartIncrement_GetVector(void);

void StartIncrement_SetPriority(uint8 priority);
uint8 StartIncrement_GetPriority(void);

void StartIncrement_Enable(void);
uint8 StartIncrement_GetState(void);
void StartIncrement_Disable(void);

void StartIncrement_SetPending(void);
void StartIncrement_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the StartIncrement ISR. */
#define StartIncrement_INTC_VECTOR            ((reg32 *) StartIncrement__INTC_VECT)

/* Address of the StartIncrement ISR priority. */
#define StartIncrement_INTC_PRIOR             ((reg8 *) StartIncrement__INTC_PRIOR_REG)

/* Priority of the StartIncrement interrupt. */
#define StartIncrement_INTC_PRIOR_NUMBER      StartIncrement__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable StartIncrement interrupt. */
#define StartIncrement_INTC_SET_EN            ((reg32 *) StartIncrement__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the StartIncrement interrupt. */
#define StartIncrement_INTC_CLR_EN            ((reg32 *) StartIncrement__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the StartIncrement interrupt state to pending. */
#define StartIncrement_INTC_SET_PD            ((reg32 *) StartIncrement__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the StartIncrement interrupt. */
#define StartIncrement_INTC_CLR_PD            ((reg32 *) StartIncrement__INTC_CLR_PD_REG)


#endif /* CY_ISR_StartIncrement_H */


/* [] END OF FILE */
