/*******************************************************************************
* File Name: COL1.h  
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

#if !defined(CY_PINS_COL1_H) /* Pins COL1_H */
#define CY_PINS_COL1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "COL1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 COL1__PORT == 15 && ((COL1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    COL1_Write(uint8 value);
void    COL1_SetDriveMode(uint8 mode);
uint8   COL1_ReadDataReg(void);
uint8   COL1_Read(void);
void    COL1_SetInterruptMode(uint16 position, uint16 mode);
uint8   COL1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the COL1_SetDriveMode() function.
     *  @{
     */
        #define COL1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define COL1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define COL1_DM_RES_UP          PIN_DM_RES_UP
        #define COL1_DM_RES_DWN         PIN_DM_RES_DWN
        #define COL1_DM_OD_LO           PIN_DM_OD_LO
        #define COL1_DM_OD_HI           PIN_DM_OD_HI
        #define COL1_DM_STRONG          PIN_DM_STRONG
        #define COL1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define COL1_MASK               COL1__MASK
#define COL1_SHIFT              COL1__SHIFT
#define COL1_WIDTH              1u

/* Interrupt constants */
#if defined(COL1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in COL1_SetInterruptMode() function.
     *  @{
     */
        #define COL1_INTR_NONE      (uint16)(0x0000u)
        #define COL1_INTR_RISING    (uint16)(0x0001u)
        #define COL1_INTR_FALLING   (uint16)(0x0002u)
        #define COL1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define COL1_INTR_MASK      (0x01u) 
#endif /* (COL1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define COL1_PS                     (* (reg8 *) COL1__PS)
/* Data Register */
#define COL1_DR                     (* (reg8 *) COL1__DR)
/* Port Number */
#define COL1_PRT_NUM                (* (reg8 *) COL1__PRT) 
/* Connect to Analog Globals */                                                  
#define COL1_AG                     (* (reg8 *) COL1__AG)                       
/* Analog MUX bux enable */
#define COL1_AMUX                   (* (reg8 *) COL1__AMUX) 
/* Bidirectional Enable */                                                        
#define COL1_BIE                    (* (reg8 *) COL1__BIE)
/* Bit-mask for Aliased Register Access */
#define COL1_BIT_MASK               (* (reg8 *) COL1__BIT_MASK)
/* Bypass Enable */
#define COL1_BYP                    (* (reg8 *) COL1__BYP)
/* Port wide control signals */                                                   
#define COL1_CTL                    (* (reg8 *) COL1__CTL)
/* Drive Modes */
#define COL1_DM0                    (* (reg8 *) COL1__DM0) 
#define COL1_DM1                    (* (reg8 *) COL1__DM1)
#define COL1_DM2                    (* (reg8 *) COL1__DM2) 
/* Input Buffer Disable Override */
#define COL1_INP_DIS                (* (reg8 *) COL1__INP_DIS)
/* LCD Common or Segment Drive */
#define COL1_LCD_COM_SEG            (* (reg8 *) COL1__LCD_COM_SEG)
/* Enable Segment LCD */
#define COL1_LCD_EN                 (* (reg8 *) COL1__LCD_EN)
/* Slew Rate Control */
#define COL1_SLW                    (* (reg8 *) COL1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define COL1_PRTDSI__CAPS_SEL       (* (reg8 *) COL1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define COL1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) COL1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define COL1_PRTDSI__OE_SEL0        (* (reg8 *) COL1__PRTDSI__OE_SEL0) 
#define COL1_PRTDSI__OE_SEL1        (* (reg8 *) COL1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define COL1_PRTDSI__OUT_SEL0       (* (reg8 *) COL1__PRTDSI__OUT_SEL0) 
#define COL1_PRTDSI__OUT_SEL1       (* (reg8 *) COL1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define COL1_PRTDSI__SYNC_OUT       (* (reg8 *) COL1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(COL1__SIO_CFG)
    #define COL1_SIO_HYST_EN        (* (reg8 *) COL1__SIO_HYST_EN)
    #define COL1_SIO_REG_HIFREQ     (* (reg8 *) COL1__SIO_REG_HIFREQ)
    #define COL1_SIO_CFG            (* (reg8 *) COL1__SIO_CFG)
    #define COL1_SIO_DIFF           (* (reg8 *) COL1__SIO_DIFF)
#endif /* (COL1__SIO_CFG) */

/* Interrupt Registers */
#if defined(COL1__INTSTAT)
    #define COL1_INTSTAT            (* (reg8 *) COL1__INTSTAT)
    #define COL1_SNAP               (* (reg8 *) COL1__SNAP)
    
	#define COL1_0_INTTYPE_REG 		(* (reg8 *) COL1__0__INTTYPE)
#endif /* (COL1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_COL1_H */


/* [] END OF FILE */
