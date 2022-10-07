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
/** \file vectors.c
 **
 ** vectors file
 **
 ** History:
 **   - 2020-08-12  1.0  MSc  First Version
 ************************************************************************/

 #include "mcu.h" 

/*---------------------------------------------------------------------------
   InitIrqLevels()

   This function  pre-sets all interrupt control registers. It can be used
   to set all interrupt priorities in static applications. If this file
   contains assignments to dedicated resources, verify  that the
   appropriate controller is used.

   NOTE: value 0xFF disables the interrupt and value 0 sets highest priority.
   NOTE: For all resource interrupts exists 3 Interrupt level registers (ILRx).
         Each register sets the level for 4 different resources (IRQx).
   NOTE: This list is prepared for the 8FX-emulation chip MB95FV100 'Horn'.
         Not all resources will be supported by all 8FX-devices
-----------------------------------------------------------------------------*/

void InitIrqLevels(void)
{
/*  ILRx                  IRQs defined by ILRx */

    ILR0 = 0xFF;      //  IRQ0:  external interrupt ch0 | ch4
                      //  IRQ1:  external interrupt ch1 | ch5 
                      //  IRQ2:  external interrupt ch2 | ch6
                      //  IRQ3:  external interrupt ch3 | ch7
	//0X73
    ILR1 = 0x73;      //  IRQ4:  UART/SIO ch0
                      //  IRQ5:  8/16-bit timer ch0 (lower)
                      //  IRQ6:  8/16-bit timer ch0 (upper)
                      //  IRQ7:  LIN-UART (reception)

    ILR2 = 0xFF;      //  IRQ8:  LIN-UART (transmission)
                      //  IRQ9:  8/16-bit PPG ch1 (lower) | UART/SIO ch1
                      //  IRQ10: 8/16-bit PPG ch1 (upper) | I2C ch1
                      //  IRQ11: 16-bit reload timer ch0

    ILR3 = 0xFF;      //  IRQ12: 8/16-bit PPG ch0 (upper)
                      //  IRQ13: 8/16-bit PPG ch0 (lower)
                      //  IRQ14: 8/16-bit timer ch1 (upper)
                      //  IRQ15: 16-bit PPG ch0 + ch2
                          
    ILR4 = 0xFF;      //  IRQ16: 16-bit reload timer ch1 | I2C ch0
                      //  IRQ17: 16-bit PPG ch1
                      //  IRQ18: 10-bit A/D-converter
                      //  IRQ19: Timebase timer
                          
    ILR5 = 0xFF;      //  IRQ20: Watch timer / counter
                      //  IRQ21: external interrupt ch 8-11
                      //  IRQ22: 8/16-bit timer ch1 (lower) | external interrupt ch 12-15
                      //  IRQ23: Flash | Custom ch1                           
}

/*---------------------------------------------------------------------------
   Prototypes
   
   Add your own prototypes here. Each vector definition needs is proto-
   type. Either do it here or include a header file containing them.
-----------------------------------------------------------------------------*/

__interrupt void DefaultIRQHandler (void);
/*---------------------------------------------------------------------------
   Vector definiton

   Use following statements to define vectors. 
   All resource related vectors are predefined. 
   Remaining software interrupts can be added hereas well.
-----------------------------------------------------------------------------*/
#pragma intvect DefaultIRQHandler	0   //  IRQ0:  external interrupt ch0 | ch4 
#pragma intvect DefaultIRQHandler	1   //  IRQ1:  external interrupt ch1 | ch5  
#pragma intvect DefaultIRQHandler	2   //  IRQ2:  external interrupt ch2 | ch6 
#pragma intvect DefaultIRQHandler	3   //  IRQ3:  external interrupt ch3 | ch7 
                                      
#pragma intvect DefaultIRQHandler 4   // IRQ4:  UART/SIO ch0, MPG(DTTI)
#pragma intvect DefaultIRQHandler 5   //  IRQ5:  8/16-bit timer ch0 (lower) 
#pragma intvect DefaultIRQHandler 6   //  IRQ6:  8/16-bit timer ch0 (upper) 
#pragma intvect DefaultIRQHandler 	7   //  IRQ7:  LIN-UART (reception) 
                                      
#pragma intvect DefaultIRQHandler 8   //  IRQ8:  LIN-UART (transmission) 	     
#pragma intvect DefaultIRQHandler 9   //  IRQ9:  8/16-bit PPG ch1 (lower) 
#pragma intvect DefaultIRQHandler 10  //  IRQ10: 8/16-bit PPG ch1 (upper) 
#pragma intvect DefaultIRQHandler 11  //  IRQ11: 8/16-bit PPG ch2 (upper) 
                                      
#pragma intvect DefaultIRQHandler 12  //  IRQ12: 8/16-bit PPG ch0 (upper) 
#pragma intvect DefaultIRQHandler 13  //  IRQ13: 8/16-bit PPG ch0 (lower) 
#pragma intvect DefaultIRQHandler 14  //  IRQ14: 8/16-bit composite timer ch1 (upper) 
#pragma intvect DefaultIRQHandler 15  //  IRQ15:  8/16-bit PPG ch2 (lower) 
                                          
#pragma intvect DefaultIRQHandler 16 //  IRQ16: 16-bit reload timer ch1, MPG(write time/compare clear),I2C ch0 
#pragma intvect DefaultIRQHandler 17  //  IRQ17: 16-bit PPG ch1,MPG(position detection/compare match) 
#pragma intvect DefaultIRQHandler 18  //  IRQ18: 10-bit A/D-converter 
#pragma intvect DefaultIRQHandler  19  //  IRQ19: Timebase timer 
                                          
#pragma intvect DefaultIRQHandler 20  //  IRQ20: Watch prescaler 
#pragma intvect DefaultIRQHandler 21  //  IRQ21: external interrupt ch 8-9
#pragma intvect DefaultIRQHandler 22  //  IRQ22: 8/16-bit compostite timer ch1 (lower)
#pragma intvect DefaultIRQHandler 23  //  IRQ23: Flash memory    
 	
/*---------------------------------------------------------------------------
   DefaultIRQHandler()

   This function is a placeholder for all vector definitions. 
   Either use your own placeholder or add necessary code here 
   (the real used resource interrupt handlers should be defined in the main.c). 
-----------------------------------------------------------------------------*/
__interrupt void DefaultIRQHandler (void)
{
	__DI();						// disable interrupts
	while(1)
		__wait_nop();				// halt system
}
