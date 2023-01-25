#include <util/delay.h>

int main() {

    DDRB = 0b00010110; // PB1, PB2, PB4 are outputs

    while (1) {
        PORTB = 0b00000100; // Red LED on, yellow and green off
        _delay_ms(3000); // Wait for 3 seconds
        PORTB = 0b00000000;
        _delay_ms(100);
        PORTB = 0b00010100; // Red and yellow LED on, green off
        _delay_ms(1000); // Wait for 1 second
        PORTB = 0b00000000;
        _delay_ms(100);
        PORTB = 0b00000010; // Green LED on, red and yellow off
        _delay_ms(3000); // Wait for 3 seconds
        PORTB = 0b00000000;
        _delay_ms(100);
        PORTB = 0b00010100; // Red and yellow LED on, green off
        _delay_ms(1000); // Wait for 1 second
    }
}
