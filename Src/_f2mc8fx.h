/*
 XT95630 Series I/O register declaration file V01L02
 ALL RIGHTS RESERVED, COPYRIGHT (C)  Shenzhen XTX Technology Co., LTD 2020
 LICENSED MATERIAL - PROGRAM PROPERTY OF  Shenzhen XTX Technology Co., LTD
*/

#if defined(__CPU_XT95F632H__) || \
    defined(__CPU_XT95F632K__) || \
    defined(__CPU_XT95F633H__) || \
    defined(__CPU_XT95F633K__) || \
    defined(__CPU_XT95F634H__) || \
    defined(__CPU_XT95F634K__) || \
    defined(__CPU_XT95F636H__) || \
    defined(__CPU_XT95F636K__) || \
	defined(__CPU_MB95F632H__) || \
    defined(__CPU_MB95F632K__) || \
    defined(__CPU_MB95F633H__) || \
    defined(__CPU_MB95F633K__) || \
    defined(__CPU_MB95F634H__) || \
    defined(__CPU_MB95F634K__) || \
    defined(__CPU_MB95F636H__) || \
    defined(__CPU_MB95F636K__) 
#ifdef __FASM__
#include "XT95630_a.inc"
#else
#include "XT95630.h"
#endif
#else
#error "The I/O register file of the specified CPU option does not exist"
#endif
