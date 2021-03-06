/*
 * $Id: wlu_cmd.c,v 1.1 2008/08/25 06:42:31 l65130 Exp $
 * $Copyright: (c) 2006, Broadcom Corp.
 * All Rights Reserved.$
 *
 * File:        wlu_cmd.c
 * Purpose:     Command and IO variable information commands
 * Requires:
 */

#if	defined(_CFE_)
#include <lib_types.h>
#include <lib_string.h>
#include <lib_printf.h>
#include <lib_malloc.h>
#include <cfe_error.h>
#else
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#endif /* defined(_CFE_) */

#include <typedefs.h>
#include <bcmutils.h>
#include <wlioctl.h>

#include "wlu.h"


