/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL: https://svn.code.sf.net/p/eapidk/code/trunk/lib/include/DbgChk.h $
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
 *I              THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN '
 *I              AS IS' BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF 
 *I              ANY KIND, EITHER EXPRESS OR IMPLIED.
 *I
 *I Description: Auto Created for DbgPrt.c
 *I
 *+-------------------------------------------------------------------------
 *I
 *I  File Name            : DbgChk.h
 *I  File Location        : lib\include
 *I  Last committed       : $Revision: 55 $
 *I  Last changed by      : $Author: dethrophes $
 *I  Last changed date    : $Date: 2010-02-02 04:21:00 +0100 (Di, 02. Feb 2010) $
 *I  ID                   : $Id: DbgChk.h 55 2010-02-02 03:21:00Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */
#ifndef _DBGCHK_H_    
#define _DBGCHK_H_



#ifdef __cplusplus
extern "C" {
#endif



signed int
siFormattedMessage_M2(
    char          cType       ,
    const char *  cszFileName ,   
    const char *  cszFuncName ,   
    unsigned int  uiLineNum   ,
    const char *  csz2ndValue ,   
    const char *  cszFormat   ,   
    ...
    );


signed int
siFormattedMessage_SC(
    char          cType       ,
    const char *  cszFileName ,   
    const char *  cszFuncName ,   
    unsigned int  uiLineNum   ,
    EApiStatusCode_t  StatusCode  ,   
    const char *  cszFormat   ,   
    ...
    );


#ifdef __cplusplus
}
#endif



#endif /* _DBGCHK_H_ */


