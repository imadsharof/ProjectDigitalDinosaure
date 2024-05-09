/*******************************************************************************
* File Name: PWMOUT.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_PWMOUT_H) /* Pins PWMOUT_H */
#define CY_PINS_PWMOUT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PWMOUT_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PWMOUT__PORT == 15 && ((PWMOUT__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PWMOUT_Write(uint8 value);
void    PWMOUT_SetDriveMode(uint8 mode);
uint8   PWMOUT_ReadDataReg(void);
uint8   PWMOUT_Read(void);
void    PWMOUT_SetInterruptMode(uint16 position, uint16 mode);
uint8   PWMOUT_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PWMOUT_SetDriveMode() function.
     *  @{
     */
        #define PWMOUT_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PWMOUT_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PWMOUT_DM_RES_UP          PIN_DM_RES_UP
        #define PWMOUT_DM_RES_DWN         PIN_DM_RES_DWN
        #define PWMOUT_DM_OD_LO           PIN_DM_OD_LO
        #define PWMOUT_DM_OD_HI           PIN_DM_OD_HI
        #define PWMOUT_DM_STRONG          PIN_DM_STRONG
        #define PWMOUT_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PWMOUT_MASK               PWMOUT__MASK
#define PWMOUT_SHIFT              PWMOUT__SHIFT
#define PWMOUT_WIDTH              1u

/* Interrupt constants */
#if defined(PWMOUT__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PWMOUT_SetInterruptMode() function.
     *  @{
     */
        #define PWMOUT_INTR_NONE      (uint16)(0x0000u)
        #define PWMOUT_INTR_RISING    (uint16)(0x0001u)
        #define PWMOUT_INTR_FALLING   (uint16)(0x0002u)
        #define PWMOUT_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PWMOUT_INTR_MASK      (0x01u) 
#endif /* (PWMOUT__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PWMOUT_PS                     (* (reg8 *) PWMOUT__PS)
/* Data Register */
#define PWMOUT_DR                     (* (reg8 *) PWMOUT__DR)
/* Port Number */
#define PWMOUT_PRT_NUM                (* (reg8 *) PWMOUT__PRT) 
/* Connect to Analog Globals */                                                  
#define PWMOUT_AG                     (* (reg8 *) PWMOUT__AG)                       
/* Analog MUX bux enable */
#define PWMOUT_AMUX                   (* (reg8 *) PWMOUT__AMUX) 
/* Bidirectional Enable */                                                        
#define PWMOUT_BIE                    (* (reg8 *) PWMOUT__BIE)
/* Bit-mask for Aliased Register Access */
#define PWMOUT_BIT_MASK               (* (reg8 *) PWMOUT__BIT_MASK)
/* Bypass Enable */
#define PWMOUT_BYP                    (* (reg8 *) PWMOUT__BYP)
/* Port wide control signals */                                                   
#define PWMOUT_CTL                    (* (reg8 *) PWMOUT__CTL)
/* Drive Modes */
#define PWMOUT_DM0                    (* (reg8 *) PWMOUT__DM0) 
#define PWMOUT_DM1                    (* (reg8 *) PWMOUT__DM1)
#define PWMOUT_DM2                    (* (reg8 *) PWMOUT__DM2) 
/* Input Buffer Disable Override */
#define PWMOUT_INP_DIS                (* (reg8 *) PWMOUT__INP_DIS)
/* LCD Common or Segment Drive */
#define PWMOUT_LCD_COM_SEG            (* (reg8 *) PWMOUT__LCD_COM_SEG)
/* Enable Segment LCD */
#define PWMOUT_LCD_EN                 (* (reg8 *) PWMOUT__LCD_EN)
/* Slew Rate Control */
#define PWMOUT_SLW                    (* (reg8 *) PWMOUT__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PWMOUT_PRTDSI__CAPS_SEL       (* (reg8 *) PWMOUT__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PWMOUT_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PWMOUT__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PWMOUT_PRTDSI__OE_SEL0        (* (reg8 *) PWMOUT__PRTDSI__OE_SEL0) 
#define PWMOUT_PRTDSI__OE_SEL1        (* (reg8 *) PWMOUT__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PWMOUT_PRTDSI__OUT_SEL0       (* (reg8 *) PWMOUT__PRTDSI__OUT_SEL0) 
#define PWMOUT_PRTDSI__OUT_SEL1       (* (reg8 *) PWMOUT__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PWMOUT_PRTDSI__SYNC_OUT       (* (reg8 *) PWMOUT__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PWMOUT__SIO_CFG)
    #define PWMOUT_SIO_HYST_EN        (* (reg8 *) PWMOUT__SIO_HYST_EN)
    #define PWMOUT_SIO_REG_HIFREQ     (* (reg8 *) PWMOUT__SIO_REG_HIFREQ)
    #define PWMOUT_SIO_CFG            (* (reg8 *) PWMOUT__SIO_CFG)
    #define PWMOUT_SIO_DIFF           (* (reg8 *) PWMOUT__SIO_DIFF)
#endif /* (PWMOUT__SIO_CFG) */

/* Interrupt Registers */
#if defined(PWMOUT__INTSTAT)
    #define PWMOUT_INTSTAT            (* (reg8 *) PWMOUT__INTSTAT)
    #define PWMOUT_SNAP               (* (reg8 *) PWMOUT__SNAP)
    
	#define PWMOUT_0_INTTYPE_REG 		(* (reg8 *) PWMOUT__0__INTTYPE)
#endif /* (PWMOUT__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PWMOUT_H */


/* [] END OF FILE */
