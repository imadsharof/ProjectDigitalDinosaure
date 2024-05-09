/*******************************************************************************
* File Name: ROW2.h  
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

#if !defined(CY_PINS_ROW2_H) /* Pins ROW2_H */
#define CY_PINS_ROW2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ROW2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ROW2__PORT == 15 && ((ROW2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    ROW2_Write(uint8 value);
void    ROW2_SetDriveMode(uint8 mode);
uint8   ROW2_ReadDataReg(void);
uint8   ROW2_Read(void);
void    ROW2_SetInterruptMode(uint16 position, uint16 mode);
uint8   ROW2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the ROW2_SetDriveMode() function.
     *  @{
     */
        #define ROW2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define ROW2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define ROW2_DM_RES_UP          PIN_DM_RES_UP
        #define ROW2_DM_RES_DWN         PIN_DM_RES_DWN
        #define ROW2_DM_OD_LO           PIN_DM_OD_LO
        #define ROW2_DM_OD_HI           PIN_DM_OD_HI
        #define ROW2_DM_STRONG          PIN_DM_STRONG
        #define ROW2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define ROW2_MASK               ROW2__MASK
#define ROW2_SHIFT              ROW2__SHIFT
#define ROW2_WIDTH              1u

/* Interrupt constants */
#if defined(ROW2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ROW2_SetInterruptMode() function.
     *  @{
     */
        #define ROW2_INTR_NONE      (uint16)(0x0000u)
        #define ROW2_INTR_RISING    (uint16)(0x0001u)
        #define ROW2_INTR_FALLING   (uint16)(0x0002u)
        #define ROW2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define ROW2_INTR_MASK      (0x01u) 
#endif /* (ROW2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ROW2_PS                     (* (reg8 *) ROW2__PS)
/* Data Register */
#define ROW2_DR                     (* (reg8 *) ROW2__DR)
/* Port Number */
#define ROW2_PRT_NUM                (* (reg8 *) ROW2__PRT) 
/* Connect to Analog Globals */                                                  
#define ROW2_AG                     (* (reg8 *) ROW2__AG)                       
/* Analog MUX bux enable */
#define ROW2_AMUX                   (* (reg8 *) ROW2__AMUX) 
/* Bidirectional Enable */                                                        
#define ROW2_BIE                    (* (reg8 *) ROW2__BIE)
/* Bit-mask for Aliased Register Access */
#define ROW2_BIT_MASK               (* (reg8 *) ROW2__BIT_MASK)
/* Bypass Enable */
#define ROW2_BYP                    (* (reg8 *) ROW2__BYP)
/* Port wide control signals */                                                   
#define ROW2_CTL                    (* (reg8 *) ROW2__CTL)
/* Drive Modes */
#define ROW2_DM0                    (* (reg8 *) ROW2__DM0) 
#define ROW2_DM1                    (* (reg8 *) ROW2__DM1)
#define ROW2_DM2                    (* (reg8 *) ROW2__DM2) 
/* Input Buffer Disable Override */
#define ROW2_INP_DIS                (* (reg8 *) ROW2__INP_DIS)
/* LCD Common or Segment Drive */
#define ROW2_LCD_COM_SEG            (* (reg8 *) ROW2__LCD_COM_SEG)
/* Enable Segment LCD */
#define ROW2_LCD_EN                 (* (reg8 *) ROW2__LCD_EN)
/* Slew Rate Control */
#define ROW2_SLW                    (* (reg8 *) ROW2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ROW2_PRTDSI__CAPS_SEL       (* (reg8 *) ROW2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ROW2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ROW2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ROW2_PRTDSI__OE_SEL0        (* (reg8 *) ROW2__PRTDSI__OE_SEL0) 
#define ROW2_PRTDSI__OE_SEL1        (* (reg8 *) ROW2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ROW2_PRTDSI__OUT_SEL0       (* (reg8 *) ROW2__PRTDSI__OUT_SEL0) 
#define ROW2_PRTDSI__OUT_SEL1       (* (reg8 *) ROW2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ROW2_PRTDSI__SYNC_OUT       (* (reg8 *) ROW2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(ROW2__SIO_CFG)
    #define ROW2_SIO_HYST_EN        (* (reg8 *) ROW2__SIO_HYST_EN)
    #define ROW2_SIO_REG_HIFREQ     (* (reg8 *) ROW2__SIO_REG_HIFREQ)
    #define ROW2_SIO_CFG            (* (reg8 *) ROW2__SIO_CFG)
    #define ROW2_SIO_DIFF           (* (reg8 *) ROW2__SIO_DIFF)
#endif /* (ROW2__SIO_CFG) */

/* Interrupt Registers */
#if defined(ROW2__INTSTAT)
    #define ROW2_INTSTAT            (* (reg8 *) ROW2__INTSTAT)
    #define ROW2_SNAP               (* (reg8 *) ROW2__SNAP)
    
	#define ROW2_0_INTTYPE_REG 		(* (reg8 *) ROW2__0__INTTYPE)
#endif /* (ROW2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ROW2_H */


/* [] END OF FILE */
