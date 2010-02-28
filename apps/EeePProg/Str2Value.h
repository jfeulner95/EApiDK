/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL: https://svn.code.sf.net/p/eapidk/code/trunk/apps/EeePProg/Str2Value.h $
 *+=========================================================================
 *I   Copyright: Copyright (c) 2002-2010, Kontron Embedded Modules GmbH
 *I      Author: John Kearney,                  John.Kearney@kontron.com
 *I
 *I     License: This program contains proprietary and confidential 
 *I              information. All rights reserved except as may be 
 *I              permitted by prior written consent.
 *I
 *I Description: Auto Created for sprintf.c
 *I
 *+-------------------------------------------------------------------------
 *I
 *I  File Name            : StrFuncs.h
 *I  File Location        : apps\EeePProg
 *I  Last committed       : $Revision: 60 $
 *I  Last changed by      : $Author: dethrophes $
 *I  Last changed date    : $Date: 2010-02-28 21:53:20 +0100 (So, 28. Feb 2010) $
 *I  ID                   : $Id: Str2Value.h 60 2010-02-28 20:53:20Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */
#ifndef __STR2VALUE_H__
#define __STR2VALUE_H__

#ifdef __cplusplus
extern "C" {
#endif

char *
ReturnEnvVar(
    const char *const VarName
    );


unsigned long 
ulConvertStr2NumEx(
    __IN  const char *  cszString, 
    __OUT char **       pszEnd
    );

EApiStatusCode_t
ExpandEnviromentVariables(
    __IN  const char   *cszString,
    __OUT char        **pszExpStr
  );

EApiStatusCode_t
ParseAsciiEqu(
    __IN  const char       *cszString,
    __OUT signed long long *psllValue
  );

EApiStatusCode_t
ParseAsciiEqu_VA(
    __IN  const char       *cszString,
    __OUT void             *pvalue,
    __IN  signed int        siElementSize
  );


#ifdef __cplusplus
}
#endif
#endif /* __STR2VALUE_H__ */
