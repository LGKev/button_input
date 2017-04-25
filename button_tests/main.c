#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define BV(x) (1<<x)     // shifts bits by x. and sets the bit to 1 or 0 based on x 0 is zero shift, 1st bit.
#define ToggleBit(port, bit) (port ^= (1 << bit) //  toggles the bit


int main(void) {
    uint8_t button = 3;
    uint8_t led2 = 2;
    uint8_t led = 4;
    
 

        //set input.
        DDRC ^= BV(button); //set the pin 3 in DDRC as input;
        DDRC |= BV(led2);
        DDRC |= BV(led); //set pin 4 as output
        
        for (int i = 0; i<5; i++) {
            PORTC|= BV(led);//set high
            _delay_ms(500);
            PORTC ^= BV(led);
            _delay_ms(500);
            PORTC =BV(led2);
            _delay_ms(100);
            PORTC ^=BV(led2);
            _delay_ms(100);
        

  
    }
    
    while (1) {
        
        if(bit_is_clear(PINC, button)){ //check while true, as in grounded
            for (int i = 0; i<5; i++) {
                PORTC|= BV(led);//set high
                _delay_ms(75);
                PORTC ^= BV(led);
                _delay_ms(75);
            }}
        
        //BLINK FOR A LONG DELAY, SEE IF BUTTON IS MEASURED.  or if delay is blocking
        PORTC |= BV(led);
        _delay_ms(4000);
        PORTC ^= BV(led);
        _delay_ms(5000);
        
        
    }
    return 0; // never reached
}
