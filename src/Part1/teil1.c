#include <avr/io.h>
#include <util/delay.h>

int main(){

    DDRB = 0b00010000;

     while (1) {
        PORTB = 0b00010000; //Port 4 high   LED ON
        _delay_ms(2000);    //Wait 2 sec
        PORTB = 0b00000000; // Port 4 Low   LED OFF
        _delay_ms(2000);    // wait 2 sec
    }
    return 0;
}
