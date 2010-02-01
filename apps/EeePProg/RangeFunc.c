/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL: https://svn.code.sf.net/p/eapidk/code/trunk/apps/EeePProg/RangeFunc.c $
 *+=========================================================================
 *I   Copyright: Copyright (c) 2002-2010, Kontron Embedded Modules GmbH
 *I      Author: John Kearney,                  John.Kearney@kontron.com
 *I
 *I     License: This program contains proprietary and confidential 
 *I              information. All rights reserved except as may be 
 *I              permitted by prior written consent.
 *I
 *I Description: Auto Created for sEAPI_printf.c
 *I
 *+-------------------------------------------------------------------------
 *I
 *I  File Name            : RangeFunc.c
 *I  File Location        : apps\EeePProg
 *I  Last committed       : $Revision: 51 $
 *I  Last changed by      : $Author: dethrophes $
 *I  Last changed date    : $Date: 2010-02-01 08:48:20 +0100 (Mo, 01. Feb 2010) $
 *I  ID                   : $Id: RangeFunc.c 51 2010-02-01 07:48:20Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */

#include <EeePApp.h>

EApiStatusCode_t
RangeCheckAll(
    NumberRangeDesc_t *pRangeDesc,
    unsigned long ulValue
  )
{ 
  NumberRange_t *pNumRange =pRangeDesc->pNumberRange;
  size_t         stRangeCnt=pRangeDesc->stRangeCount;
  while(stRangeCnt--){
/*     printf("%04lX - %04lX - %04lX\n", pNumRange->uiLowerLimit, ulValue, pNumRange->uiUpperLimit); */
    switch(pNumRange->uiType){
      case RANGE_INCLUSIVE:
        if(!((ulValue>=pNumRange->uiLowerLimit)&&(ulValue<=pNumRange->uiUpperLimit))){
          return EAPI_STATUS_ERROR;
        }
        break;
      case RANGE_EXCLUSIVE:
        if(!((ulValue<pNumRange->uiLowerLimit)||(ulValue>pNumRange->uiUpperLimit))){
          return EAPI_STATUS_ERROR;
        }
        break;
      case RANGE_MASK_SET:
        if(!(ulValue&pNumRange->uiLowerLimit)){
          return EAPI_STATUS_ERROR;
        }
        break;
      case RANGE_MASK_UNSET:
        if((ulValue&pNumRange->uiLowerLimit)){
          return EAPI_STATUS_ERROR;
        }
        break;
      default:
        break;
    }
    pNumRange++;
  }
  return EAPI_STATUS_SUCCESS;

}

EApiStatusCode_t
RangeCheckAny(
    __IN  NumberRangeDesc_t *pRangeDesc,
    __IN unsigned long ulValue
  )
{ 
  NumberRange_t *pNumRange =pRangeDesc->pNumberRange;
  size_t         stRangeCnt=pRangeDesc->stRangeCount;
  while(stRangeCnt--){
/*     printf("%04lX - %04lX - %04lX\n", pNumRange->uiLowerLimit, ulValue, pNumRange->uiUpperLimit); */
    switch(pNumRange->uiType){
      case RANGE_INCLUSIVE:
        if(((ulValue>=pNumRange->uiLowerLimit)&&(ulValue<=pNumRange->uiUpperLimit))){
          return EAPI_STATUS_SUCCESS;
        }
        break;
      case RANGE_EXCLUSIVE:
        if(((ulValue<pNumRange->uiLowerLimit)||(ulValue>pNumRange->uiUpperLimit))){
          return EAPI_STATUS_SUCCESS;
        }
        break;
      case RANGE_MASK_SET:
        if((ulValue&pNumRange->uiLowerLimit)){
          return EAPI_STATUS_SUCCESS;
        }
        break;
      case RANGE_MASK_UNSET:
        if(!(ulValue&pNumRange->uiLowerLimit)){
          return EAPI_STATUS_SUCCESS;
        }
        break;
      default:
        break;
    }
    pNumRange++;
  }
  return EAPI_STATUS_ERROR;

}

#if TEST_RANGE_FUNC

EApiStatusCode_t
main(void)
{
/*   EApiStatusCode_t EApiStatusCode; */

  exit(EAPI_STATUS_SUCCESS);
}
#endif

