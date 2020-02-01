# MC14500B-micro
MC14500B on microcontroller

## Idea
MC14500B running on some sort of microcontroller (preferably ATTiny or maybe PIC). It does not need to be as fast (1MHz) at the beginning, but with some code tweaking i want to be able to do at least 1.2-1.5MHz.
> ***ONLY*** CPU emulation on the uC, no Program Counter, no builtin EEPROM

Inspired by [HACKADAY - WHAT EVERYONE ELSE DID WITH EIGHT BITS, THE GERMANS DID WITH ONLY ONE](https://hackaday.com/2020/02/01/what-everyone-else-did-with-eight-bits-the-germans-did-with-only-one/)

## Documents
 - Datasheet mirrors: 
 [1](https://en.wikichip.org/w/images/5/5b/MC14500B_datasheet.pdf) 
 [2](http://www.brouhaha.com/~eric/retrocomputing/motorola/mc14500b/mc14500brev3.pdf) 
 [3](https://www.alldatasheet.com/datasheet-pdf/pdf/244447/MOTOROLA/MC14500B.html)
 - Programming PIC in C: [instructables PDF](https://cdn.instructables.com/ORIG/FMW/C6LT/IJAEKC37/FMWC6LTIJAEKC37.pdf)

## "Gotcha" things
 - Duration of output spikes: 1 clock step
 - JMP address on output trigger: nowhere, program it yourself

## Microcontroller
 - Thing needed:
   - 7 digital inputs
   - 6 digital outputs (7 if we want pseudo internal clock)
   - 5V input tolerance (EEPROM and clock reading)
 - Candidates:
   - PIC16F84 (Obsolete)
   - PIC16F88
