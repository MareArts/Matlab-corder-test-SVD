/*
 * MySVD.cpp
 *
 * Code generation for function 'MySVD'
 *
 * C source code generated on: Mon Feb 29 22:28:37 2016
 *
 */

/* Include files */
#include "MySVD.h"
#include "MySVD_emxutil.h"

/* Function Declarations */
static void b_eml_xaxpy(int32_T n, real_T a, int32_T ix0, emxArray_real_T *y,
  int32_T iy0);
static real_T b_eml_xdotc(int32_T n, const emxArray_real_T *x, int32_T ix0,
  const emxArray_real_T *y, int32_T iy0);
static void b_eml_xrot(int32_T n, emxArray_real_T *x, int32_T ix0, int32_T iy0,
  real_T c, real_T s);
static void b_eml_xscal(int32_T n, real_T a, emxArray_real_T *x, int32_T ix0);
static void b_eml_xswap(int32_T n, emxArray_real_T *x, int32_T ix0, int32_T iy0);
static void c_eml_xscal(real_T a, real_T x[4], int32_T ix0);
static real_T eml_div(real_T x, real_T y);
static void eml_xaxpy(int32_T n, real_T a, int32_T ix0, emxArray_real_T *y,
                      int32_T iy0);
static real_T eml_xdotc(int32_T n, const emxArray_real_T *x, int32_T ix0, const
  emxArray_real_T *y, int32_T iy0);
static void eml_xgesvd(const emxArray_real_T *A, emxArray_real_T *U, real_T
  S_data[2], int32_T S_size[1], real_T V[4]);
static real_T eml_xnrm2(int32_T n, const emxArray_real_T *x, int32_T ix0);
static void eml_xrot(real_T x[4], int32_T ix0, int32_T iy0, real_T c, real_T s);
static void eml_xrotg(real_T *a, real_T *b, real_T *c, real_T *s);
static void eml_xscal(int32_T n, real_T a, emxArray_real_T *x, int32_T ix0);
static void eml_xswap(real_T x[4], int32_T ix0, int32_T iy0);

/* Function Definitions */
static void b_eml_xaxpy(int32_T n, real_T a, int32_T ix0, emxArray_real_T *y,
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

static real_T b_eml_xdotc(int32_T n, const emxArray_real_T *x, int32_T ix0,
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

static void b_eml_xrot(int32_T n, emxArray_real_T *x, int32_T ix0, int32_T iy0,
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

static void b_eml_xscal(int32_T n, real_T a, emxArray_real_T *x, int32_T ix0)
{
  int32_T i1;
  int32_T k;
  i1 = (ix0 + n) - 1;
  for (k = ix0; k <= i1; k++) {
    x->data[k - 1] *= a;
  }
}

static void b_eml_xswap(int32_T n, emxArray_real_T *x, int32_T ix0, int32_T iy0)
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

static void c_eml_xscal(real_T a, real_T x[4], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 1; k++) {
    x[k - 1] *= a;
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

static void eml_xgesvd(const emxArray_real_T *A, emxArray_real_T *U, real_T
  S_data[2], int32_T S_size[1], real_T V[4])
{
  emxArray_real_T *b_A;
  int32_T jj;
  int32_T i;
  int32_T minnp;
  real_T s_data[2];
  real_T e[2];
  int32_T qs;
  int32_T nct;
  int32_T q;
  int32_T mm;
  real_T ztest0;
  int32_T m;
  real_T ztest;
  real_T tiny;
  real_T snorm;
  boolean_T exitg2;
  boolean_T exitg1;
  real_T sn;
  real_T sm;
  real_T varargin_1[5];
  real_T sqds;
  real_T b;
  emxInit_real_T(&b_A, 2);
  jj = b_A->size[0] * b_A->size[1];
  b_A->size[0] = A->size[0];
  b_A->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)b_A, jj, (int32_T)sizeof(real_T));
  i = A->size[0] * A->size[1];
  for (jj = 0; jj < i; jj++) {
    b_A->data[jj] = A->data[jj];
  }

  i = A->size[0];
  if (i <= 2) {
    minnp = i;
  } else {
    minnp = 2;
  }

  i = A->size[0] + 1;
  if (i <= 2) {
  } else {
    i = 2;
  }

  for (jj = 0; jj < i; jj++) {
    s_data[jj] = 0.0;
  }

  for (i = 0; i < 2; i++) {
    e[i] = 0.0;
  }

  i = A->size[0];
  qs = A->size[0];
  jj = U->size[0] * U->size[1];
  U->size[0] = i;
  emxEnsureCapacity((emxArray__common *)U, jj, (int32_T)sizeof(real_T));
  jj = U->size[0] * U->size[1];
  U->size[1] = qs;
  emxEnsureCapacity((emxArray__common *)U, jj, (int32_T)sizeof(real_T));
  i *= qs;
  for (jj = 0; jj < i; jj++) {
    U->data[jj] = 0.0;
  }

  for (jj = 0; jj < 4; jj++) {
    V[jj] = 0.0;
  }

  if (A->size[0] == 0) {
    for (i = 0; i < 2; i++) {
      V[i + (i << 1)] = 1.0;
    }
  } else {
    i = A->size[0];
    i--;
    if (i <= 2) {
      nct = i;
    } else {
      nct = 2;
    }

    for (q = 0; q + 1 <= nct; q++) {
      mm = q + A->size[0] * q;
      i = A->size[0] - q;
      if (q + 1 <= nct) {
        ztest0 = eml_xnrm2(i, b_A, mm + 1);
        if (ztest0 > 0.0) {
          if (b_A->data[mm] < 0.0) {
            ztest0 = -ztest0;
          }

          s_data[q] = ztest0;
          eml_xscal(i, eml_div(1.0, s_data[q]), b_A, mm + 1);
          b_A->data[mm]++;
          s_data[q] = -s_data[q];
        } else {
          s_data[q] = 0.0;
        }
      }

      jj = q + 2;
      while (jj < 3) {
        qs = q + A->size[0];
        if ((q + 1 <= nct) && (s_data[q] != 0.0)) {
          ztest0 = eml_xdotc(i, b_A, mm + 1, b_A, qs + 1);
          ztest0 = -eml_div(ztest0, b_A->data[q + b_A->size[0] * q]);
          eml_xaxpy(i, ztest0, mm + 1, b_A, qs + 1);
        }

        e[1] = b_A->data[qs];
        jj = 3;
      }

      if (q + 1 <= nct) {
        for (i = q; i + 1 <= A->size[0]; i++) {
          U->data[i + U->size[0] * q] = b_A->data[i + b_A->size[0] * q];
        }
      }
    }

    i = A->size[0] + 1;
    if (2 <= i) {
      m = 2;
    } else {
      m = i;
    }

    if (nct < 2) {
      s_data[nct] = b_A->data[nct + b_A->size[0] * nct];
    }

    if (A->size[0] < m) {
      s_data[1] = 0.0;
    }

    if (1 < m) {
      e[0] = b_A->data[b_A->size[0]];
    }

    e[m - 1] = 0.0;
    if (nct + 1 <= A->size[0]) {
      for (jj = nct; jj + 1 <= A->size[0]; jj++) {
        for (i = 1; i <= A->size[0]; i++) {
          U->data[(i + U->size[0] * jj) - 1] = 0.0;
        }

        U->data[jj + U->size[0] * jj] = 1.0;
      }
    }

    for (q = nct - 1; q + 1 > 0; q--) {
      i = A->size[0] - q;
      mm = q + A->size[0] * q;
      if (s_data[q] != 0.0) {
        for (jj = q; jj + 2 <= A->size[0]; jj++) {
          qs = (q + A->size[0] * (jj + 1)) + 1;
          ztest0 = b_eml_xdotc(i, U, mm + 1, U, qs);
          ztest0 = -eml_div(ztest0, U->data[mm]);
          b_eml_xaxpy(i, ztest0, mm + 1, U, qs);
        }

        for (i = q; i + 1 <= A->size[0]; i++) {
          U->data[i + U->size[0] * q] = -U->data[i + U->size[0] * q];
        }

        U->data[mm]++;
        i = 1;
        while (i <= q) {
          U->data[U->size[0] * q] = 0.0;
          i = 2;
        }
      } else {
        for (i = 1; i <= A->size[0]; i++) {
          U->data[(i + U->size[0] * q) - 1] = 0.0;
        }

        U->data[mm] = 1.0;
      }
    }

    for (q = 1; q > -1; q += -1) {
      for (i = 0; i < 2; i++) {
        V[i + (q << 1)] = 0.0;
      }

      V[q + (q << 1)] = 1.0;
    }

    for (q = 0; q + 1 <= m; q++) {
      if (s_data[q] != 0.0) {
        ztest = fabs(s_data[q]);
        ztest0 = eml_div(s_data[q], ztest);
        s_data[q] = ztest;
        if (q + 1 < m) {
          e[0] = eml_div(e[0], ztest0);
        }

        if (q + 1 <= A->size[0]) {
          jj = A->size[0] * q + 1;
          b_eml_xscal(A->size[0], ztest0, U, jj);
        }
      }

      if ((q + 1 < m) && (e[0] != 0.0)) {
        ztest = fabs(e[0]);
        ztest0 = eml_div(ztest, e[0]);
        e[0] = ztest;
        s_data[1] *= ztest0;
        c_eml_xscal(ztest0, V, 3);
      }
    }

    mm = m;
    nct = 0;
    tiny = eml_div(2.2250738585072014E-308, 2.2204460492503131E-16);
    snorm = 0.0;
    for (i = 0; i + 1 <= m; i++) {
      ztest0 = fabs(s_data[i]);
      ztest = fabs(e[i]);
      if (ztest0 >= ztest) {
      } else {
        ztest0 = ztest;
      }

      if (snorm >= ztest0) {
      } else {
        snorm = ztest0;
      }
    }

    while ((m > 0) && (!(nct >= 75))) {
      q = m - 1;
      exitg2 = FALSE;
      while (!((exitg2 == TRUE) || (q == 0))) {
        ztest0 = fabs(e[0]);
        if ((ztest0 <= 2.2204460492503131E-16 * (fabs(s_data[0]) + fabs(s_data[1])))
            || (ztest0 <= tiny) || ((nct > 20) && (ztest0 <=
              2.2204460492503131E-16 * snorm))) {
          e[0] = 0.0;
          exitg2 = TRUE;
        } else {
          q = 0;
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
              ztest0 = fabs(e[0]);
            }

            if (i > q + 1) {
              ztest0 += fabs(e[0]);
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
        ztest = e[0];
        e[0] = 0.0;
        i = m - 1;
        while (i >= q + 1) {
          ztest0 = s_data[0];
          eml_xrotg(&ztest0, &ztest, &sm, &sn);
          s_data[0] = ztest0;
          eml_xrot(V, 1, ((m - 1) << 1) + 1, sm, sn);
          i = 0;
        }
        break;

       case 2:
        ztest = e[q - 1];
        e[q - 1] = 0.0;
        for (i = q; i + 1 <= m; i++) {
          eml_xrotg(&s_data[i], &ztest, &sm, &sn);
          ztest = -sn * e[i];
          e[i] *= sm;
          jj = A->size[0] * i + 1;
          qs = A->size[0] * (q - 1) + 1;
          b_eml_xrot(A->size[0], U, jj, qs, sm, sn);
        }
        break;

       case 3:
        varargin_1[0] = fabs(s_data[m - 1]);
        varargin_1[1] = fabs(s_data[m - 2]);
        varargin_1[2] = fabs(e[m - 2]);
        varargin_1[3] = fabs(s_data[q]);
        varargin_1[4] = fabs(e[q]);
        sn = varargin_1[0];
        for (i = 0; i < 4; i++) {
          if (varargin_1[i + 1] > sn) {
            sn = varargin_1[i + 1];
          }
        }

        sm = eml_div(s_data[m - 1], sn);
        ztest0 = eml_div(s_data[m - 2], sn);
        ztest = eml_div(e[m - 2], sn);
        sqds = eml_div(s_data[q], sn);
        b = eml_div((ztest0 + sm) * (ztest0 - sm) + ztest * ztest, 2.0);
        ztest0 = sm * ztest;
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
        ztest0 = sqds * eml_div(e[q], sn);
        while (q + 1 <= m - 1) {
          eml_xrotg(&ztest, &ztest0, &sm, &sn);
          ztest0 = sm * s_data[0];
          ztest = sn * e[0];
          e[0] = sm * e[0] - sn * s_data[0];
          b = s_data[1];
          s_data[1] *= sm;
          eml_xrot(V, 1, 3, sm, sn);
          s_data[0] = ztest0 + ztest;
          ztest0 = sn * b;
          eml_xrotg(&s_data[0], &ztest0, &sm, &sn);
          ztest = sm * e[0] + sn * s_data[1];
          s_data[1] = -sn * e[0] + sm * s_data[1];
          ztest0 = sn * e[1];
          e[1] *= sm;
          if (1 < A->size[0]) {
            jj = A->size[0] + 1;
            b_eml_xrot(A->size[0], U, 1, jj, sm, sn);
          }

          q = 1;
        }

        e[0] = ztest;
        nct++;
        break;

       default:
        if (s_data[q] < 0.0) {
          s_data[q] = -s_data[q];
          c_eml_xscal(-1.0, V, (q << 1) + 1);
        }

        while ((q + 1 < mm) && (s_data[0] < s_data[1])) {
          ztest = s_data[0];
          s_data[0] = s_data[1];
          s_data[1] = ztest;
          eml_xswap(V, 1, 3);
          if (1 < A->size[0]) {
            jj = A->size[0] + 1;
            b_eml_xswap(A->size[0], U, 1, jj);
          }

          q = 1;
        }

        nct = 0;
        m--;
        break;
      }
    }
  }

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

static void eml_xrot(real_T x[4], int32_T ix0, int32_T iy0, real_T c, real_T s)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  real_T y;
  real_T b_y;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < 2; k++) {
    y = c * x[ix];
    b_y = s * x[iy];
    x[iy] = c * x[iy] - s * x[ix];
    x[ix] = y + b_y;
    iy++;
    ix++;
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
  int32_T i0;
  int32_T k;
  i0 = (ix0 + n) - 1;
  for (k = ix0; k <= i0; k++) {
    x->data[k - 1] *= a;
  }
}

static void eml_xswap(real_T x[4], int32_T ix0, int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  real_T temp;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < 2; k++) {
    temp = x[ix];
    x[ix] = x[iy];
    x[iy] = temp;
    ix++;
    iy++;
  }
}

void MySVD(const emxArray_real_T *X, emxArray_real_T *U, emxArray_real_T *S,
           real_T V[4])
{
  int32_T s_size[1];
  real_T s_data[2];
  uint32_T uv0[2];
  int32_T k;
  int32_T loop_ub;
  eml_xgesvd(X, U, s_data, s_size, V);
  for (k = 0; k < 2; k++) {
    uv0[k] = (uint32_T)X->size[k];
  }

  k = S->size[0] * S->size[1];
  S->size[0] = (int32_T)uv0[0];
  S->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)S, k, (int32_T)sizeof(real_T));
  loop_ub = (int32_T)uv0[0] << 1;
  for (k = 0; k < loop_ub; k++) {
    S->data[k] = 0.0;
  }

  for (k = 0; k < s_size[0]; k++) {
    S->data[k + S->size[0] * k] = s_data[k];
  }
}

/* End of code generation (MySVD.cpp) */
