/************************************************************************/
/*               (C)Shenzhen XTX Technology Co., LTD(XTX)                */
/*                                                                      */
/* The following software deliverable is intended for and must only be  */
/* used for reference and in an evaluation laboratory environment.      */
/* It is provided on an as-is basis without charge and is subject to    */
/* alterations.                                                         */
/* It is the user's obligation to fully test the software in its        */
/* environment and to ensure proper functionality, qualification and    */
/* compliance with component specifications.                            */
/*                                                                      */
/* In the event the software deliverable includes the use of open       */
/* source components, the provisions of the governing open source       */
/* license agreement shall apply with respect to such software          */
/* deliverable.                                                         */
/* XTX does not warrant that the deliverables do not infringe any      */
/* third party intellectual property right (IPR). In the event that     */
/* the deliverables infringe a third party IPR it is the sole           */
/* responsibility of the customer to obtain necessary licenses to       */
/* continue the usage of the deliverable.                               */
/*                                                                      */
/* To the maximum extent permitted by applicable law XTX disclaims all */
/* warranties, whether express or implied, in particular, but not       */
/* limited to, warranties of merchantability and fitness for a          */
/* particular purpose for which the deliverable is not designated.      */
/*                                                                      */
/* To the maximum extent permitted by applicable law, XTX's liability  */
/* is restricted to intentional misconduct and gross negligence.        */
/* Shenzhen XTX Technology Co., LTD is not liable for consequential      */
/* damages.                                                             */
/*                                                                      */
/* (V1.0)                                                               */
/************************************************************************/
/** \file main.c
 **
 ** main file
 **
 ** 
 **
 ** History:
 **   - 2020-08-12 1.0  Msc  First Version
 ************************************************************************/
#include "mcu.h"
#include "base_types.h"
#include <string.h>
#include <stdio.h>
#include "spi.h"


/*--------------------- MAIN ROUTINE ----------------------------------------*/
void main(void)
{
	__DI();
	/* system clock setting */
	SYCC = 0xFC;				// Main CR PLL clock mode,Source clock  (no division)
	PLLC = 0x80;				// MCLK: main CR clock *2= 4MHZ*2 = 8MHZ  
	while(!PLLC_MPRDY);			// wait Main CR PLL clock oscillation stabilization
	
	
	
	/* IO Port initialization */
	AIDRL = 0xFF;				// P0: Port input enabled
	PDR0 = 0xFF;
	 
	DDR0_P03 = 1; //P03(SOT) OUTPUT
	DDR0_P04 = 0; //P04(SIN) INPUT
	
	/* watchdog timer setting */
	WDTC = 0x35;				// Clear watchdog timer
	
	InitIrqLevels();			// initialise Interrupt level register and IRQ vector table
	__set_il(3);				// set global interrupt mask to allow all IRQ levels    
	__EI();
	 

	while(1)		// show error code on 7-seg display
	{
		WDTC = 0x35;	//Clear watch dog timer
	}
}

/*****************************************************************************/
/*Function Name: LIN_Uart_Mode3_Init                                         */
/*Function description: LIN-UART works as the LIN master and the LIN slave.  */
/*                      this function initialize operationg mode 3 of LIN.   */
/*****************************************************************************/


/***********************************************************************
NAME : LIN_Uart_Mode0_init ()
FUNCTION: Initialize the LIN-UART in operation mode 0(asynchronous mode)
***********************************************************************/
void LIN_Uart_Mode0_Init(void) //
{
	BGR1 = 0x03; //8Mhz 9600 Baud
	BGR0 = 0x40; //8Mhz 9600 Baud 
	SSR = 0X02; //Clear Flags, Enable reception interrupt
	SCR = 0x13; //Enabel transmit 
	ESCR = 0x00;
	SMR = 0x0C;
	SMR = 0x01; // Reset LIN_Uart_Mode0, Enable Trasnmit	
	
}
/***********************************************************************
NAME : Init_ReloadTimer(void)
FUNCTION: Initialize the ReloadTImer
***********************************************************************/
void Init_ReloadTimer(void) // 1.008ms Timer
{
	TMR1_TMRH1 = 126;
	TMR1_TMRL1 = 0;
	
	TMCSRH1_CSL2 = 0; // 1MCLK
	TMCSRH1_CSL1 = 0;
	TMCSRH1_CSL0 = 0;
	
	TMCSRH1_MOD2 = 0; // Software TRG
	TMCSRH1_MOD1 = 0;
	TMCSRH1_MOD0 = 0;
	
	TMCSRL1_OUTE = 0; // output enable  
	TMCSRL1_OUTL = 0; // output L 
	TMCSRL1_RELD = 1; //Reload Mode 	
	TMCSRL1_CNTE = 1; //Enable a count	

    TMCSRL1_TRG  = 1; // Perform the software trigger 	
    TMCSRL1_INTE = 1; // Enable underflow interrupt
}

/*****************************************************************************/
/*Function Name: wait                                                        */
/*Function description: use this funciton to set delay time                  */
/*****************************************************************************/
void wait(unsigned long j)
{
	while(j--)
	{
		asm("\tNOP");
		WDTC=0x35;	//Clear watch dog timer
	}
}




