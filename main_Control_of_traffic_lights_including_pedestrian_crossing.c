#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// Interrupt service routine for INT0 (PB2)
ISR (INT0_vect)
{
    //DDRB |= (1<<PB1);
    PORTB &= ~(1<<PB0);
    PORTB |= (1<<PB4);
    _delay_ms(1500);
    PORTB &= ~(1<<PB4);
    PORTB |= (1<<PB1);
      // turn on LED
    _delay_ms(3000);
    PORTB &= ~(1<<PB1); // turn off LED
}

void init_interrupt() {
  // Configure PB2 as an input and enable the pull-up resistor
  // DDRB &= ~(1<<PB2);
  // PORTB |= (1<<PB2);

  // Enable external interrupt on PB2
  GIMSK |= (1<<INT0);

  // Set the interrupt to trigger on a falling edge
  MCUCR &= ~(1<<ISC01);
  MCUCR &= ~(1<<ISC00);
  sei();
}

int main() {
    DDRB |= (1<<PB0); // configure PB0 as output
    DDRB |= (1<<PB1);
    DDRB |= (1<<PB4);
    DDRB &= ~(1<<PB2);
    PORTB |= (1<<PB2);
    //PORTB |= (1<<PB0);
    init_interrupt();
    // PORTB &= ~(1<<PB1);
    while (1) {
        PORTB |= (1<<PB0); // toggle LED
        //_delay_ms(500);
    }
}
