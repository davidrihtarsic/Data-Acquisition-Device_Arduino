#!/usr/bin/env python
#[IOEXT]

PINB = 0x03 + 0x20
PINB0 = 0
PINB1 = 1
PINB2 = 2
PINB3 = 3
PINB4 = 4
PINB5 = 5
PINB6 = 6
PINB7 = 7

DDRB = 0x04 + 0x20
DDB0 = 0
DDB1 = 1
DDB2 = 2
DDB3 = 3
DDB4 = 4
DDB5 = 5
DDB6 = 6
DDB7 = 7

PORTB = 0x05 + 0x20
PORTB0 = 0
PORTB1 = 1
PORTB2 = 2
PORTB3 = 3
PORTB4 = 4
PORTB5 = 5
PORTB6 = 6
PORTB7 = 7

PINC = 0x06 + 0x20
PINC0 = 0
PINC1 = 1
PINC2 = 2
PINC3 = 3
PINC4 = 4
PINC5 = 5
PINC6 = 6

DDRC = 0x07 + 0x20
DDC0 = 0
DDC1 = 1
DDC2 = 2
DDC3 = 3
DDC4 = 4
DDC5 = 5
DDC6 = 6

PORTC = 0x08 + 0x20
PORTC0 = 0
PORTC1 = 1
PORTC2 = 2
PORTC3 = 3
PORTC4 = 4
PORTC5 = 5
PORTC6 = 6

PIND = 0x09 + 0x20
PIND0 = 0
PIND1 = 1
PIND2 = 2
PIND3 = 3
PIND4 = 4
PIND5 = 5
PIND6 = 6
PIND7 = 7

DDRD = 0x0A + 0x20
DDD0 = 0
DDD1 = 1
DDD2 = 2
DDD3 = 3
DDD4 = 4
DDD5 = 5
DDD6 = 6
DDD7 = 7

PORTD = 0x0B + 0x20
PORTD0 = 0
PORTD1 = 1
PORTD2 = 2
PORTD3 = 3
PORTD4 = 4
PORTD5 = 5
PORTD6 = 6
PORTD7 = 7

TIFR0 = 0x15 + 0x20
TOV0 = 0
OCF0A = 1
OCF0B = 2

TIFR1 = 0x16 + 0x20
TOV1 = 0
OCF1A = 1
OCF1B = 2
ICF1 = 5

TIFR2 = 0x17 + 0x20
TOV2 = 0
OCF2A = 1
OCF2B = 2

PCIFR = 0x1B + 0x20
PCIF0 = 0
PCIF1 = 1
PCIF2 = 2

EIFR = 0x1C + 0x20
INTF0 = 0
INTF1 = 1

EIMSK = 0x1D + 0x20
INT0 = 0
INT1 = 1

GPIOR0 = 0x1E + 0x20
GPIOR00 = 0
GPIOR01 = 1
GPIOR02 = 2
GPIOR03 = 3
GPIOR04 = 4
GPIOR05 = 5
GPIOR06 = 6
GPIOR07 = 7

EECR = 0x1F + 0x20
EERE = 0
EEPE = 1
EEMPE = 2
EERIE = 3
EEPM0 = 4
EEPM1 = 5

EEDR = 0x20 + 0x20
EEDR0 = 0
EEDR1 = 1
EEDR2 = 2
EEDR3 = 3
EEDR4 = 4
EEDR5 = 5
EEDR6 = 6
EEDR7 = 7

#EEAR = _SFR_IO16(0x21)

EEARL = 0x21 + 0x20
EEAR0 = 0
EEAR1 = 1
EEAR2 = 2
EEAR3 = 3
EEAR4 = 4
EEAR5 = 5
EEAR6 = 6
EEAR7 = 7

EEARH = 0x22 + 0x20
EEAR8 = 0
EEAR9 = 1

#_EEPROM_REG_LOCATIONS_ = 1F2021

GTCCR = 0x23 + 0x20
PSRSYNC = 0
PSRASY = 1
TSM = 7

TCCR0A = 0x24 + 0x20
WGM00 = 0
WGM01 = 1
COM0B0 = 4
COM0B1 = 5
COM0A0 = 6
COM0A1 = 7

TCCR0B = 0x25 + 0x20
CS00 = 0
CS01 = 1
CS02 = 2
WGM02 = 3
FOC0B = 6
FOC0A = 7

TCNT0 = 0x26 + 0x20
TCNT0_0 = 0
TCNT0_1 = 1
TCNT0_2 = 2
TCNT0_3 = 3
TCNT0_4 = 4
TCNT0_5 = 5
TCNT0_6 = 6
TCNT0_7 = 7

OCR0A = 0x27 + 0x20
OCR0A_0 = 0
OCR0A_1 = 1
OCR0A_2 = 2
OCR0A_3 = 3
OCR0A_4 = 4
OCR0A_5 = 5
OCR0A_6 = 6
OCR0A_7 = 7

OCR0B = 0x28 + 0x20
OCR0B_0 = 0
OCR0B_1 = 1
OCR0B_2 = 2
OCR0B_3 = 3
OCR0B_4 = 4
OCR0B_5 = 5
OCR0B_6 = 6
OCR0B_7 = 7

GPIOR1 = 0x2A + 0x20
GPIOR10 = 0
GPIOR11 = 1
GPIOR12 = 2
GPIOR13 = 3
GPIOR14 = 4
GPIOR15 = 5
GPIOR16 = 6
GPIOR17 = 7

GPIOR2 = 0x2B + 0x20
GPIOR20 = 0
GPIOR21 = 1
GPIOR22 = 2
GPIOR23 = 3
GPIOR24 = 4
GPIOR25 = 5
GPIOR26 = 6
GPIOR27 = 7

SPCR = 0x2C + 0x20
SPR0 = 0
SPR1 = 1
CPHA = 2
CPOL = 3
MSTR = 4
DORD = 5
SPE = 6
SPIE = 7

SPSR = 0x2D + 0x20
SPI2X = 0
WCOL = 6
SPIF = 7

SPDR = 0x2E + 0x20
SPDR0 = 0
SPDR1 = 1
SPDR2 = 2
SPDR3 = 3
SPDR4 = 4
SPDR5 = 5
SPDR6 = 6
SPDR7 = 7

ACSR = 0x30 + 0x20
ACIS0 = 0
ACIS1 = 1
ACIC = 2
ACIE = 3
ACI = 4
ACO = 5
ACBG = 6
ACD = 7

SMCR = 0x33 + 0x20
SE = 0
SM0 = 1
SM1 = 2
SM2 = 3

MCUSR = 0x34 + 0x20
PORF = 0
EXTRF = 1
BORF = 2
WDRF = 3

MCUCR = 0x35 + 0x20
IVCE = 0
IVSEL = 1
PUD = 4
BODSE = 5
BODS = 6

SPMCSR = 0x37 + 0x20
SELFPRGEN = 0 #	only for backwards compatibility with previous
		      # avr-libc versions; not an official name """
SPMEN = 0
PGERS = 1
PGWRT = 2
BLBSET = 3
RWWSRE = 4
SIGRD = 5
RWWSB = 6
SPMIE = 7

WDTCSR = 0x60
WDP0 = 0
WDP1 = 1
WDP2 = 2
WDE = 3
WDCE = 4
WDP3 = 5
WDIE = 6
WDIF = 7

CLKPR = 0x61
CLKPS0 = 0
CLKPS1 = 1
CLKPS2 = 2
CLKPS3 = 3
CLKPCE = 7

PRR = 0x64
PRADC = 0
PRUSART0 = 1
PRSPI = 2
PRTIM1 = 3
PRTIM0 = 5
PRTIM2 = 6
PRTWI = 7

#__AVR_HAVE_PRR =	((1<<PRADC)|(1<<PRUSART0)|(1<<PRSPI)|(1<<PRTIM1)|(1<<PRTIM0)|(1<<PRTIM2)|(1<<PRTWI))
#__AVR_HAVE_PRR_PRADC =
#__AVR_HAVE_PRR_PRUSART0 =
#__AVR_HAVE_PRR_PRSPI =
#__AVR_HAVE_PRR_PRTIM1 =
#__AVR_HAVE_PRR_PRTIM0 =
#__AVR_HAVE_PRR_PRTIM2 =
#__AVR_HAVE_PRR_PRTWI =

OSCCAL = 0x66
CAL0 = 0
CAL1 = 1
CAL2 = 2
CAL3 = 3
CAL4 = 4
CAL5 = 5
CAL6 = 6
CAL7 = 7

PCICR = 0x68
PCIE0 = 0
PCIE1 = 1
PCIE2 = 2

EICRA = 0x69
ISC00 = 0
ISC01 = 1
ISC10 = 2
ISC11 = 3

PCMSK0 = 0x6B
PCINT0 = 0
PCINT1 = 1
PCINT2 = 2
PCINT3 = 3
PCINT4 = 4
PCINT5 = 5
PCINT6 = 6
PCINT7 = 7

PCMSK1 = 0x6C
PCINT8 = 0
PCINT9 = 1
PCINT10 = 2
PCINT11 = 3
PCINT12 = 4
PCINT13 = 5
PCINT14 = 6

PCMSK2 = 0x6D
PCINT16 = 0
PCINT17 = 1
PCINT18 = 2
PCINT19 = 3
PCINT20 = 4
PCINT21 = 5
PCINT22 = 6
PCINT23 = 7

TIMSK0 = 0x6E
TOIE0 = 0
OCIE0A = 1
OCIE0B = 2

TIMSK1 = 0x6F
TOIE1 = 0
OCIE1A = 1
OCIE1B = 2
ICIE1 = 5

TIMSK2 = 0x70
TOIE2 = 0
OCIE2A = 1
OCIE2B = 2

#ifndef __ASSEMBLER__
#ADC =     _SFR_MEM16(0x78)
#endif
#ADCW =    _SFR_MEM16(0x78)

ADCL = 0x78
ADCL0 = 0
ADCL1 = 1
ADCL2 = 2
ADCL3 = 3
ADCL4 = 4
ADCL5 = 5
ADCL6 = 6
ADCL7 = 7

ADCH = 0x79
ADCH0 = 0
ADCH1 = 1
ADCH2 = 2
ADCH3 = 3
ADCH4 = 4
ADCH5 = 5
ADCH6 = 6
ADCH7 = 7

ADCSRA = 0x7A
ADPS0 = 0
ADPS1 = 1
ADPS2 = 2
ADIE = 3
ADIF = 4
ADATE = 5
ADSC = 6
ADEN = 7

ADCSRB = 0x7B
ADTS0 = 0
ADTS1 = 1
ADTS2 = 2
ACME = 6

ADMUX = 0x7C
MUX0 = 0
MUX1 = 1
MUX2 = 2
MUX3 = 3
ADLAR = 5
REFS0 = 6
REFS1 = 7

DIDR0 = 0x7E
ADC0D = 0
ADC1D = 1
ADC2D = 2
ADC3D = 3
ADC4D = 4
ADC5D = 5

DIDR1 = 0x7F
AIN0D = 0
AIN1D = 1

TCCR1A = 0x80
WGM10 = 0
WGM11 = 1
COM1B0 = 4
COM1B1 = 5
COM1A0 = 6
COM1A1 = 7

TCCR1B = 0x81
CS10 = 0
CS11 = 1
CS12 = 2
WGM12 = 3
WGM13 = 4
ICES1 = 6
ICNC1 = 7

TCCR1C = 0x82
FOC1B = 6
FOC1A = 7

#TCNT1 = _SFR_MEM16(0x84)

TCNT1L = 0x84
TCNT1L0 = 0
TCNT1L1 = 1
TCNT1L2 = 2
TCNT1L3 = 3
TCNT1L4 = 4
TCNT1L5 = 5
TCNT1L6 = 6
TCNT1L7 = 7

TCNT1H = 0x85
TCNT1H0 = 0
TCNT1H1 = 1
TCNT1H2 = 2
TCNT1H3 = 3
TCNT1H4 = 4
TCNT1H5 = 5
TCNT1H6 = 6
TCNT1H7 = 7

#ICR1 = _SFR_MEM16(0x86)

ICR1L = 0x86
ICR1L0 = 0
ICR1L1 = 1
ICR1L2 = 2
ICR1L3 = 3
ICR1L4 = 4
ICR1L5 = 5
ICR1L6 = 6
ICR1L7 = 7

ICR1H = 0x87
ICR1H0 = 0
ICR1H1 = 1
ICR1H2 = 2
ICR1H3 = 3
ICR1H4 = 4
ICR1H5 = 5
ICR1H6 = 6
ICR1H7 = 7

#OCR1A = _SFR_MEM16(0x88)

OCR1AL = 0x88
OCR1AL0 = 0
OCR1AL1 = 1
OCR1AL2 = 2
OCR1AL3 = 3
OCR1AL4 = 4
OCR1AL5 = 5
OCR1AL6 = 6
OCR1AL7 = 7

OCR1AH = 0x89
OCR1AH0 = 0
OCR1AH1 = 1
OCR1AH2 = 2
OCR1AH3 = 3
OCR1AH4 = 4
OCR1AH5 = 5
OCR1AH6 = 6
OCR1AH7 = 7

#OCR1B = _SFR_MEM16(0x8A)

OCR1BL = 0x8A
OCR1BL0 = 0
OCR1BL1 = 1
OCR1BL2 = 2
OCR1BL3 = 3
OCR1BL4 = 4
OCR1BL5 = 5
OCR1BL6 = 6
OCR1BL7 = 7

OCR1BH = 0x8B
OCR1BH0 = 0
OCR1BH1 = 1
OCR1BH2 = 2
OCR1BH3 = 3
OCR1BH4 = 4
OCR1BH5 = 5
OCR1BH6 = 6
OCR1BH7 = 7

TCCR2A = 0xB0
WGM20 = 0
WGM21 = 1
COM2B0 = 4
COM2B1 = 5
COM2A0 = 6
COM2A1 = 7

TCCR2B = 0xB1
CS20 = 0
CS21 = 1
CS22 = 2
WGM22 = 3
FOC2B = 6
FOC2A = 7

TCNT2 = 0xB2
TCNT2_0 = 0
TCNT2_1 = 1
TCNT2_2 = 2
TCNT2_3 = 3
TCNT2_4 = 4
TCNT2_5 = 5
TCNT2_6 = 6
TCNT2_7 = 7

OCR2A = 0xB3
OCR2_0 = 0
OCR2_1 = 1
OCR2_2 = 2
OCR2_3 = 3
OCR2_4 = 4
OCR2_5 = 5
OCR2_6 = 6
OCR2_7 = 7

OCR2B = 0xB4
OCR2_0 = 0
OCR2_1 = 1
OCR2_2 = 2
OCR2_3 = 3
OCR2_4 = 4
OCR2_5 = 5
OCR2_6 = 6
OCR2_7 = 7

ASSR = 0xB6
TCR2BUB = 0
TCR2AUB = 1
OCR2BUB = 2
OCR2AUB = 3
TCN2UB = 4
AS2 = 5
EXCLK = 6

TWBR = 0xB8
TWBR0 = 0
TWBR1 = 1
TWBR2 = 2
TWBR3 = 3
TWBR4 = 4
TWBR5 = 5
TWBR6 = 6
TWBR7 = 7

TWSR = 0xB9
TWPS0 = 0
TWPS1 = 1
TWS3 = 3
TWS4 = 4
TWS5 = 5
TWS6 = 6
TWS7 = 7

TWAR = 0xBA
TWGCE = 0
TWA0 = 1
TWA1 = 2
TWA2 = 3
TWA3 = 4
TWA4 = 5
TWA5 = 6
TWA6 = 7

TWDR = 0xBB
TWD0 = 0
TWD1 = 1
TWD2 = 2
TWD3 = 3
TWD4 = 4
TWD5 = 5
TWD6 = 6
TWD7 = 7

TWCR = 0xBC
TWIE = 0
TWEN = 2
TWWC = 3
TWSTO = 4
TWSTA = 5
TWEA = 6
TWINT = 7

TWAMR = 0xBD
TWAM0 = 0
TWAM1 = 1
TWAM2 = 2
TWAM3 = 3
TWAM4 = 4
TWAM5 = 5
TWAM6 = 6

UCSR0A = 0xC0
MPCM0 = 0
U2X0 = 1
UPE0 = 2
DOR0 = 3
FE0 = 4
UDRE0 = 5
TXC0 = 6
RXC0 = 7

UCSR0B = 0xC1
TXB80 = 0
RXB80 = 1
UCSZ02 = 2
TXEN0 = 3
RXEN0 = 4
UDRIE0 = 5
TXCIE0 = 6
RXCIE0 = 7

UCSR0C = 0xC2
UCPOL0 = 0
UCSZ00 = 1
UCPHA0 = 1
UCSZ01 = 2
UDORD0 = 2
USBS0 = 3
UPM00 = 4
UPM01 = 5
UMSEL00 = 6
UMSEL01 = 7

#UBRR0 = _SFR_MEM16(0xC4)

UBRR0L = 0xC4
UBRR0_0 = 0
UBRR0_1 = 1
UBRR0_2 = 2
UBRR0_3 = 3
UBRR0_4 = 4
UBRR0_5 = 5
UBRR0_6 = 6
UBRR0_7 = 7

UBRR0H = 0xC5
UBRR0_8 = 0
UBRR0_9 = 1
UBRR0_10 = 2
UBRR0_11 = 3

UDR0 = 0xC6
UDR0_0 = 0
UDR0_1 = 1
UDR0_2 = 2
UDR0_3 = 3
UDR0_4 = 4
UDR0_5 = 5
UDR0_6 = 6
UDR0_7 = 7


"""
/* Interrupt Vectors */
/* Interrupt Vector 0 is the reset vector. */

INT0_vect_num =     1
INT0_vect =         _VECTOR(1)   /* External Interrupt Request 0 */

INT1_vect_num =     2
INT1_vect =         _VECTOR(2)   /* External Interrupt Request 1 */

PCINT0_vect_num =   3
PCINT0_vect =       _VECTOR(3)   /* Pin Change Interrupt Request 0 */

PCINT1_vect_num =   4
PCINT1_vect =       _VECTOR(4)   /* Pin Change Interrupt Request 0 */

PCINT2_vect_num =   5
PCINT2_vect =       _VECTOR(5)   /* Pin Change Interrupt Request 1 */

WDT_vect_num =      6
WDT_vect =          _VECTOR(6)   /* Watchdog Time-out Interrupt */

TIMER2_COMPA_vect_num = 7
TIMER2_COMPA_vect = _VECTOR(7)   /* Timer/Counter2 Compare Match A */

TIMER2_COMPB_vect_num = 8
TIMER2_COMPB_vect = _VECTOR(8)   /* Timer/Counter2 Compare Match A */

TIMER2_OVF_vect_num =   9
TIMER2_OVF_vect =   _VECTOR(9)   /* Timer/Counter2 Overflow */

TIMER1_CAPT_vect_num =  10
TIMER1_CAPT_vect =  _VECTOR(10)  /* Timer/Counter1 Capture Event */

TIMER1_COMPA_vect_num = 11
TIMER1_COMPA_vect = _VECTOR(11)  /* Timer/Counter1 Compare Match A */

TIMER1_COMPB_vect_num = 12
TIMER1_COMPB_vect = _VECTOR(12)  /* Timer/Counter1 Compare Match B */ 

TIMER1_OVF_vect_num =   13
TIMER1_OVF_vect =   _VECTOR(13)  /* Timer/Counter1 Overflow */

TIMER0_COMPA_vect_num = 14
TIMER0_COMPA_vect = _VECTOR(14)  /* TimerCounter0 Compare Match A */

TIMER0_COMPB_vect_num = 15
TIMER0_COMPB_vect = _VECTOR(15)  /* TimerCounter0 Compare Match B */

TIMER0_OVF_vect_num =  16
TIMER0_OVF_vect =   _VECTOR(16)  /* Timer/Couner0 Overflow */

SPI_STC_vect_num =  17
SPI_STC_vect =      _VECTOR(17)  /* SPI Serial Transfer Complete */

USART_RX_vect_num = 18
USART_RX_vect =     _VECTOR(18)  /* USART Rx Complete */

USART_UDRE_vect_num =   19
USART_UDRE_vect =   _VECTOR(19)  /* USART, Data Register Empty */

USART_TX_vect_num = 20
USART_TX_vect =     _VECTOR(20)  /* USART Tx Complete */

ADC_vect_num =      21
ADC_vect =          _VECTOR(21)  /* ADC Conversion Complete */

EE_READY_vect_num = 22
EE_READY_vect =     _VECTOR(22)  /* EEPROM Ready */

ANALOG_COMP_vect_num =  23
ANALOG_COMP_vect =  _VECTOR(23)  /* Analog Comparator */

TWI_vect_num =      24
TWI_vect =          _VECTOR(24)  /* Two-wire Serial Interface */

SPM_READY_vect_num =    25
SPM_READY_vect =    _VECTOR(25)  /* Store Program Memory Read */

_VECTORS_SIZE = (26 * 4)
"""


#Constants 
SPM_PAGESIZE = 128
RAMSTART =     (0x100)
RAMEND =       0x8FF     #/* Last On-Chip SRAM Location */
XRAMSIZE =     0
XRAMEND =      RAMEND
E2END =        0x3FF
E2PAGESIZE =   4
FLASHEND =     0x7FFF


"""
/* Fuses */
FUSE_MEMORY_SIZE = 3

/* Low Fuse Byte */
FUSE_CKSEL0 = (unsigned char)~_BV(0)  /* Select Clock Source */
FUSE_CKSEL1 = (unsigned char)~_BV(1)  /* Select Clock Source */
FUSE_CKSEL2 = (unsigned char)~_BV(2)  /* Select Clock Source */
FUSE_CKSEL3 = (unsigned char)~_BV(3)  /* Select Clock Source */
FUSE_SUT0 =   (unsigned char)~_BV(4)  /* Select start-up time */
FUSE_SUT1 =   (unsigned char)~_BV(5)  /* Select start-up time */
FUSE_CKOUT =  (unsigned char)~_BV(6)  /* Clock output */
FUSE_CKDIV8 = (unsigned char)~_BV(7) /* Divide clock by 8 */
LFUSE_DEFAULT = (FUSE_CKSEL0 & FUSE_CKSEL2 & FUSE_CKSEL3 & FUSE_SUT0 & FUSE_CKDIV8)

/* High Fuse Byte */
FUSE_BOOTRST = (unsigned char)~_BV(0)
FUSE_BOOTSZ0 = (unsigned char)~_BV(1)
FUSE_BOOTSZ1 = (unsigned char)~_BV(2)
FUSE_EESAVE =    (unsigned char)~_BV(3)  /* EEPROM memory is preserved through chip erase */
FUSE_WDTON =     (unsigned char)~_BV(4)  /* Watchdog Timer Always On */
FUSE_SPIEN =     (unsigned char)~_BV(5)  /* Enable Serial programming and Data Downloading */
FUSE_DWEN =      (unsigned char)~_BV(6)  /* debugWIRE Enable */
FUSE_RSTDISBL =  (unsigned char)~_BV(7)  /* External reset disable */
HFUSE_DEFAULT = (FUSE_BOOTSZ0 & FUSE_BOOTSZ1 & FUSE_SPIEN)

/* Extended Fuse Byte */
FUSE_BODLEVEL0 = (unsigned char)~_BV(0)  /* Brown-out Detector trigger level */
FUSE_BODLEVEL1 = (unsigned char)~_BV(1)  /* Brown-out Detector trigger level */
FUSE_BODLEVEL2 = (unsigned char)~_BV(2)  /* Brown-out Detector trigger level */
EFUSE_DEFAULT =  (0xFF)
"""

"""
/* Lock Bits */
__LOCK_BITS_EXIST =
__BOOT_LOCK_BITS_0_EXIST =
__BOOT_LOCK_BITS_1_EXIST = 
"""
"""
/* Signature */
SIGNATURE_0 = 0x1E
SIGNATURE_1 = 0x95
#if defined(__AVR_ATmega328__)
#  define SIGNATURE_2 0x14
#else /* ATmega328P */
#  define SIGNATURE_2 0x0F
#endif

SLEEP_MODE_IDLE = (0x00<<1)
SLEEP_MODE_ADC = (0x01<<1)
SLEEP_MODE_PWR_DOWN = (0x02<<1)
SLEEP_MODE_PWR_SAVE = (0x03<<1)
SLEEP_MODE_STANDBY = (0x06<<1)
SLEEP_MODE_EXT_STANDBY = (0x07<<1)
"""
