#ifndef DEBUG_H
#define DEBUG_H
#include <MKL25Z4.h>

#define MASK(x) (1UL << (x))

#define DEBUG_OFF (1) // when 1, disables debug bits

#if(DEBUG_OFF)
	#define DEBUG_START(channel) {;} 
	#define DEBUG_STOP(channel) {;}
	#define DEBUG_TOGGLE(channel) {;}
#endif
	
#if(!DEBUG_OFF)
#define DEBUG_START(channel) {PTB->PSOR = MASK(channel);} 
#define DEBUG_STOP(channel) { PTB->PCOR = MASK(channel); }
#define DEBUG_TOGGLE(channel) { PTB->PTOR = MASK(channel); }
#endif

// Debug Signals on port B
#define DBG_1 1 	// SPI_RW
#define DBG_2 2	  // SD_Read
#define DBG_3 3		// SD_Write
#define DBG_4 8		// pf_read
#define DBG_5 9		// SD_Init
#define DBG_6 10	// unused
#define DBG_7 11	// unused

void Init_Debug_Signals(void);

#endif // DEBUG_H
