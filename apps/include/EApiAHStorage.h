/*
 *<KHeader>
 *+=========================================================================
 *I               EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL: https://svn.code.sf.net/p/eapidk/code/trunk/apps/include/EApiAHStorage.h $
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
 *I Description: Auto Created for EApiAHStorage.h
 *I
 *+------------------------------------------------------------------------=
 *I
 *I  File Name            : EApiAHStorage.h
 *I  File Location        : apps\include
 *I  Last committed       : $Revision: 1 $
 *I  Last changed by      : $Author: dethrophes $
 *I  Last changed date    : $Date: 2009-08-21 13:26:22 +0200 (Fr, 21. Aug 2009) $
 *I  ID                   : $Id: EApiAHStorage.h 1 2009-08-21 11:26:22Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */
/* EAPI(Embedded Application Interface) */

#ifndef _EAPIAHSTORAGE_H_        
#define _EAPIAHSTORAGE_H_

#ifdef __cplusplus
extern "C" {
#endif
uint32_t 
EApiAHWriteStorage(
    __IN  uint32_t         Id          , 
    __IN  const uint32_t   ByteOffset  , 
    __IN  void *           pBuffer     , 
    __IN  const uint32_t   ByteCnt 
    );


#ifdef __cplusplus
}
#endif

#endif /* _EAPIAHSTORAGE_H_ */


