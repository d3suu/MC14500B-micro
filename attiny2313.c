#ifndef F_CPU
#define F_CPU 20000000UL
#endif

#include <avr/io.h>

void waitForClock(){
	// do nothing until clock line raises
	while(!(PIND & (1<<PD6))){};
}

int main(void){
	//DDRD &= ~(1<<PD6); // PD6 as input, clock
	DDRD = 0x00; // PORTD as input
	/* PD0 - ?
	 * PD1 - ?
	 * PD2 - Instruction LSB
	 * PD3 - Instruction bit 2
	 * PD4 - Instruction bit 3
	 * PD5 - Instruction MSB
	 * PD6 - Clock line
	 */

	DDRB = 0xFF; // PORTB as output
	/* PB0 - Flag F
	 * PB1 - Flag O
	 * PB2 - RTN
	 * PB3 - JMP
	 * PB4 - ?
	 * PB5 - ?
	 * PB6 - ?
	 * PB7 - ?
	 */
	
	uint8_t instruction = 0x00;
	uint8_t skipNextInstruction = 0x00;
	// Registers
	uint8_t RR, Data, IEN, OEN;

	while(1){ // CPU LOOP
	while(!(PIND & (1<<PD6))){ // While clock state is low
		// Restart pins that need restarting due to clock cycle
		PORTB |= (0<<PB3); // JMP
		PORTB |= (0<<PB2); // RTN
		PORTB |= (0<<PB1); // Flag O
		PORTB |= (0<<PB0); // Flag F

		// If last instruction skips next instruction, skip current instruction in clock cycle
		if(skipNextInstruction == 0x01){
			skipNextInstruction = 0x00;
			break;
		}

		// Filter instruction from PORTD[2:5]
		instruction = (PIND & 0b00111100) >> 2;
		switch(instruction){
			case 0x00:
				// NOPO
				PORTB |= (1<<PB1);
				break;
			case 0x01:
				// LD
				break;
			case 0x02:
				// LDC
				break;
			case 0x03:
				// AND
				break;
			case 0x04:
				// ANDC
				break;
			case 0x05:
				// OR
				break;
			case 0x06:
				// ORC
				break;
			case 0x07:
				// XNOR
				break;
			case 0x08:
				// STO
				break;
			case 0x09:
				// STOC
				break;
			case 0x0A:
				// IEN
				break;
			case 0x0B:
				// OEN
				break;
			case 0x0C:
				// JMP
				PORTB |= (1<<PB3);
				break;
			case 0x0D:
				// RTN
				PORTB |= (1<<PB2);
				skipNextInstruction = 0x01;
				break;
			case 0x0E:
				// SKZ
				break;
			case 0x0F:
				// NOPF
				PORTB |= (1<<PB0);
				break;
			default:
				// Soft NOP
				break;
		}

	} else waitForClock();

	// Instruction finished, wait for clock
	waitForClock();
	
	} // END CPU LOOP
}
