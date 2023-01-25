#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// Interrupt service routine for INT0 (PB2)
ISR (INT0_vect)
{
    DDRB |= (1<<PB1);
    PORTB ^= (1<<PB1);  // turn on LED
}

void init_interrupt() {
  // Configure PB2 as an input and enable the pull-up resistor
  DDRB &= ~(1<<PB2);
  PORTB |= (1<<PB2);

  // Enable external interrupt on PB2
  GIMSK |= (1<<INT0);

  // Set the interrupt to trigger on a falling edge
  MCUCR &= ~(1<<ISC01);
  MCUCR |= (1<<ISC00);
  sei();
}

int main() {
    init_interrupt();
    DDRB = 0b00000001;


    
    while (1) {
        // do nothing, wait for interrupt
    }
}
