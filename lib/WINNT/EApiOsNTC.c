/*
 *<KHeader>
 *+=========================================================================
 *I               EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL: https://svn.code.sf.net/p/eapidk/code/trunk/lib/WINNT/EApiOsNTC.c $
 *+=========================================================================
 *I   Copyright: Copyright (c) 2002-2009, Kontron Embedded Modules GmbH
 *I      Author: John Kearney,                  John.Kearney@kontron.com
 *I
 *I     License: All rights reserved. This program and the accompanying 
 *I              materials are licensed and made available under the 
 *I              terms and conditions of the BSD License which 
 *I              accompanies this distribution. The full text of the 
 *I              license may be found at 
 *I              http://opensource.org/licenses/bsd-license.php
 *I              
 *I              THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "
 *I              AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF 
 *I              ANY KIND, EITHER EXPRESS OR IMPLIED.
 *I
 *I Description: Auto Created for EApiOsNTC.c
 *I
 *+------------------------------------------------------------------------=
 *I
 *I  File Name            : EApiOsNTC.c
 *I  File Location        : lib\WINNT
 *I  Last committed       : $Revision: 1 $
 *I  Last changed by      : $Author: dethrophes $
 *I  Last changed date    : $Date: 2009-08-21 13:26:22 +0200 (Fr, 21. Aug 2009) $
 *I  ID                   : $Id: EApiOsNTC.c 1 2009-08-21 11:26:22Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */
  #include <EApiLib.h>

void EApiSleepus(unsigned long us)  
{ 
  LARGE_INTEGER cnt1;
  LARGE_INTEGER cnt2;
  QueryPerformanceCounter   (&cnt1);
  QueryPerformanceFrequency (&cnt2);
  cnt1.QuadPart+=(us*cnt2.QuadPart)/1000000;
  do{
    QueryPerformanceCounter (&cnt2);
  }while(cnt1.QuadPart>cnt2.QuadPart);
  return ;
}

