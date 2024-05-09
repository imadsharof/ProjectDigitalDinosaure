/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"


uint8 rxData;

CY_ISR(isr_uart_Handler){
    uint8 status = 0;
    do{
        // Checks if no UART Rx errors
        status = UART_ReadRxStatus();
        if ((status & UART_RX_STS_PAR_ERROR) || (status & UART_RX_STS_STOP_ERROR) || (status & UART_RX_STS_BREAK) || (status & UART_RX_STS_OVERRUN) ) {
            // Parity, framing, break or overrun error
            // ... process error
            LCD_Position(1,0);
            LCD_PrintString("UART err");
        }
        // Check that rx buffer is not empty and get rx data
        if ( (status & UART_RX_STS_FIFO_NOTEMPTY) != 0){
            rxData = UART_ReadRxData();
            UART_PutChar(rxData);
            LCD_Position(1,0);
            LCD_PrintString("     ");
            LCD_Position(1,0);
            LCD_PutChar(rxData);
            
        }
    }while ((status & UART_RX_STS_FIFO_NOTEMPTY) != 0);
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    //int32 val_adc = 0;
    uint16_t pwm_period = 48000;
    uint32_t val_CMP;
    uint32_t val_adc;
    
    // Start PWM
   
    PWM_Start();
    ADC_StartConvert();
    UART_Start(); //Start the UART
    
    PWM_WritePeriod(pwm_period);
    PWM_WriteCompare(val_CMP); 
    isr_uart_StartEx(isr_uart_Handler);
    
    for(;;)
    {
        /* Place your application code here. */
        if (ADC_IsEndConversion(ADC_RETURN_STATUS)){
            val_adc = ADC_GetResult32();
            val_CMP = ((val_adc /(float)0xFFFF) + 1 ) * 2400; //Conversion from [0x0000,0xFFFF] to [2400,4800] (:= [1,2ms])
            LCD_Position(0,0);
            LCD_PrintNumber(val_CMP);
            PWM_WriteCompare(val_CMP);
            CyDelay(500);
            
        }
        // Read ADC values and light LEDs accordingly, and write PWM accordingly
        
    }
}

/* [] END OF FILE */

