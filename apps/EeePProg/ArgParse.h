/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL: https://svn.code.sf.net/p/eapidk/code/trunk/apps/EeePProg/ArgParse.h $
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
 *I  File Name            : ArgParse.h
 *I  File Location        : apps\EeePProg
 *I  Last committed       : $Revision: 60 $
 *I  Last changed by      : $Author: dethrophes $
 *I  Last changed date    : $Date: 2010-02-28 21:53:20 +0100 (So, 28. Feb 2010) $
 *I  ID                   : $Id: ArgParse.h 60 2010-02-28 20:53:20Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */
#ifndef __ARGPARSE_H__
#define __ARGPARSE_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ArgDesc_s{
  void *pValue;
  size_t stValueSize;
  const char *cszHelp;
  EApiStatusCode_t (*Handle)(struct ArgDesc_s  *pArgs, void * pCurArg,  const char *cszArg );
}ArgDesc_t;

typedef struct CmdDesc_s{
  const char  cShort;
  const char *cszLong;
  unsigned int *puiResult;
  const char *cszHelp;
  ArgDesc_t  *pArgs;
  size_t     stArgs;
  void *     pArgData;
  EApiStatusCode_t (*handler)(void *pArgsData);
}CmdDesc_t;

typedef EApiStatusCode_t CmdArgHandler_t(
    struct ArgDesc_s  *pArgs, 
    void * pCurArg, 
    const char *cszArg 
    );

CmdArgHandler_t StringArg;
CmdArgHandler_t NumberArg;

EApiStatusCode_t
PrintUsage(
    FILE      *OutStream    , 
    CmdDesc_t *pCmdDesc     ,
    size_t    stArgDescCnt
    );

EApiStatusCode_t
ParseArgs(
    signed int siArgc,
    const char**pszArgv,
    CmdDesc_t *pCmdDesc,
    size_t    stArgDescCnt
    );

#ifdef __cplusplus
}
#endif
#endif /* __ARGPARSE_H__ */
