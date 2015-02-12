#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

#ifdef __cplusplus
extern "C"{
#endif

// ATMEL ATMEGA1284/1284P
//
//                         +---\/---+
//             (D23) PB0 1 |        | 40 PA0 (D 14) AI 0
//             (D24) PB1 2 |        | 39 PA1 (D 15) AI 1
//        INT2 (D26) PB2 3 |        | 38 PA2 (D 16) AI 2
//      PWM 0A (D25) PB3 4 |        | 37 PA3 (D 17) AI 3
//  PWM 0B/SS (D 10) PB4 5 |        | 36 PA4 (D 18) AI 4
//       MOSI (D 11) PB5 6 |        | 35 PA5 (D 19) AI 5
//PWM 3A/MISO (D 12) PB6 7 |        | 34 PA6 (D 20) AI 6
// PWM 3B/SCK (D 13) PB7 8 |        | 33 PA7 (D 21) AI 7
//                   RST 9 |        | 32 AREF
//                  VCC 10 |        | 31 GND 
//                  GND 11 |        | 30 AVCC
//                XTAL2 12 |        | 29 PC7 (D 29) 
//                XTAL1 13 |        | 28 PC6 (D  8) 
//        RX0 (D 0) PD0 14 |        | 27 PC5 (D  7) TDI
//        TX0 (D 1) PD1 15 |        | 26 PC4 (D  6) TDO
//  INT0 RX1 (D30?) PD2 16 |        | 25 PC3 (D  5) TMS
//  INT1 TX1 (D31?) PD3 17 |        | 24 PC2 (D  4) TCK
//     PWM 1B (D28) PD4 18 |        | 23 PC1 (D  3) SDA
//     PWM 1A (D27) PD5 19 |        | 22 PC0 (D  2) SCL
//     PWM 2B (D 9) PD6 20 |        | 21 PD7 (D 22) PWM 2A
//                         +--------+
//

#define DUINOBOT
#define DUINOBOT_VARIANT SelfDesign

#define NUM_DIGITAL_PINS            32
#define NUM_ANALOG_INPUTS           7
#define analogInputToDigitalPin(p)  ((p < NUM_ANALOG_INPUTS) ? 14 + (p) : -1)

extern const uint8_t digital_pin_to_pcint[NUM_DIGITAL_PINS];
extern const uint16_t __pcmsk[];
extern const uint8_t digital_pin_to_timer_PGM[NUM_DIGITAL_PINS];

#define ifpin(p,what,ifnot)	    (((p) >= 0 && (p) < NUM_DIGITAL_PINS) ? (what) : (ifnot))
#define digitalPinHasPWM(p)         ifpin(p,pgm_read_byte(digital_pin_to_timer_PGM + (p)) != NOT_ON_TIMER,1==0)

#define digitalPinToAnalogPin(p)    ( (p) >= 14 && (p) <= 20 ? (p) - 14 : -1 )
#define analogPinToChannel(p)	    ( (p) < NUM_ANALOG_INPUTS ? /*NUM_ANALOG_INPUTS - 1 -*/ (p) : -1 )

static const uint8_t SS   = 10;
static const uint8_t MOSI = 11;
static const uint8_t MISO = 12;
static const uint8_t SCK  = 13;

static const uint8_t SDA = 3;
static const uint8_t SCL = 2;
static const uint8_t LED = 13;
static const uint8_t LED_BUILTIN = 13;

static const uint8_t A0 = 14;
static const uint8_t A1 = 15;
static const uint8_t A2 = 16;
static const uint8_t A3 = 17;
static const uint8_t A4 = 18;
static const uint8_t A5 = 19;
static const uint8_t A6 = 20;

static const uint8_t BATTERY = 20;
static const uint8_t BILED = 21;
static const uint8_t SPEAKER = 22;

// Motors
static const uint8_t M0_EN = 27;
static const uint8_t M0_D0 = 23;
static const uint8_t M0_D1 = 24;

static const uint8_t M1_EN = 28;
static const uint8_t M1_D0 = 25;
static const uint8_t M1_D1 = 26;

// Run Switch
static const uint8_t RUN_SW = 29;


#define digitalPinToPCICR(p)    ifpin(p,&PCICR,(uint8_t *)0)
#define digitalPinToPCICRbit(P) ifpin(p,digital_pin_to_pcint[p] >> 3,(uint8_t *)0)
#define digitalPinToPCMSK(p)    ifpin(p,__pcmsk[digital_pin_to_pcint[]],(uint8_t *)0)
#define digitalPinToPCMSKbit(p) ifpin(p,digital_pin_to_pcint[p] & 0x7,(uint8_t *)0)

#ifdef ARDUINO_MAIN

#define PA 1
#define PB 2
#define PC 3
#define PD 4

const uint8_t digital_pin_to_pcint[NUM_DIGITAL_PINS] =
{
 24, // D0 PD0
 25, // D1 PD1
 16, // D2 PC0
 17, // D3 PC1
 18, // D4 PC2
 19, // D5 PC3
 20, // D6 PC4
 21, // D7 PC5
 22, // D8 PC6
 30, // D9 PD6
 12, // D10 PB4
 13, // D11 PB5
 14, // D12 PB6
 15, // D13 PB7
  0, // D14 PA0
  1, // D15 PA1
  2, // D16 PA2
  3, // D17 PA3
  4, // D18 PA4
  5, // D19 PA5
  6, // D20 PA6
  7, // D21 PA7
 31, // D22 PD7
  8, // D23 PB0
  9, // D24 PB1
 11, // D25 PB3
 10, // D26 PB2
 29, // D27 PD5
 28, // D28 PD4
 23, // D29 PC7
 26, // D30 PD2 ???
 27, // D31 PD3 ???
};

const uint16_t __pcmsk[] = 
{
  (uint16_t)&PCMSK0, 
  (uint16_t)&PCMSK1, 
  (uint16_t)&PCMSK2, 
  (uint16_t)&PCMSK3
};

// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing)
const uint16_t PROGMEM port_to_mode_PGM[] =
{
	NOT_A_PORT,
	(uint16_t) &DDRA,
	(uint16_t) &DDRB,
	(uint16_t) &DDRC,
	(uint16_t) &DDRD,
};

const uint16_t PROGMEM port_to_output_PGM[] =
{
	NOT_A_PORT,
	(uint16_t) &PORTA,
	(uint16_t) &PORTB,
	(uint16_t) &PORTC,
	(uint16_t) &PORTD,
};

const uint16_t PROGMEM port_to_input_PGM[] =
{
	NOT_A_PORT,
	(uint16_t) &PINA,
	(uint16_t) &PINB,
	(uint16_t) &PINC,
	(uint16_t) &PIND,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[NUM_DIGITAL_PINS] =
{
	PD, // D0 - PD0
	PD, // D1 - PD1
	PC, // D2 - PC0
	PC, // D3 - PC1
	PC, // D4 - PC2
	PC, // D5 - PC3
	PC, // D6 - PC4
	PC, // D7 - PC5
	PC, // D8 - PC6
	PD, // D9 - PD6
	PB, // D10 - SS - PB4
	PB, // D11 - MOSI - PB5
	PB, // D12 - MISO - PB6
	PB, // D13 - SCK - PB7
	PA, // D14 - A0 - PA0
	PA, // D15 - A1 - PA1
	PA, // D16 - A2 - PA2
	PA, // D17 - A3 - PA3
	PA, // D18 - A4 - PA4
	PA, // D19 - A5 - PA5
	PA, // D20 - A6 - PA6 (Battery Status)
	PA, // D21 - BILED - PA7
	PD, // D22 - SPEAKER - PD7
	PB, // D23 - PB0 - M0_D0
	PB, // D24 - PB1 - M0_D1
	PB, // D25 - PB3 - M1_D0
	PB, // D26 - PB2 - M1_D1
	PD, // D27 - PD5 - M0_EN
	PD, // D28 - PD4 - M1_EN
	PC, // D29 - PC7 - RUN_SW
  PD,
  PD,
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[NUM_DIGITAL_PINS] =
{
	_BV(0), // PD0
	_BV(1), // PD1
	_BV(0), // PC0..PC6
	_BV(1),
	_BV(2),
	_BV(3),
	_BV(4),
	_BV(5),
	_BV(6),
	_BV(6), // PD6
	_BV(4), // PB4..PB7
	_BV(5),
	_BV(6),
	_BV(7),
	_BV(0), // PA0..PA6
	_BV(1),
	_BV(2),
	_BV(3),
	_BV(4),
	_BV(5),
	_BV(6),
	_BV(7), // PA7
	_BV(7), // PD7
	_BV(0), // PB0
	_BV(1), // PB1
	_BV(3), // PB3
	_BV(2), // PB2
	_BV(5), // PD5
	_BV(4), // PD4
	_BV(7), // PC7
	_BV(2),
	_BV(3),
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[NUM_DIGITAL_PINS] =
{
	NOT_ON_TIMER, // D0  PD0
	NOT_ON_TIMER, // D1  PD1
	NOT_ON_TIMER, // D2  PC0
	NOT_ON_TIMER, // D3  PC1
	NOT_ON_TIMER, // D4  PC2
	NOT_ON_TIMER, // D5  PC3
	NOT_ON_TIMER, // D6  PC4
	NOT_ON_TIMER, // D7  PC5
	NOT_ON_TIMER, // D8  PC6
	
	TIMER2B,      // D9  PD6
	TIMER0B,      // D10 PB4
	NOT_ON_TIMER, // D11 PB5
	TIMER3A,      // D12 PB6
	TIMER3B,      // D13 PB7
	
	NOT_ON_TIMER, // D14 PA0

	NOT_ON_TIMER, // D15 PA1

	NOT_ON_TIMER, // D16 PA2
	NOT_ON_TIMER, // D17 PA3
	NOT_ON_TIMER, // D18 PA4
	NOT_ON_TIMER, // D19 PA5
	NOT_ON_TIMER, // D20 PA6
	NOT_ON_TIMER, // D21 PA7
	TIMER2A,      // D22 PD7 

	NOT_ON_TIMER, // D23 PB0
	NOT_ON_TIMER, // D24 PB1
	TIMER0A,      // D25 PB3
	NOT_ON_TIMER, // D26 PB2

	TIMER1A,      // D27 PD5
	TIMER1B,      // D28 PD4
	NOT_ON_TIMER, // D29 PC7
	NOT_ON_TIMER,
	NOT_ON_TIMER,
};

#endif // ARDUINO_MAIN

#ifdef __cplusplus
} // extern "C"
#endif


#endif // Pins_Arduino_h
// vim:ai:cin:sts=2 sw=2 ft=cpp
