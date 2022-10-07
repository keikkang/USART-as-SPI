#ifndef __SPI_H__
#define __SPI_H__

#include "mcu.h"
#include "base_types.h"

#define SPI_CS_PIN 	    PDR0_P05
#define SPI_CS_PIN_DIR  DDR0_P05
#define MOSI 		    RDR_TDR
#define MISO 		    RDR_TDR
#define MOSI_FLAG 	    SSR_RDRF
#define MISO_FLAG 	    SSR_TDRE

typedef char spi_t;

typedef struct {
	volatile uint8_t tx;
	volatile uint8_t rx;
}spi_data;

extern void SPI_Wait(uint8_t j);
extern void SPI_Init(void);
extern void SPI_CS_Enable(void);
extern void SPI_Write_Read(spi_data* pbuf, spi_t data);

#endif

