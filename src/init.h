#ifndef __INIT_H
#define __INIT_H
#include "stm8s.h"
/* Private typedef -----------------------------------------------------------*/
#define ADC
#define PUTCHAR_PROTOTYPE int putchar (int c)
#define GETCHAR_PROTOTYPE int getchar (void)
/* Private define ------------------------------------------------------------*/
#define LED_GPIO_PORT  (GPIOC)              //port use to turn on/off module SIM
#define LED_GPIO_PINS  (GPIO_PIN_3)         //pin use to turn on/off module SIM
#define TDS_GPIO_PORT  (GPIOD)              //port use to turn on/off module SIM
#define TDS_GPIO_PIN   (GPIO_PIN_2)         //pin use to turn on/off module SIM
#define TIM4_PERIOD       124               //1ms
#define UART_BUFFER 160                     //255 charactor for UART buffer
#define TDS_LIMIT 500                       //watermark value for TDS
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
#define VREF 3.3                            // analog reference voltage(Volt) of the ADC
#define SCOUNT  30                          // sum of sample point

#define TDS_MEASURE_REPEAT 10               //repeat measuring TDS n times to make sure the water is really dirty

#define TDS_OVER_RANGE 0                    //tds over safe range
#define TDS_UNDER_RANGE 1                   //tds probe is probably not plugged into water

void CLK_Config(void);                     //config cpu clock
void UART1_Config(void);                   //config uC with SIM communication
void TIM4_Config(void);                    //config timer
void GPIO_Config(void);                    //config GPIO
void ADC_Config(void);                     //config ADC to measure TDS
int getMedianNum(int*);                    //median value of TDS
void inform_customer(void);                //inform customer if TDS value over range or tds probe is not plugged into water
void booting(void);
void TimingDelay_Decrement(void);
void delay(__IO uint32_t);
void blink_led(uint8_t, uint32_t);
uint16_t read_tds(void);                   //read TDS value from TDS sensor
#endif /* __INIT_H */