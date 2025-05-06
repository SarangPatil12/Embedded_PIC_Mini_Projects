/*
 * File:   main.c
 * Author: saran
 *
 * Created on 6 May, 2025, 6:16 PM
 */

#include <xc.h>
#pragma config WDTE = OFF
#define _XTAL_FREQ 4000000  // 4 MHz Clock frequency

void pattern1() {
    for (int i = 0; i < 8; i++) {
        PORTD |= (1 << i);
        __delay_ms(500);
    }
    for (int i = 0; i < 8; i++) {
        PORTD &= ~(1 << i);
        __delay_ms(500);
    }
}

void pattern2() {
    for (int i = 7; i >= 0; i--) {
        PORTD |= (1 << i);
        __delay_ms(500);
    }
    for (int i = 7; i >= 0; i--) {
        PORTD &= ~(1 << i );
        __delay_ms(500);
    }
}

void pattern3() {
    PORTD = 0x55;
    __delay_ms(500);
    PORTD = ~(0x55);
    __delay_ms(500);
}

void pattern4() {
    PORTD = 0x0F;
    __delay_ms(500);
    PORTD = ~(0x0F);
    __delay_ms(500);
}

void main() {
    TRISB = 0x0F;
    TRISD = 0x00;
    PORTD = 0x00;
    
    while(1) {
        if (PORTBbits.RB0 == 0) {
            pattern1();
        }
        else if (PORTBbits.RB1 == 0) {
            pattern2();
        }
        else if (PORTBbits.RB2 == 0) {
            pattern3();
        }
        else if (PORTBbits.RB3 == 0) {
            pattern4();
        }
        else {
            PORTD = 0x00;
        }
    }
}
