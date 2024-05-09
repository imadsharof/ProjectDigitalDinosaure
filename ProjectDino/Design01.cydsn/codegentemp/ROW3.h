/*******************************************************************************
* File Name: ROW3.h  
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

#if !defined(CY_PINS_ROW3_H) /* Pins ROW3_H */
#define CY_PINS_ROW3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ROW3_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ROW3__PORT == 15 && ((ROW3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    ROW3_Write(uint8 value);
void    ROW3_SetDriveMode(uint8 mode);
uint8   ROW3_ReadDataReg(void);
uint8   ROW3_Read(void);
void    ROW3_SetInterruptMode(uint16 position, uint16 mode);
uint8   ROW3_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the ROW3_SetDriveMode() function.
     *  @{
     */
        #define ROW3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define ROW3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define ROW3_DM_RES_UP          PIN_DM_RES_UP
        #define ROW3_DM_RES_DWN         PIN_DM_RES_DWN
        #define ROW3_DM_OD_LO           PIN_DM_OD_LO
        #define ROW3_DM_OD_HI           PIN_DM_OD_HI
        #define ROW3_DM_STRONG          PIN_DM_STRONG
        #define ROW3_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define ROW3_MASK               ROW3__MASK
#define ROW3_SHIFT              ROW3__SHIFT
#define ROW3_WIDTH              1u

/* Interrupt constants */
#if defined(ROW3__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ROW3_SetInterruptMode() function.
     *  @{
     */
        #define ROW3_INTR_NONE      (uint16)(0x0000u)
        #define ROW3_INTR_RISING    (uint16)(0x0001u)
        #define ROW3_INTR_FALLING   (uint16)(0x0002u)
        #define ROW3_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define ROW3_INTR_MASK      (0x01u) 
#endif /* (ROW3__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ROW3_PS                     (* (reg8 *) ROW3__PS)
/* Data Register */
#define ROW3_DR                     (* (reg8 *) ROW3__DR)
/* Port Number */
#define ROW3_PRT_NUM                (* (reg8 *) ROW3__PRT) 
/* Connect to Analog Globals */                                                  
#define ROW3_AG                     (* (reg8 *) ROW3__AG)                       
/* Analog MUX bux enable */
#define ROW3_AMUX                   (* (reg8 *) ROW3__AMUX) 
/* Bidirectional Enable */                                                        
#define ROW3_BIE                    (* (reg8 *) ROW3__BIE)
/* Bit-mask for Aliased Register Access */
#define ROW3_BIT_MASK               (* (reg8 *) ROW3__BIT_MASK)
/* Bypass Enable */
#define ROW3_BYP                    (* (reg8 *) ROW3__BYP)
/* Port wide control signals */                                                   
#define ROW3_CTL                    (* (reg8 *) ROW3__CTL)
/* Drive Modes */
#define ROW3_DM0                    (* (reg8 *) ROW3__DM0) 
#define ROW3_DM1                    (* (reg8 *) ROW3__DM1)
#define ROW3_DM2                    (* (reg8 *) ROW3__DM2) 
/* Input Buffer Disable Override */
#define ROW3_INP_DIS                (* (reg8 *) ROW3__INP_DIS)
/* LCD Common or Segment Drive */
#define ROW3_LCD_COM_SEG            (* (reg8 *) ROW3__LCD_COM_SEG)
/* Enable Segment LCD */
#define ROW3_LCD_EN                 (* (reg8 *) ROW3__LCD_EN)
/* Slew Rate Control */
#define ROW3_SLW                    (* (reg8 *) ROW3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ROW3_PRTDSI__CAPS_SEL       (* (reg8 *) ROW3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ROW3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ROW3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ROW3_PRTDSI__OE_SEL0        (* (reg8 *) ROW3__PRTDSI__OE_SEL0) 
#define ROW3_PRTDSI__OE_SEL1        (* (reg8 *) ROW3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ROW3_PRTDSI__OUT_SEL0       (* (reg8 *) ROW3__PRTDSI__OUT_SEL0) 
#define ROW3_PRTDSI__OUT_SEL1       (* (reg8 *) ROW3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ROW3_PRTDSI__SYNC_OUT       (* (reg8 *) ROW3__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(ROW3__SIO_CFG)
    #define ROW3_SIO_HYST_EN        (* (reg8 *) ROW3__SIO_HYST_EN)
    #define ROW3_SIO_REG_HIFREQ     (* (reg8 *) ROW3__SIO_REG_HIFREQ)
    #define ROW3_SIO_CFG            (* (reg8 *) ROW3__SIO_CFG)
    #define ROW3_SIO_DIFF           (* (reg8 *) ROW3__SIO_DIFF)
#endif /* (ROW3__SIO_CFG) */

/* Interrupt Registers */
#if defined(ROW3__INTSTAT)
    #define ROW3_INTSTAT            (* (reg8 *) ROW3__INTSTAT)
    #define ROW3_SNAP               (* (reg8 *) ROW3__SNAP)
    
	#define ROW3_0_INTTYPE_REG 		(* (reg8 *) ROW3__0__INTTYPE)
#endif /* (ROW3__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ROW3_H */


/* [] END OF FILE */
