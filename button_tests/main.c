#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>



#define BV(x) (1<<x)
//#define BV(x) (1<<x) //left shift 1.
#define ToggleBit(port, bit) (port ^= (1 << bit) // toggle the given port from 1 to 0 and 0 to 1

int led =4;
int button =3;
int led2 = 2;

void initIO(void) {
	//set input.
    DDRC ^= BV(button); //set the pin 3 in DDRC as input;
    DDRC |= BV(led2)
    DDRC |= BV(led); //set pin 4 as output
    
    for (int i = 0; i<5; i++) {g        PORTC |= BV(led);//set high
        _delay_ms(500);
        PORTC ^= BV(led);
        _delay_ms(500);
        PORTC =BV(led2);
        _delay_ms(100);
        PORTC ^=BV(led2);
        _delay_ms(100);
    }
}

int main(void) {
	initIO();

	while (1) {
        
        while(bit_is_clear(PINC, button)){ //check while true, as in grounded
            PORTC |= BV(led2);
            _delay_ms(75);
            PORTC |= BV(led2);
            _delay_ms(75);
        }
        
        //BLINK FOR A LONG DELAY, SEE IF BUTTON IS MEASURED.  or if delay is blocking
        PORTC |= BV(led);
        _delay_ms(4000);
        PORTC ^= BV(led);
        _delay_ms(5000);
        
        
	}
	return 0; // never reached
}
