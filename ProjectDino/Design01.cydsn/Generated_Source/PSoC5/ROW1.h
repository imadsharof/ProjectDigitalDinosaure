/*******************************************************************************
* File Name: ROW1.h  
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

#if !defined(CY_PINS_ROW1_H) /* Pins ROW1_H */
#define CY_PINS_ROW1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ROW1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ROW1__PORT == 15 && ((ROW1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    ROW1_Write(uint8 value);
void    ROW1_SetDriveMode(uint8 mode);
uint8   ROW1_ReadDataReg(void);
uint8   ROW1_Read(void);
void    ROW1_SetInterruptMode(uint16 position, uint16 mode);
uint8   ROW1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the ROW1_SetDriveMode() function.
     *  @{
     */
        #define ROW1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define ROW1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define ROW1_DM_RES_UP          PIN_DM_RES_UP
        #define ROW1_DM_RES_DWN         PIN_DM_RES_DWN
        #define ROW1_DM_OD_LO           PIN_DM_OD_LO
        #define ROW1_DM_OD_HI           PIN_DM_OD_HI
        #define ROW1_DM_STRONG          PIN_DM_STRONG
        #define ROW1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define ROW1_MASK               ROW1__MASK
#define ROW1_SHIFT              ROW1__SHIFT
#define ROW1_WIDTH              1u

/* Interrupt constants */
#if defined(ROW1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ROW1_SetInterruptMode() function.
     *  @{
     */
        #define ROW1_INTR_NONE      (uint16)(0x0000u)
        #define ROW1_INTR_RISING    (uint16)(0x0001u)
        #define ROW1_INTR_FALLING   (uint16)(0x0002u)
        #define ROW1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define ROW1_INTR_MASK      (0x01u) 
#endif /* (ROW1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ROW1_PS                     (* (reg8 *) ROW1__PS)
/* Data Register */
#define ROW1_DR                     (* (reg8 *) ROW1__DR)
/* Port Number */
#define ROW1_PRT_NUM                (* (reg8 *) ROW1__PRT) 
/* Connect to Analog Globals */                                                  
#define ROW1_AG                     (* (reg8 *) ROW1__AG)                       
/* Analog MUX bux enable */
#define ROW1_AMUX                   (* (reg8 *) ROW1__AMUX) 
/* Bidirectional Enable */                                                        
#define ROW1_BIE                    (* (reg8 *) ROW1__BIE)
/* Bit-mask for Aliased Register Access */
#define ROW1_BIT_MASK               (* (reg8 *) ROW1__BIT_MASK)
/* Bypass Enable */
#define ROW1_BYP                    (* (reg8 *) ROW1__BYP)
/* Port wide control signals */                                                   
#define ROW1_CTL                    (* (reg8 *) ROW1__CTL)
/* Drive Modes */
#define ROW1_DM0                    (* (reg8 *) ROW1__DM0) 
#define ROW1_DM1                    (* (reg8 *) ROW1__DM1)
#define ROW1_DM2                    (* (reg8 *) ROW1__DM2) 
/* Input Buffer Disable Override */
#define ROW1_INP_DIS                (* (reg8 *) ROW1__INP_DIS)
/* LCD Common or Segment Drive */
#define ROW1_LCD_COM_SEG            (* (reg8 *) ROW1__LCD_COM_SEG)
/* Enable Segment LCD */
#define ROW1_LCD_EN                 (* (reg8 *) ROW1__LCD_EN)
/* Slew Rate Control */
#define ROW1_SLW                    (* (reg8 *) ROW1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ROW1_PRTDSI__CAPS_SEL       (* (reg8 *) ROW1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ROW1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ROW1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ROW1_PRTDSI__OE_SEL0        (* (reg8 *) ROW1__PRTDSI__OE_SEL0) 
#define ROW1_PRTDSI__OE_SEL1        (* (reg8 *) ROW1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ROW1_PRTDSI__OUT_SEL0       (* (reg8 *) ROW1__PRTDSI__OUT_SEL0) 
#define ROW1_PRTDSI__OUT_SEL1       (* (reg8 *) ROW1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ROW1_PRTDSI__SYNC_OUT       (* (reg8 *) ROW1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(ROW1__SIO_CFG)
    #define ROW1_SIO_HYST_EN        (* (reg8 *) ROW1__SIO_HYST_EN)
    #define ROW1_SIO_REG_HIFREQ     (* (reg8 *) ROW1__SIO_REG_HIFREQ)
    #define ROW1_SIO_CFG            (* (reg8 *) ROW1__SIO_CFG)
    #define ROW1_SIO_DIFF           (* (reg8 *) ROW1__SIO_DIFF)
#endif /* (ROW1__SIO_CFG) */

/* Interrupt Registers */
#if defined(ROW1__INTSTAT)
    #define ROW1_INTSTAT            (* (reg8 *) ROW1__INTSTAT)
    #define ROW1_SNAP               (* (reg8 *) ROW1__SNAP)
    
	#define ROW1_0_INTTYPE_REG 		(* (reg8 *) ROW1__0__INTTYPE)
#endif /* (ROW1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ROW1_H */


/* [] END OF FILE */
