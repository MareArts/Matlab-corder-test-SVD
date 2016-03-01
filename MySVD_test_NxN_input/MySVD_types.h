/*
 * MySVD_types.h
 *
 * Code generation for function 'MySVD'
 *
 * C source code generated on: Tue Mar 01 12:25:32 2016
 *
 */

#ifndef __MYSVD_TYPES_H__
#define __MYSVD_TYPES_H__

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray__common
#define struct_emxArray__common
struct emxArray__common
{
    void *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};
#endif /*struct_emxArray__common*/
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T
{
    real_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};
#endif /*struct_emxArray_real_T*/

#endif
/* End of code generation (MySVD_types.h) */
