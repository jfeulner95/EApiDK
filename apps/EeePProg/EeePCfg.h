/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL: https://svn.code.sf.net/p/eapidk/code/trunk/apps/EeePProg/EeePCfg.h $
 *+=========================================================================
 *I   Copyright: Copyright (c) 2002-2010, Kontron Embedded Modules GmbH
 *I      Author: John Kearney,                  John.Kearney@kontron.com
 *I
 *I     License: This program contains proprietary and confidential 
 *I              information. All rights reserved except as may be 
 *I              permitted by prior written consent.
 *I
 *I Description: Auto Created for EeePCfg.c
 *I
 *+-------------------------------------------------------------------------
 *I
 *I  File Name            : EeePCfg.h
 *I  File Location        : apps\EeePProg
 *I  Last committed       : $Revision: 27 $
 *I  Last changed by      : $Author: dethrophes $
 *I  Last changed date    : $Date: 2010-01-25 04:21:51 +0100 (Mo, 25. Jan 2010) $
 *I  ID                   : $Id: EeePCfg.h 27 2010-01-25 03:21:51Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */
#ifndef __EEEPCFG_H__
#define __EEEPCFG_H__

#ifdef __cplusplus
extern "C" {
#endif

EApiStatusCode_t
EeeP_CreateCOM0R20_CBImage(
    __OUT  EeePHandel_t   * pBHandel      ,
    __IN   const char     * cszCfgFileName
    );

EApiStatusCode_t
EeeP_CreateCOM0R20_MEEPImage(
    __OUT  EeePHandel_t   * pBHandel      ,
    __IN   const char     * cszCfgFileName
    );

EApiStatusCode_t
EeeP_CreateEeePExtEEPImage(
    __OUT  EeePHandel_t   * pBHandel      ,
    __IN   const char     * cszCfgFileName
    );

EApiStatusCode_t
EeeP_CreateCOM0R20_CBCfg(
    __OUT  FILE           * OutStream
    );

EApiStatusCode_t
EeeP_CreateCOM0R20_MEEPCfg(
    __OUT  FILE           * OutStream
    );

EApiStatusCode_t
EeeP_CreateEeePExtEEPCfg(
    __OUT  FILE           * OutStream
    );

#ifdef __cplusplus
}
#endif
#endif /* __EEEPCFG_H__ */
