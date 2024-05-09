/*******************************************************************************
* File Name: COL2.h  
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

#if !defined(CY_PINS_COL2_H) /* Pins COL2_H */
#define CY_PINS_COL2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "COL2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 COL2__PORT == 15 && ((COL2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    COL2_Write(uint8 value);
void    COL2_SetDriveMode(uint8 mode);
uint8   COL2_ReadDataReg(void);
uint8   COL2_Read(void);
void    COL2_SetInterruptMode(uint16 position, uint16 mode);
uint8   COL2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the COL2_SetDriveMode() function.
     *  @{
     */
        #define COL2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define COL2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define COL2_DM_RES_UP          PIN_DM_RES_UP
        #define COL2_DM_RES_DWN         PIN_DM_RES_DWN
        #define COL2_DM_OD_LO           PIN_DM_OD_LO
        #define COL2_DM_OD_HI           PIN_DM_OD_HI
        #define COL2_DM_STRONG          PIN_DM_STRONG
        #define COL2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define COL2_MASK               COL2__MASK
#define COL2_SHIFT              COL2__SHIFT
#define COL2_WIDTH              1u

/* Interrupt constants */
#if defined(COL2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in COL2_SetInterruptMode() function.
     *  @{
     */
        #define COL2_INTR_NONE      (uint16)(0x0000u)
        #define COL2_INTR_RISING    (uint16)(0x0001u)
        #define COL2_INTR_FALLING   (uint16)(0x0002u)
        #define COL2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define COL2_INTR_MASK      (0x01u) 
#endif /* (COL2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define COL2_PS                     (* (reg8 *) COL2__PS)
/* Data Register */
#define COL2_DR                     (* (reg8 *) COL2__DR)
/* Port Number */
#define COL2_PRT_NUM                (* (reg8 *) COL2__PRT) 
/* Connect to Analog Globals */                                                  
#define COL2_AG                     (* (reg8 *) COL2__AG)                       
/* Analog MUX bux enable */
#define COL2_AMUX                   (* (reg8 *) COL2__AMUX) 
/* Bidirectional Enable */                                                        
#define COL2_BIE                    (* (reg8 *) COL2__BIE)
/* Bit-mask for Aliased Register Access */
#define COL2_BIT_MASK               (* (reg8 *) COL2__BIT_MASK)
/* Bypass Enable */
#define COL2_BYP                    (* (reg8 *) COL2__BYP)
/* Port wide control signals */                                                   
#define COL2_CTL                    (* (reg8 *) COL2__CTL)
/* Drive Modes */
#define COL2_DM0                    (* (reg8 *) COL2__DM0) 
#define COL2_DM1                    (* (reg8 *) COL2__DM1)
#define COL2_DM2                    (* (reg8 *) COL2__DM2) 
/* Input Buffer Disable Override */
#define COL2_INP_DIS                (* (reg8 *) COL2__INP_DIS)
/* LCD Common or Segment Drive */
#define COL2_LCD_COM_SEG            (* (reg8 *) COL2__LCD_COM_SEG)
/* Enable Segment LCD */
#define COL2_LCD_EN                 (* (reg8 *) COL2__LCD_EN)
/* Slew Rate Control */
#define COL2_SLW                    (* (reg8 *) COL2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define COL2_PRTDSI__CAPS_SEL       (* (reg8 *) COL2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define COL2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) COL2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define COL2_PRTDSI__OE_SEL0        (* (reg8 *) COL2__PRTDSI__OE_SEL0) 
#define COL2_PRTDSI__OE_SEL1        (* (reg8 *) COL2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define COL2_PRTDSI__OUT_SEL0       (* (reg8 *) COL2__PRTDSI__OUT_SEL0) 
#define COL2_PRTDSI__OUT_SEL1       (* (reg8 *) COL2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define COL2_PRTDSI__SYNC_OUT       (* (reg8 *) COL2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(COL2__SIO_CFG)
    #define COL2_SIO_HYST_EN        (* (reg8 *) COL2__SIO_HYST_EN)
    #define COL2_SIO_REG_HIFREQ     (* (reg8 *) COL2__SIO_REG_HIFREQ)
    #define COL2_SIO_CFG            (* (reg8 *) COL2__SIO_CFG)
    #define COL2_SIO_DIFF           (* (reg8 *) COL2__SIO_DIFF)
#endif /* (COL2__SIO_CFG) */

/* Interrupt Registers */
#if defined(COL2__INTSTAT)
    #define COL2_INTSTAT            (* (reg8 *) COL2__INTSTAT)
    #define COL2_SNAP               (* (reg8 *) COL2__SNAP)
    
	#define COL2_0_INTTYPE_REG 		(* (reg8 *) COL2__0__INTTYPE)
#endif /* (COL2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_COL2_H */


/* [] END OF FILE */
