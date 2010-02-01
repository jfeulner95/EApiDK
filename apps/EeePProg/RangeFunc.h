/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL: https://svn.code.sf.net/p/eapidk/code/trunk/apps/EeePProg/RangeFunc.h $
 *+=========================================================================
 *I   Copyright: Copyright (c) 2002-2010, Kontron Embedded Modules GmbH
 *I      Author: John Kearney,                  John.Kearney@kontron.com
 *I
 *I     License: This program contains proprietary and confidential 
 *I              information. All rights reserved except as may be 
 *I              permitted by prior written consent.
 *I
 *I Description: Auto Created for TokenFunc.c
 *I
 *+-------------------------------------------------------------------------
 *I
 *I  File Name            : RangeFunc.h
 *I  File Location        : apps\EeePProg
 *I  Last committed       : $Revision: 51 $
 *I  Last changed by      : $Author: dethrophes $
 *I  Last changed date    : $Date: 2010-02-01 08:48:20 +0100 (Mo, 01. Feb 2010) $
 *I  ID                   : $Id: RangeFunc.h 51 2010-02-01 07:48:20Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */
#ifndef __RANGEFUNC_H__
#define __RANGEFUNC_H__

#ifdef __cplusplus
extern "C" {
#endif


  
typedef struct NumberRange_s{
  unsigned int uiLowerLimit;
  unsigned int uiUpperLimit;
  unsigned int uiType;
#define  RANGE_EXCLUSIVE  0
#define  RANGE_INCLUSIVE  1
#define  RANGE_MASK_SET   2
#define  RANGE_MASK_UNSET 3
}NumberRange_t;
typedef struct NumberRangeDesc_s{
  size_t         stRangeCount;
  NumberRange_t *pNumberRange;
}NumberRangeDesc_t;

#define PCFG_RANGE_LIST_DESC(RLName, RangeList) \
NumberRangeDesc_t RLName={ \
  ARRAY_SIZE(RangeList), RangeList \
}

EApiStatusCode_t
RangeCheckAll(
    NumberRangeDesc_t *pRangeDesc,
    unsigned long      ulValue
  );

EApiStatusCode_t
RangeCheckAny(
    NumberRangeDesc_t *pRangeDesc,
    unsigned long      ulValue
  );
    



#ifdef __cplusplus
}
#endif
#endif /* __RANGEFUNC_H__ */

