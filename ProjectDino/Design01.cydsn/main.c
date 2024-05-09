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
#include <project.h>
#include "keypad.h"

#include <stdio.h>
#include <math.h>
#define PI 3.14
#define N 100

float signalJump[N];
float signalDuck[N];
volatile uint32_t score = 0;            // Variable to store score
volatile uint8_t incrementFlag = 0;     // Variable to store the game status
uint16_t cnt0 = 0;


// Function to initialize peripherals
void initPeripherals() {
    // Initialize components
    
    keypadInit();
    
    LCD_Start();
    LCD_ClearDisplay();
    VDAC8_1_Start();
    //UART_Start();
    //PWM_Start();
    
}

void startTimer(){
    MyTimer_Start(); // Démarrer le Timer
    incrementFlag = 1; // Activer le drapeau d'incrémentation
}

// Function to send messages over UART
void sendUARTMessage(char *message) {
    // Send message over UART
    UART_PutString(message);
}


void sound(int value){
    
    VDAC8_1_SetValue(value);
}


// Function to detect obstacles using photoresistors
void detectObstacles() {
    // Read photoresistors to detect obstacles
    // Perform necessary actions based on obstacle detection
}

// Function to display status and score on the LCD
void display_score(int score) {
    // Clear the LCD screen before updating
    LCD_ClearDisplay();

    // Display the score on the second line (row 1)
    LCD_Position(1, 0);
    LCD_PrintNumber(score);
    
    
}

// Function to display status and score on the LCD
void display_dino_status(const char* status) {
    // Clear the LCD screen before updating
    LCD_ClearDisplay();
    
    // Display "Jump" or "Duck" at the first line (row 0)
    LCD_Position(0, 0);
    LCD_PrintString(status);
    
    LCD_Position(1, 0);
    LCD_PrintNumber(score);
    
}
    

// Function to control servo for jumping
void jump() {
    if (incrementFlag == 0){ // Si l'incrémentation n'a pas encore commencé
        startTimer();
    }
    
    // Control servo to press the spacebar
    //sendUARTMessage("Jump\n");
    display_dino_status("Jump");
    for (int j=0; j<N; j++){
        sound(128 + 128*signalJump[j]);
    }
    
    
    LED1_Write(1);
    LED2_Write(1);
    //PWM_WriteCompare( /* Value for servo control */ );
}



// Function to control servo for ducking
void duck() {
    // Control servo to press the down-arrow key
    //sendUARTMessage("Duck\n");
    
    // Update LCD with score
    display_dino_status("Duck");
    for (int j=0; j<N; j++){
        sound(128 + 128*signalDuck[j]);
    }
    
    LED3_Write(1);
    LED4_Write(1);
    //PWM_WriteCompare( /* Value for servo control */ );
}

// Function to control servo for ducking
void restLeds() {
    LED1_Write(0);
    LED2_Write(0);
    LED3_Write(0);
    LED4_Write(0);
}


void getKeypadEntries(){
    
    //press 8 to jump
    if(keypadScan() == '8' ){
        jump();}
    
    //press 5 to duck
    else if (keypadScan() == '5' ){
        duck();}
}
CY_ISR(myISR){
    if (cnt0 < 1000){
        cnt0++;
    }
    else{
        getKeypadEntries();
        cnt0 = 0; //Reset counter
    }
    
    Timer_keyboard_ISR_ReadStatusRegister();
    
}


int main(void)
{
     // Enable global interrupts.
    CyGlobalIntEnable;
    
    // Initialize peripherals
    initPeripherals();
    isr_StartEx(myISR);
    Timer_keyboard_ISR_Start();
     
    uint16_t cnt = 0;
    
    for (int j=0; j<N; j++){
        signalJump[j] = sin(2*PI*j/N);
        signalDuck[j] = sin(100*PI*j/N);
    }
        
    // Main loop
    for(;;)
    {
        if((0x80 & MyTimer_ReadStatusRegister())&& incrementFlag == 1){ //In case of overflow
                if (cnt < 1000){
                    cnt++;
                }
                else{
                    //un coeficient à ajouter encore #1.5
                    score += 10;
                    display_score(score);
                    cnt = 0; //Reset counter
                }
        }
        // Check for SW1 press to jump
        if(SW1_Read() ==1) {
            jump();
            
        }
        
        // Check for SW2 press to duck
        if(SW2_Read() == 1 && incrementFlag == 1) {
            duck();
            
        }
        
        // Check for SW3 press to reset score and timer
        if(SW3_Read() == 1) {
            score = 0;              //reset score
            cnt = 0;                
            incrementFlag = 0;
            display_score(score);
            MyTimer_Stop();
        }
        
        // Detect obstacles
        detectObstacles();
        
        
        // Add delay or use interrupts as necessary
        //CyDelay(100);
        restLeds();
    }
}




/* [] END OF FILE */

