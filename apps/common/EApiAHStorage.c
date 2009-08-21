/*
 *<KHeader>
 *+=========================================================================
 *I               EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL: https://svn.code.sf.net/p/eapidk/code/trunk/apps/common/EApiAHStorage.c $
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
 *I Description: Auto Created for EApiAHStorage.c
 *I
 *+------------------------------------------------------------------------=
 *I
 *I  File Name            : EApiAHStorage.c
 *I  File Location        : apps\common
 *I  Last committed       : $Revision: 1 $
 *I  Last changed by      : $Author: dethrophes $
 *I  Last changed date    : $Date: 2009-08-21 13:26:22 +0200 (Fr, 21. Aug 2009) $
 *I  ID                   : $Id: EApiAHStorage.c 1 2009-08-21 11:26:22Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */
  #include <EApiApp.h>


uint32_t 
EApiAHWriteStorage(
    __IN  uint32_t         Id          , 
    __IN  const uint32_t   ByteOffset  , 
    __IN  void *           pBuffer     , 
    __IN  const uint32_t   ByteCnt 
    )
{
    uint32_t MaxLen, alignment;
    uint32_t AdjOffset=ByteOffset, AdjLength=ByteCnt;
    int_least8_t * pLclBuffer;
    uint32_t BufferOffset=0;
    uint32_t ReturnValue;
    
    EAPI_APP_ASSERT_PARAMATER_NULL(
        EApiAHWriteStorage, 
        EAPI_STATUS_INVALID_PARAMETER, 
        pBuffer
        );
    EAPI_APP_ASSERT_PARAMATER_ZERO(
        EApiAHWriteStorage, 
        EAPI_STATUS_INVALID_PARAMETER, 
        ByteCnt
        );
    /* Get Storage Capabilities */
    ReturnValue=EApiStorageCap(Id, &MaxLen, &alignment);
    if(ReturnValue!=EAPI_STATUS_SUCCESS)
      return ReturnValue;

    /* Is the write possible? */
    EAPI_APP_ASSERT_PARAMATER_CHECK(
        EApiAHWriteStorage, 
        EAPI_STATUS_INVALID_PARAMETER, 
        ((ByteOffset+ByteCnt)>MaxLen), 
        TEXT("((ByteOffset+ByteCnt)>MaxLen)")
        );

    if(ByteOffset%alignment){
      BufferOffset=ByteOffset%alignment     ; /* Calculate Alignment Offset */
      AdjOffset=ByteOffset - BufferOffset   ; /* Align Bottom of window */
      AdjLength=ByteCnt+BufferOffset        ; /* Increase block length to adjust for new base */
    }
    if(AdjLength%alignment){
      /* Adjust Block length so its a multiple of alignment */
      AdjLength=AdjLength-(AdjLength%alignment)+alignment;  
    }
    if(AdjLength!=ByteCnt){
      /* This Error can only occur if the Storage 
       * area isn't a multiple of its alignment 
       */
      EAPI_APP_ASSERT_PARAMATER_CHECK(
          EApiAHWriteStorage, 
          EAPI_STATUS_ERROR, 
          ((AdjOffset+AdjLength)>MaxLen), 
          TEXT("((AdjOffset+AdjLength)>MaxLen)")
          );
      pLclBuffer=malloc(AdjLength);
      EAPI_APP_RETURN_ERROR_IF(
        EApiAHWriteStorage, 
        pLclBuffer==NULL,
        EAPI_STATUS_ALLOC_ERROR, 
        TEXT("Allocating Page Buffer")
        );
      ReturnValue=EApiStorageAreaRead(Id, AdjOffset, pLclBuffer, AdjLength, AdjLength);
      if(ReturnValue!=EAPI_STATUS_SUCCESS)
      {
        free(pLclBuffer);
        return ReturnValue;
      }
      memcpy(&pLclBuffer[BufferOffset], pBuffer, ByteCnt);
      ReturnValue=EApiStorageAreaWrite(Id, AdjOffset, pLclBuffer, AdjLength);
      free(pLclBuffer);
      return ReturnValue;
    }else{
      return EApiStorageAreaWrite(Id, ByteOffset, pBuffer, ByteCnt);
    }
}

