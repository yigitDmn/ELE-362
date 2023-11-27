#ifndef NOKIA_3310_H
#define NOKIA_3310_H

#include "stm32f4xx_hal.h"
#include "dwt_delay.h"

 void NOKIA_Init(void);
 void NOKIA_Clear(void);
 void NOKIA_Write_Command(char NOKIA_command);
 void NOKIA_Write_Data(char NOKIA_data);
 void NOKIA_Write_Byte(char byteforNOKIA);
 void NOKIA_Goto_xy(char xNOKIA, char yNOKIA);
 void NOKIA_Goto_pixel(char xNOKIA,char yNOKIA); 
 void NOKIA_Contrast(char contrast);
 void NOKIA_Out(char xNOKIA,char yNOKIA, const char *s);
 void NOKIA_Chr(char xNOKIA,char yNOKIA, char charsel);
 void NOKIA_Dot(char xNOKIA, char yNOKIA);
 void NOKIA_Image(const char *image);
 void NOKIA_Partial_Image(char xNOKIA, char yNOKIA,char xImage,char array_length, const char *image);

//#define SCE_Pin GPIO_PIN_4
//#define SCE_GPIO_Port GPIOA
//#define SCLK_Pin GPIO_PIN_5
//#define SCLK_GPIO_Port GPIOA
//#define SDIN_Pin GPIO_PIN_7
//#define SDIN_GPIO_Port GPIOA
//#define RES_Pin GPIO_PIN_13
//#define RES_GPIO_Port GPIOA
//#define DC_Pin GPIO_PIN_14
//#define DC_GPIO_Port GPIOA

//extern sbit RES ;
//extern sbit SCE ;
//extern sbit DC  ;
//extern sbit SDIN;
//extern sbit SCLK;

/*extern sfr sbit nok_res_dir ;
extern sfr sbit nok_sce_dir ;
extern sfr sbit nok_dc_dir  ;
extern sfr sbit nok_sdin_dir;
extern sfr sbit nok_sclk_dir;*/

#endif
