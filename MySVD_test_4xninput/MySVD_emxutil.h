/*
 * MySVD_emxutil.h
 *
 * Code generation for function 'MySVD_emxutil'
 *
 * C source code generated on: Mon Feb 29 23:18:01 2016
 *
 */

#ifndef __MYSVD_EMXUTIL_H__
#define __MYSVD_EMXUTIL_H__
/* Include files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "rtwtypes.h"
#include "MySVD_types.h"

/* Function Declarations */
extern void b_emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions);
extern void emxEnsureCapacity(emxArray__common *emxArray, int32_T oldNumel, int32_T elementSize);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions);
#endif
/* End of code generation (MySVD_emxutil.h) */
