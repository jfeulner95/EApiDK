/*
 *<KHeader>
 *+=========================================================================
 *I               EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL: https://svn.code.sf.net/p/eapidk/code/trunk/apps/include/EApiAHI2C.h $
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
 *I Description: Auto Created for EApiAHI2C.h
 *I
 *+------------------------------------------------------------------------=
 *I
 *I  File Name            : EApiAHI2C.h
 *I  File Location        : apps\include
 *I  Last committed       : $Revision: 1 $
 *I  Last changed by      : $Author: dethrophes $
 *I  Last changed date    : $Date: 2009-08-21 13:26:22 +0200 (Fr, 21. Aug 2009) $
 *I  ID                   : $Id: EApiAHI2C.h 1 2009-08-21 11:26:22Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */
/* EAPI(Embedded Application Interface) */

#ifndef _EAPIAHI2C_H_        
#define _EAPIAHI2C_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef enum EApiCmdTypes_e{
  EApiAPI2CStdIndex=1,
  EApiAPI2CExtIndex=2
}EApiCmdTypes_t;

typedef struct I2CDeviceDesc_s{
  uint16_t        DeviceAddr   ; /* Encodded Device Address */
  uint16_t        PageSize     ; /* Maximume Write Block Length */
  EApiCmdTypes_t  ExtIndx      ; /* Maximum Write Block Length */
  uint16_t        WRecTimems   ; /* Write Recover Time in ms */
  uint32_t        DevSize      ; /* Device Size */
}I2CDeviceDesc_t;

uint32_t 
EApiAHI2CProbeDevice(
    __IN  uint32_t              Id    , 
    __IN  uint32_t              EncAddr
    );

uint32_t
EApiAHI2CWriteEeprom(
    __IN uint32_t               Id          , 
    __IN const I2CDeviceDesc_t *const pDDesc, 
    __IN const uint32_t         ByteOffset  , 
    __IN void *                 pBuffer     , 
    __IN uint32_t               ByteCnt 
    );
uint32_t
EApiAHI2CReadEeprom(
    __IN uint32_t              Id           , 
    __IN const I2CDeviceDesc_t *const pDDesc, 
    __IN const uint32_t        ByteOffset   , 
    __IN void *                pBuffer      , 
    __IN const uint32_t        BufLength    , 
    __IN uint32_t              ByteCnt 
    );

#ifdef __cplusplus
}
#endif

#endif /* _EAPIAHI2C_H_ */


