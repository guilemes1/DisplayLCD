/*
 * File:   main.c
 * Author: 20185189
 *
 * Created on 16 de Abril de 2021, 16:35
 */

#include "config.h"
#define _XTAL_FREQ 4000000
#include <xc.h>

#define DADOS   PORTB
#define EN      PORTDbits.RD7
#define RS      PORTDbits.RD6

void LCD_init (void)
{
    TRISDbits.TRISD6 = 0;
    TRISDbits.TRISD7 = 0;
    ANSELH = 0;
    TRISB = 0x00;
    
    DADOS = 0X00;
    EN = 1;
    RS = 0;
}

void LCD_on (void)
{
    RS = 0;
    EN = 1;
    DADOS = 0x0F;
    EN = 0;
    __delay_us(40);
    EN = 1;
}

void LCD_lincol (char lin, char col)
{
    RS = 0;
    EN = 1;
    DADOS = 0x80 + ((lin*40) + col);
    EN = 0;
    __delay_us(40);
    EN = 1;         
}

void LCD_printChar (char c)
{
    RS = 1;                //PERMITE O ENVIO DE DADOS
    DADOS = c;
    EN = 0;
    __delay_us(40);
    EN = 1;         
}

void LCD_print ( char * str)
{
    char i = 0;
    
    while( *(str+i) != 0 )
    {   
        if( *(str+i) == 0 )
            LCD_lincol(1,0);
        else            
        {    
            if( i == 16 )
                LCD_lincol(1,0);
                        
            LCD_printChar( *(str+i) );
        }    
        i++;
    }
}

void main(void) 
{
    LCD_init();
    LCD_on();
    LCD_print("ARRI EGUA!");
    
    while(1)
    {
    
    }    
}
