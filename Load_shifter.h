#include <stdint.h>

#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "em_usart.h"
#include "em_system.h"
#include "em_timer.h"
#include "caplesenseconfig.h"

#include "caplesense.h"

#include "em_acmp.h"

#include "em_int.h"
#include "em_lesense.h"
#include <string.h>     // required for strlen() function
#include <math.h>
//#iclude "LCD.c" //lcd functions
// port definitions:
#define COM_PORT gpioPortD // USART location #1: PD0 and PD1
#define UART_TX_pin 7      // PD0
#define UART_RX_pin 6      // PD1
#define LED_PORT gpioPortE
#define BTN_PORT gpioPortB

#define LCD_D4 0
#define LCD_D5 1
#define LCD_D6 2
#define LCD_D7 3
#define LCD_EN 4
#define LCD_RS 5
#define LED0 2
#define LED1 3
#define Status 15
//Updated upstream:Load_shifter.h
#define PB0 9
#define PB1 10

extern char rx_char;
// common lines:
#define Recieved (USART1->STATUS & (1 << 7))
#define Button0pressed op0=1 & GPIO_PinInGet(BTN_PORT, PB0)==0 

extern uint8_t completed;
extern char rx_char,Buffer[256];
//=======
//Stashed changes:LCD_40.h

#define SIZE 256

typedef struct{
     char buffer[SIZE];
     int sp;
     } stack_t;
stack_t STACK;     
void LCD_Init1 ( void );
#define LCD_SetPosition(a) LCD_PutCmd( (a) | 0x80)
//void LCD_SetPosition ( unsigned int c );
void LCD_PutCmd ( unsigned int c );
void LCD_PulseEnable ( void );

void upper (unsigned int c);
void lower(unsigned int c);
void LCD_PutChar ( unsigned int c );
void getserial(char *c);
void sendserial(char *c);
typedef struct
{
    uint8_t nr;    // menu nr.
    uint8_t maxch;// max choise
    
} menu_t;  
 uint8_t oc,choice;
 uint8_t current;
 
 typedef struct{
	 uint8_t s;
	 uint8_t m;
	 uint8_t h;
 } time;
 
 extern int32_t power;
 
 typedef struct{
	 char name[16];
	 uint8_t id;
	 uint8_t pow;
	 uint8_t duration;
	 time deadline;
	 time starttime;
	 char status[16];
	 int cost;

 }task;
 
 extern uint8_t nextid;
 
 
 
