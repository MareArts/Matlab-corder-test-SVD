/*
 * MySVD.cpp
 *
 * Code generation for function 'MySVD'
 *
 * C source code generated on: Mon Feb 29 23:18:01 2016
 *
 */

/* Include files */
#include "MySVD.h"
#include "MySVD_emxutil.h"

/* Function Declarations */
static void b_eml_xaxpy(int32_T n, real_T a, const emxArray_real_T *x, int32_T
  ix0, real_T y[4], int32_T iy0);
static real_T b_eml_xdotc(int32_T n, const real_T x[16], int32_T ix0, const
  real_T y[16], int32_T iy0);
static real_T b_eml_xnrm2(int32_T n, const emxArray_real_T *x, int32_T ix0);
static void b_eml_xrot(real_T x[16], int32_T ix0, int32_T iy0, real_T c, real_T
  s);
static void b_eml_xscal(int32_T n, real_T a, emxArray_real_T *x, int32_T ix0);
static void b_eml_xswap(real_T x[16], int32_T ix0, int32_T iy0);
static void c_eml_xaxpy(int32_T n, real_T a, const real_T x[4], int32_T ix0,
  emxArray_real_T *y, int32_T iy0);
static real_T c_eml_xdotc(int32_T n, const emxArray_real_T *x, int32_T ix0,
  const emxArray_real_T *y, int32_T iy0);
static void c_eml_xscal(real_T a, real_T x[16], int32_T ix0);
static void d_eml_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[16], int32_T
  iy0);
static void d_eml_xscal(int32_T n, real_T a, emxArray_real_T *x, int32_T ix0);
static void e_eml_xaxpy(int32_T n, real_T a, int32_T ix0, emxArray_real_T *y,
  int32_T iy0);
static real_T eml_div(real_T x, real_T y);
static void eml_xaxpy(int32_T n, real_T a, int32_T ix0, emxArray_real_T *y,
                      int32_T iy0);
static real_T eml_xdotc(int32_T n, const emxArray_real_T *x, int32_T ix0, const
  emxArray_real_T *y, int32_T iy0);
static void eml_xgesvd(const emxArray_real_T *A, real_T U[16], real_T S_data[4],
  int32_T S_size[1], emxArray_real_T *V);
static real_T eml_xnrm2(int32_T n, const emxArray_real_T *x, int32_T ix0);
static void eml_xrot(int32_T n, emxArray_real_T *x, int32_T ix0, int32_T iy0,
                     real_T c, real_T s);
static void eml_xrotg(real_T *a, real_T *b, real_T *c, real_T *s);
static void eml_xscal(int32_T n, real_T a, emxArray_real_T *x, int32_T ix0);
static void eml_xswap(int32_T n, emxArray_real_T *x, int32_T ix0, int32_T iy0);

/* Function Definitions */
static void b_eml_xaxpy(int32_T n, real_T a, const emxArray_real_T *x, int32_T
  ix0, real_T y[4], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if ((n < 1) || (a == 0.0)) {
  } else {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * x->data[ix];
      ix++;
      iy++;
    }
  }
}

static real_T b_eml_xdotc(int32_T n, const real_T x[16], int32_T ix0, const
  real_T y[16], int32_T iy0)
{
  real_T d;
  int32_T ix;
  int32_T iy;
  int32_T k;
  d = 0.0;
  if (n < 1) {
  } else {
    ix = ix0;
    iy = iy0;
    for (k = 1; k <= n; k++) {
      d += x[ix - 1] * y[iy - 1];
      ix++;
      iy++;
    }
  }

  return d;
}

static real_T b_eml_xnrm2(int32_T n, const emxArray_real_T *x, int32_T ix0)
{
  real_T y;
  real_T scale;
  int32_T kend;
  int32_T k;
  real_T absxk;
  real_T t;
  y = 0.0;
  if (n < 1) {
  } else if (n == 1) {
    y = fabs(x->data[ix0 - 1]);
  } else {
    scale = 2.2250738585072014E-308;
    kend = (ix0 + n) - 1;
    for (k = ix0; k <= kend; k++) {
      absxk = fabs(x->data[k - 1]);
      if (absxk > scale) {
        t = scale / absxk;
        y = 1.0 + y * t * t;
        scale = absxk;
      } else {
        t = absxk / scale;
        y += t * t;
      }
    }

    y = scale * sqrt(y);
  }

  return y;
}

static void b_eml_xrot(real_T x[16], int32_T ix0, int32_T iy0, real_T c, real_T
  s)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  real_T y;
  real_T b_y;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < 4; k++) {
    y = c * x[ix];
    b_y = s * x[iy];
    x[iy] = c * x[iy] - s * x[ix];
    x[ix] = y + b_y;
    iy++;
    ix++;
  }
}

static void b_eml_xscal(int32_T n, real_T a, emxArray_real_T *x, int32_T ix0)
{
  int32_T i2;
  int32_T k;
  i2 = (ix0 + n) - 1;
  for (k = ix0; k <= i2; k++) {
    x->data[k - 1] *= a;
  }
}

static void b_eml_xswap(real_T x[16], int32_T ix0, int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  real_T temp;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < 4; k++) {
    temp = x[ix];
    x[ix] = x[iy];
    x[iy] = temp;
    ix++;
    iy++;
  }
}

static void c_eml_xaxpy(int32_T n, real_T a, const real_T x[4], int32_T ix0,
  emxArray_real_T *y, int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if ((n < 1) || (a == 0.0)) {
  } else {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y->data[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

static real_T c_eml_xdotc(int32_T n, const emxArray_real_T *x, int32_T ix0,
  const emxArray_real_T *y, int32_T iy0)
{
  real_T d;
  int32_T ix;
  int32_T iy;
  int32_T k;
  d = 0.0;
  if (n < 1) {
  } else {
    ix = ix0;
    iy = iy0;
    for (k = 1; k <= n; k++) {
      d += x->data[ix - 1] * y->data[iy - 1];
      ix++;
      iy++;
    }
  }

  return d;
}

static void c_eml_xscal(real_T a, real_T x[16], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 3; k++) {
    x[k - 1] *= a;
  }
}

static void d_eml_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[16], int32_T
  iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if ((n < 1) || (a == 0.0)) {
  } else {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * y[ix];
      ix++;
      iy++;
    }
  }
}

static void d_eml_xscal(int32_T n, real_T a, emxArray_real_T *x, int32_T ix0)
{
  int32_T i3;
  int32_T k;
  i3 = (ix0 + n) - 1;
  for (k = ix0; k <= i3; k++) {
    x->data[k - 1] *= a;
  }
}

static void e_eml_xaxpy(int32_T n, real_T a, int32_T ix0, emxArray_real_T *y,
  int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if ((n < 1) || (a == 0.0)) {
  } else {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y->data[iy] += a * y->data[ix];
      ix++;
      iy++;
    }
  }
}

static real_T eml_div(real_T x, real_T y)
{
  return x / y;
}

static void eml_xaxpy(int32_T n, real_T a, int32_T ix0, emxArray_real_T *y,
                      int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if ((n < 1) || (a == 0.0)) {
  } else {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y->data[iy] += a * y->data[ix];
      ix++;
      iy++;
    }
  }
}

static real_T eml_xdotc(int32_T n, const emxArray_real_T *x, int32_T ix0, const
  emxArray_real_T *y, int32_T iy0)
{
  real_T d;
  int32_T ix;
  int32_T iy;
  int32_T k;
  d = 0.0;
  if (n < 1) {
  } else {
    ix = ix0;
    iy = iy0;
    for (k = 1; k <= n; k++) {
      d += x->data[ix - 1] * y->data[iy - 1];
      ix++;
      iy++;
    }
  }

  return d;
}

static void eml_xgesvd(const emxArray_real_T *A, real_T U[16], real_T S_data[4],
  int32_T S_size[1], emxArray_real_T *V)
{
  emxArray_real_T *b_A;
  int32_T i0;
  int32_T i;
  int32_T minnp;
  real_T s_data[5];
  emxArray_real_T *e;
  real_T work[4];
  int32_T qs;
  int32_T nrt;
  int32_T nct;
  int32_T q;
  real_T ztest0;
  int32_T jj;
  int32_T iter;
  int32_T m;
  real_T ztest;
  real_T tiny;
  real_T snorm;
  boolean_T exitg2;
  boolean_T exitg1;
  real_T sm;
  real_T emm1;
  real_T varargin_1[5];
  real_T sqds;
  real_T eqds;
  real_T b;
  emxInit_real_T(&b_A, 2);
  i0 = b_A->size[0] * b_A->size[1];
  b_A->size[0] = 4;
  b_A->size[1] = A->size[1];
  emxEnsureCapacity((emxArray__common *)b_A, i0, (int32_T)sizeof(real_T));
  i = A->size[0] * A->size[1];
  for (i0 = 0; i0 < i; i0++) {
    b_A->data[i0] = A->data[i0];
  }

  i = A->size[1];
  if (4 <= i) {
    minnp = 4;
  } else {
    minnp = i;
  }

  i = A->size[1];
  if (5 <= i) {
    i = 5;
  }

  for (i0 = 0; i0 < i; i0++) {
    s_data[i0] = 0.0;
  }

  b_emxInit_real_T(&e, 1);
  i = A->size[1];
  i0 = e->size[0];
  e->size[0] = i;
  emxEnsureCapacity((emxArray__common *)e, i0, (int32_T)sizeof(real_T));
  for (i0 = 0; i0 < i; i0++) {
    e->data[i0] = 0.0;
  }

  for (i = 0; i < 4; i++) {
    work[i] = 0.0;
  }

  for (i0 = 0; i0 < 16; i0++) {
    U[i0] = 0.0;
  }

  i = A->size[1];
  qs = A->size[1];
  i0 = V->size[0] * V->size[1];
  V->size[0] = i;
  emxEnsureCapacity((emxArray__common *)V, i0, (int32_T)sizeof(real_T));
  i0 = V->size[0] * V->size[1];
  V->size[1] = qs;
  emxEnsureCapacity((emxArray__common *)V, i0, (int32_T)sizeof(real_T));
  i *= qs;
  for (i0 = 0; i0 < i; i0++) {
    V->data[i0] = 0.0;
  }

  if (A->size[1] == 0) {
    for (i = 0; i < 4; i++) {
      U[i + (i << 2)] = 1.0;
    }
  } else {
    if (A->size[1] < 2) {
      i = 2;
    } else {
      i = A->size[1];
    }

    i -= 2;
    if (i <= 4) {
      nrt = i;
    } else {
      nrt = 4;
    }

    i = A->size[1];
    if (3 <= i) {
      nct = 3;
    } else {
      nct = i;
    }

    if (nct >= nrt) {
      i0 = nct;
    } else {
      i0 = nrt;
    }

    for (q = 1; q <= i0; q++) {
      qs = q + ((q - 1) << 2);
      if (q <= nct) {
        ztest0 = eml_xnrm2(5 - q, b_A, qs);
        if (ztest0 > 0.0) {
          if (b_A->data[qs - 1] < 0.0) {
            ztest0 = -ztest0;
          }

          s_data[q - 1] = ztest0;
          eml_xscal(5 - q, eml_div(1.0, s_data[q - 1]), b_A, qs);
          b_A->data[qs - 1]++;
          s_data[q - 1] = -s_data[q - 1];
        } else {
          s_data[q - 1] = 0.0;
        }
      }

      for (jj = q; jj + 1 <= A->size[1]; jj++) {
        i = q + (jj << 2);
        if ((q <= nct) && (s_data[q - 1] != 0.0)) {
          ztest0 = eml_xdotc(5 - q, b_A, qs, b_A, i);
          ztest0 = -eml_div(ztest0, b_A->data[(q + b_A->size[0] * (q - 1)) - 1]);
          eml_xaxpy(5 - q, ztest0, qs, b_A, i);
        }

        e->data[jj] = b_A->data[i - 1];
      }

      if (q <= nct) {
        for (i = q; i < 5; i++) {
          U[(i + ((q - 1) << 2)) - 1] = b_A->data[(i + b_A->size[0] * (q - 1)) -
            1];
        }
      }

      if (q <= nrt) {
        iter = A->size[1] - q;
        ztest0 = b_eml_xnrm2(iter, e, q + 1);
        if (ztest0 == 0.0) {
          e->data[q - 1] = 0.0;
        } else {
          if (e->data[q] < 0.0) {
            ztest0 = -ztest0;
          }

          e->data[q - 1] = ztest0;
          ztest0 = eml_div(1.0, e->data[q - 1]);
          b_eml_xscal(iter, ztest0, e, q + 1);
          e->data[q]++;
        }

        e->data[q - 1] = -e->data[q - 1];
        if ((q + 1 <= 4) && (e->data[q - 1] != 0.0)) {
          for (i = q; i + 1 < 5; i++) {
            work[i] = 0.0;
          }

          for (jj = q; jj + 1 <= A->size[1]; jj++) {
            b_eml_xaxpy(4 - q, e->data[jj], b_A, (q + (jj << 2)) + 1, work, q +
                        1);
          }

          for (jj = q; jj + 1 <= A->size[1]; jj++) {
            ztest0 = eml_div(-e->data[jj], e->data[q]);
            c_eml_xaxpy(4 - q, ztest0, work, q + 1, b_A, (q + (jj << 2)) + 1);
          }
        }

        for (i = q; i + 1 <= A->size[1]; i++) {
          V->data[i + V->size[0] * (q - 1)] = e->data[i];
        }
      }
    }

    i = A->size[1];
    if (i <= 5) {
      m = i;
    } else {
      m = 5;
    }

    if (nct < A->size[1]) {
      s_data[nct] = b_A->data[nct + b_A->size[0] * nct];
    }

    if (4 < m) {
      s_data[4] = 0.0;
    }

    if (nrt + 1 < m) {
      e->data[nrt] = b_A->data[nrt + b_A->size[0] * (m - 1)];
    }

    e->data[m - 1] = 0.0;
    for (jj = nct; jj + 1 < 5; jj++) {
      for (i = 0; i < 4; i++) {
        U[i + (jj << 2)] = 0.0;
      }

      U[jj + (jj << 2)] = 1.0;
    }

    for (q = nct - 1; q + 1 > 0; q--) {
      qs = q + (q << 2);
      if (s_data[q] != 0.0) {
        for (jj = q + 1; jj + 1 < 5; jj++) {
          i = (q + (jj << 2)) + 1;
          ztest0 = b_eml_xdotc(4 - q, U, qs + 1, U, i);
          ztest0 = -eml_div(ztest0, U[qs]);
          d_eml_xaxpy(4 - q, ztest0, qs + 1, U, i);
        }

        for (i = q; i + 1 < 5; i++) {
          U[i + (q << 2)] = -U[i + (q << 2)];
        }

        U[qs]++;
        for (i = 1; i <= q; i++) {
          U[(i + (q << 2)) - 1] = 0.0;
        }
      } else {
        for (i = 0; i < 4; i++) {
          U[i + (q << 2)] = 0.0;
        }

        U[qs] = 1.0;
      }
    }

    for (q = A->size[1] - 1; q + 1 > 0; q--) {
      if ((q + 1 <= nrt) && (e->data[q] != 0.0)) {
        iter = (A->size[1] - q) - 1;
        i = (q + A->size[1] * q) + 2;
        for (jj = q; jj + 2 <= A->size[1]; jj++) {
          qs = (q + A->size[1] * (jj + 1)) + 2;
          ztest0 = c_eml_xdotc(iter, V, i, V, qs);
          ztest0 = -eml_div(ztest0, V->data[i - 1]);
          e_eml_xaxpy(iter, ztest0, i, V, qs);
        }
      }

      for (i = 1; i <= A->size[1]; i++) {
        V->data[(i + V->size[0] * q) - 1] = 0.0;
      }

      V->data[q + V->size[0] * q] = 1.0;
    }

    for (q = 0; q + 1 <= m; q++) {
      if (s_data[q] != 0.0) {
        ztest = fabs(s_data[q]);
        ztest0 = eml_div(s_data[q], ztest);
        s_data[q] = ztest;
        if (q + 1 < m) {
          e->data[q] = eml_div(e->data[q], ztest0);
        }

        if (q + 1 <= 4) {
          c_eml_xscal(ztest0, U, (q << 2) + 1);
        }
      }

      if ((q + 1 < m) && (e->data[q] != 0.0)) {
        ztest = fabs(e->data[q]);
        ztest0 = eml_div(ztest, e->data[q]);
        e->data[q] = ztest;
        s_data[q + 1] *= ztest0;
        i0 = A->size[1] * (q + 1) + 1;
        d_eml_xscal(A->size[1], ztest0, V, i0);
      }
    }

    nct = m;
    iter = 0;
    tiny = eml_div(2.2250738585072014E-308, 2.2204460492503131E-16);
    snorm = 0.0;
    for (i = 0; i + 1 <= m; i++) {
      ztest0 = fabs(s_data[i]);
      ztest = fabs(e->data[i]);
      if (ztest0 >= ztest) {
      } else {
        ztest0 = ztest;
      }

      if (snorm >= ztest0) {
      } else {
        snorm = ztest0;
      }
    }

    while ((m > 0) && (!(iter >= 75))) {
      q = m - 1;
      exitg2 = FALSE;
      while (!((exitg2 == TRUE) || (q == 0))) {
        ztest0 = fabs(e->data[q - 1]);
        if ((ztest0 <= 2.2204460492503131E-16 * (fabs(s_data[q - 1]) + fabs
              (s_data[q]))) || (ztest0 <= tiny) || ((iter > 20) && (ztest0 <=
              2.2204460492503131E-16 * snorm))) {
          e->data[q - 1] = 0.0;
          exitg2 = TRUE;
        } else {
          q--;
        }
      }

      if (q == m - 1) {
        i = 4;
      } else {
        qs = m;
        i = m;
        exitg1 = FALSE;
        while ((exitg1 == FALSE) && (i >= q)) {
          qs = i;
          if (i == q) {
            exitg1 = TRUE;
          } else {
            ztest0 = 0.0;
            if (i < m) {
              ztest0 = fabs(e->data[i - 1]);
            }

            if (i > q + 1) {
              ztest0 += fabs(e->data[i - 2]);
            }

            ztest = fabs(s_data[i - 1]);
            if ((ztest <= 2.2204460492503131E-16 * ztest0) || (ztest <= tiny)) {
              s_data[i - 1] = 0.0;
              exitg1 = TRUE;
            } else {
              i--;
            }
          }
        }

        if (qs == q) {
          i = 3;
        } else if (qs == m) {
          i = 1;
        } else {
          i = 2;
          q = qs;
        }
      }

      switch (i) {
       case 1:
        ztest = e->data[m - 2];
        e->data[m - 2] = 0.0;
        for (i = m - 2; i + 1 >= q + 1; i--) {
          ztest0 = s_data[i];
          eml_xrotg(&ztest0, &ztest, &emm1, &sm);
          s_data[i] = ztest0;
          if (i + 1 > q + 1) {
            ztest = -sm * e->data[i - 1];
            e->data[i - 1] *= emm1;
          }

          i0 = A->size[1] * i + 1;
          qs = A->size[1] * (m - 1) + 1;
          eml_xrot(A->size[1], V, i0, qs, emm1, sm);
        }
        break;

       case 2:
        ztest = e->data[q - 1];
        e->data[q - 1] = 0.0;
        for (i = q; i + 1 <= m; i++) {
          eml_xrotg(&s_data[i], &ztest, &emm1, &sm);
          ztest = -sm * e->data[i];
          e->data[i] *= emm1;
          b_eml_xrot(U, (i << 2) + 1, ((q - 1) << 2) + 1, emm1, sm);
        }
        break;

       case 3:
        varargin_1[0] = fabs(s_data[m - 1]);
        varargin_1[1] = fabs(s_data[m - 2]);
        varargin_1[2] = fabs(e->data[m - 2]);
        varargin_1[3] = fabs(s_data[q]);
        varargin_1[4] = fabs(e->data[q]);
        ztest0 = varargin_1[0];
        for (i = 0; i < 4; i++) {
          if (varargin_1[i + 1] > ztest0) {
            ztest0 = varargin_1[i + 1];
          }
        }

        sm = eml_div(s_data[m - 1], ztest0);
        ztest = eml_div(s_data[m - 2], ztest0);
        emm1 = eml_div(e->data[m - 2], ztest0);
        sqds = eml_div(s_data[q], ztest0);
        eqds = eml_div(e->data[q], ztest0);
        b = eml_div((ztest + sm) * (ztest - sm) + emm1 * emm1, 2.0);
        ztest0 = sm * emm1;
        ztest0 *= ztest0;
        ztest = 0.0;
        if ((b != 0.0) || (ztest0 != 0.0)) {
          ztest = sqrt(b * b + ztest0);
          if (b < 0.0) {
            ztest = -ztest;
          }

          ztest = eml_div(ztest0, b + ztest);
        }

        ztest += (sqds + sm) * (sqds - sm);
        ztest0 = sqds * eqds;
        for (i = q + 1; i < m; i++) {
          eml_xrotg(&ztest, &ztest0, &emm1, &sm);
          if (i > q + 1) {
            e->data[i - 2] = ztest;
          }

          ztest0 = emm1 * s_data[i - 1];
          ztest = sm * e->data[i - 1];
          e->data[i - 1] = emm1 * e->data[i - 1] - sm * s_data[i - 1];
          b = s_data[i];
          s_data[i] *= emm1;
          i0 = A->size[1] * (i - 1) + 1;
          qs = A->size[1] * i + 1;
          eml_xrot(A->size[1], V, i0, qs, emm1, sm);
          s_data[i - 1] = ztest0 + ztest;
          ztest0 = sm * b;
          eml_xrotg(&s_data[i - 1], &ztest0, &emm1, &sm);
          ztest = emm1 * e->data[i - 1] + sm * s_data[i];
          s_data[i] = -sm * e->data[i - 1] + emm1 * s_data[i];
          ztest0 = sm * e->data[i];
          e->data[i] *= emm1;
          if (i < 4) {
            b_eml_xrot(U, ((i - 1) << 2) + 1, (i << 2) + 1, emm1, sm);
          }
        }

        e->data[m - 2] = ztest;
        iter++;
        break;

       default:
        if (s_data[q] < 0.0) {
          s_data[q] = -s_data[q];
          i0 = A->size[1] * q + 1;
          d_eml_xscal(A->size[1], -1.0, V, i0);
        }

        i = q + 1;
        while ((q + 1 < nct) && (s_data[q] < s_data[i])) {
          ztest = s_data[q];
          s_data[q] = s_data[i];
          s_data[i] = ztest;
          if (q + 1 < A->size[1]) {
            i0 = A->size[1] * q + 1;
            qs = A->size[1] * (q + 1) + 1;
            eml_xswap(A->size[1], V, i0, qs);
          }

          if (q + 1 < 4) {
            b_eml_xswap(U, (q << 2) + 1, ((q + 1) << 2) + 1);
          }

          q = i;
          i++;
        }

        iter = 0;
        m--;
        break;
      }
    }
  }

  emxFree_real_T(&e);
  emxFree_real_T(&b_A);
  S_size[0] = minnp;
  for (i = 0; i + 1 <= minnp; i++) {
    S_data[i] = s_data[i];
  }
}

static real_T eml_xnrm2(int32_T n, const emxArray_real_T *x, int32_T ix0)
{
  real_T y;
  real_T scale;
  int32_T kend;
  int32_T k;
  real_T absxk;
  real_T t;
  y = 0.0;
  if (n < 1) {
  } else if (n == 1) {
    y = fabs(x->data[ix0 - 1]);
  } else {
    scale = 2.2250738585072014E-308;
    kend = (ix0 + n) - 1;
    for (k = ix0; k <= kend; k++) {
      absxk = fabs(x->data[k - 1]);
      if (absxk > scale) {
        t = scale / absxk;
        y = 1.0 + y * t * t;
        scale = absxk;
      } else {
        t = absxk / scale;
        y += t * t;
      }
    }

    y = scale * sqrt(y);
  }

  return y;
}

static void eml_xrot(int32_T n, emxArray_real_T *x, int32_T ix0, int32_T iy0,
                     real_T c, real_T s)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  real_T y;
  real_T b_y;
  if (n < 1) {
  } else {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 1; k <= n; k++) {
      y = c * x->data[ix];
      b_y = s * x->data[iy];
      x->data[iy] = c * x->data[iy] - s * x->data[ix];
      x->data[ix] = y + b_y;
      iy++;
      ix++;
    }
  }
}

static void eml_xrotg(real_T *a, real_T *b, real_T *c, real_T *s)
{
  real_T roe;
  real_T absa;
  real_T absb;
  real_T scale;
  real_T ads;
  real_T bds;
  roe = *b;
  absa = fabs(*a);
  absb = fabs(*b);
  if (absa > absb) {
    roe = *a;
  }

  scale = absa + absb;
  if (scale == 0.0) {
    *s = 0.0;
    *c = 1.0;
    ads = 0.0;
    scale = 0.0;
  } else {
    ads = absa / scale;
    bds = absb / scale;
    ads = scale * sqrt(ads * ads + bds * bds);
    if (roe < 0.0) {
      ads = -ads;
    }

    *c = *a / ads;
    *s = *b / ads;
    if (absa > absb) {
      scale = *s;
    } else if (*c != 0.0) {
      scale = 1.0 / *c;
    } else {
      scale = 1.0;
    }
  }

  *a = ads;
  *b = scale;
}

static void eml_xscal(int32_T n, real_T a, emxArray_real_T *x, int32_T ix0)
{
  int32_T i1;
  int32_T k;
  i1 = (ix0 + n) - 1;
  for (k = ix0; k <= i1; k++) {
    x->data[k - 1] *= a;
  }
}

static void eml_xswap(int32_T n, emxArray_real_T *x, int32_T ix0, int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  real_T temp;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 1; k <= n; k++) {
    temp = x->data[ix];
    x->data[ix] = x->data[iy];
    x->data[iy] = temp;
    ix++;
    iy++;
  }
}

void MySVD(const emxArray_real_T *X, real_T U[16], emxArray_real_T *S,
           emxArray_real_T *V)
{
  int32_T s_size[1];
  real_T s_data[4];
  uint32_T uv0[2];
  int32_T k;
  int32_T loop_ub;
  eml_xgesvd(X, U, s_data, s_size, V);
  for (k = 0; k < 2; k++) {
    uv0[k] = (uint32_T)X->size[k];
  }

  k = S->size[0] * S->size[1];
  S->size[0] = 4;
  emxEnsureCapacity((emxArray__common *)S, k, (int32_T)sizeof(real_T));
  k = S->size[0] * S->size[1];
  S->size[1] = (int32_T)uv0[1];
  emxEnsureCapacity((emxArray__common *)S, k, (int32_T)sizeof(real_T));
  loop_ub = (int32_T)uv0[1] << 2;
  for (k = 0; k < loop_ub; k++) {
    S->data[k] = 0.0;
  }

  for (k = 0; k < s_size[0]; k++) {
    S->data[k + S->size[0] * k] = s_data[k];
  }
}

/* End of code generation (MySVD.cpp) */
