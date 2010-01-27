/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL: https://svn.code.sf.net/p/eapidk/code/trunk/lib/EApiInitLib.c $
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
 *I Description: Auto Created for EApiInitLib.c
 *I
 *+-------------------------------------------------------------------------
 *I
 *I  File Name            : EApiInitLib.c
 *I  File Location        : lib
 *I  Last committed       : $Revision: 42 $
 *I  Last changed by      : $Author: dethrophes $
 *I  Last changed date    : $Date: 2010-01-27 07:27:50 +0100 (Mi, 27. Jan 2010) $
 *I  ID                   : $Id: EApiInitLib.c 42 2010-01-27 06:27:50Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */
  #include <EApiLib.h>
  #include <stdio.h>
FILE *OutputStream=NULL;

void __cdecl DebugMsg(__IN const char *const fmt, ...)
{
  va_list arg;
  va_start(arg, fmt);
  if(OutputStream!=NULL)
    vfprintf(OutputStream, fmt, arg);
  else
    vfprintf(stdout, fmt, arg);

  fflush(OutputStream);
  va_end(arg);
}


uint32_t OpenI2CEepromFiles(void);
uint32_t CloseI2CEepromFiles(void);


uint32_t EApiInitLib(){
  if(OutputStream==NULL){
#if EAPI_DBG_USE_OUTPUT_FILE
    OutputStream=fopen(TEXT("EApi.log"), TEXT("w"));
#else
    OutputStream=stdout;
#endif
  }
  OpenI2CEepromFiles();
    DebugMsg("#\n"
              "# Embedded API EApi\n"
              "# Version %u.%u\n"
              "# Lib Version %u.%u.%u\n"
              "#\n",
              EAPI_VER_GET_VER(EAPI_VERSION), EAPI_VER_GET_REV(EAPI_VERSION), 
              LIB_VERSION, LIB_REVISION, LIB_BUILD
            );
  return EAPI_STATUS_SUCCESS;
}



uint32_t EApiUninitLib(){
    DebugMsg("#\n"
              "# Embedded API EApi\n"
              "# Exit \n"
              "#\n"
            );
  if(OutputStream!=NULL){
    fclose(OutputStream);
    OutputStream=NULL;
  }
  return CloseI2CEepromFiles();
}


