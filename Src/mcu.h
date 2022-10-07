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
/** \file mcu.h
 **
 ** MCU description file
 **
 ** History:
 **   2020-08-12  0.01  Msc  First version
 *****************************************************************************/

#ifndef __MCU_H__
#define __MCU_H__

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#include "XT95630.h"	// include mcu register header file

/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define')                           */
/*****************************************************************************/
#define CPU_TYPE_8BIT   8
#define CPU_TYPE_16BIT  16
#define CPU_TYPE_32BIT  32

#define _CPU_TYPE_        CPU_TYPE_8BIT

#if CPU_TYPE != CPU_TYPE_16BIT   // to be moved to compiler abstraction, if any
    #define __far 
    #define __near
#endif     

/*****************************************************************************/
/* Global type definitions ('typedef')                                       */
/*****************************************************************************/

/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source)           */
/*****************************************************************************/

/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source)             */
/*****************************************************************************/

#endif /* __MCU_H__ */
