/*
 * MySVD_types.h
 *
 * Code generation for function 'MySVD'
 *
 * C source code generated on: Mon Feb 29 22:28:37 2016
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
#ifndef struct_emxArray_real_T_2
#define struct_emxArray_real_T_2
struct emxArray_real_T_2
{
    real_T data[2];
    int32_T size[1];
};
#endif /*struct_emxArray_real_T_2*/

#endif
/* End of code generation (MySVD_types.h) */
