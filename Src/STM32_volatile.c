/*
 * STM32_volatile.c
 *
 *  Created on: Apr 3, 2026
 *      Author: Aditya Vilayatkar
 */
#include <stdint.h>
#define SRAM_ADDRESS1 0x20000004U

int main()
{
	uint32_t val = 0;
	volatile uint32_t *pSRAM  = (uint32_t*)SRAM_ADDRESS1;

	while(1)
	{
		val = *pSRAM;
		if(val) break;
	}

	while(1);

	return 0;
}
