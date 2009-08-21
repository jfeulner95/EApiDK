/*
 *<KHeader>
 *+=========================================================================
 *I               EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL: https://svn.code.sf.net/p/eapidk/code/trunk/include/EApiCommon.h $
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
 *I Description: Auto Created for EApiCommon.h
 *I
 *+------------------------------------------------------------------------=
 *I
 *I  File Name            : EApiCommon.h
 *I  File Location        : include
 *I  Last committed       : $Revision: 1 $
 *I  Last changed by      : $Author: dethrophes $
 *I  Last changed date    : $Date: 2009-08-21 13:26:22 +0200 (Fr, 21. Aug 2009) $
 *I  ID                   : $Id: EApiCommon.h 1 2009-08-21 11:26:22Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */
/* EApi Common Header */
#ifndef _EAPICOMMON_H_    
#define _EAPICOMMON_H_
/*
 * ALL Of these MACROS can be overridden by MACROS
 * in the OS Specific Header File EApiOs.h
 */
#ifndef ARRAY_SIZE
#  define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))
#endif
#ifndef STRICT_VALIDATION
#  define  STRICT_VALIDATION 2
#endif

#endif /* _EAPICOMMON_H_ */

