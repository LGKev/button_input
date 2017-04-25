#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define BV(x) (1<<x)     // shifts bits by x. and sets the bit to 1 or 0 based on x 0 is zero shift, 1st bit.
#define ToggleBit(port, bit) (port ^= (1 << bit) //  toggles the bit


void initIO(void) {
    //set input.
    uint8_t button = 3;
    uint8_t led2 = 2;
    uint8_t led = 4;
//    DDRC &= ~(1 << button);
   DDRC ^= BV(button); //set the pin 3 in DDRC as input;
    DDRC |= BV(led2);
    DDRC |= BV(led); //set pin 4 as output
    
    PORTC ^= BV(button); //don't forget to set as input
    
    for (int i = 0; i<5; i++) {
        PORTC |= (BV(led));//set high
        PORTC |=(BV(led2));
        _delay_ms(80);
        PORTC ^= (BV(led));
        PORTC ^=(BV(led2));
            _delay_ms(80);
    }
}

int main(void) {
    uint8_t button = 3;
    uint8_t led2 = 2;
    uint8_t led = 4;
    
    initIO();
    
    while (1) {
        
        if(bit_is_clear(PINC, button)){ //check while true, as in grounded
            PORTC |= BV(led2);
            _delay_ms(55);
            PORTC ^= BV(led2);
            _delay_ms(55);
        }
        
        //BLINK FOR A LONG DELAY, SEE IF BUTTON IS MEASURED.  or if delay is blocking
        PORTC |= BV(led);
        _delay_ms(400);
        PORTC ^= BV(led);
        _delay_ms(500);
        
        
    }
    return 0; // never reached
}
