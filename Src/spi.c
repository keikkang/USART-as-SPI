#include "spi.h"

void SPI_Init(void) //LIN_Uart_Mode2_Init
{
	BGR1 = 0x01;
	BGR0 = 0xA0;
	ESCR = 0x01;		// SCES = 1 => CPOL = 1
	ECCR = 0x10;		// SCDE = 1 => CPHA = 1
	SMR = 0x83; // Mode 2, SCLK enable, SOT enable
	SSR = 0x04; // MSB first, no interrupts
	
	AIDRL = 0xFF;
	SPI_CS_PIN_DIR = 0; //Using as INPUT
	SPI_CS_PIN = 0;     //Using
}

void SPI_CS_Enable(void)
{
	SPI_CS_PIN = 1;
}

void SPI_CS_Disable(void)
{
	SPI_CS_PIN = 0;
}

void SPI_Wait(uint8_t j)
{
	volatile unsigned int i;
	
	for (i = 0; i < j; i++)
	{
		#pragma asm
		NOP
		NOP
		NOP
		NOP
		#pragma endasm
	}
}

void SPI_Write_Read(spi_data* pbuf, spi_t data)
{
	pbuf->tx = data;
	
	SPI_CS_Enable();
	SPI_Wait(20);
	
	MOSI = pbuf->tx;
	while (MOSI_FLAG == 0);
	MOSI = 0xFF; // send dummy byte to produce SCLK 
	while (MISO_FLAG == 0); 
	pbuf->rx = MISO;
	
	SPI_CS_Disable();
	
}


