/*
 * MySVD.cpp
 *
 * Code generation for function 'MySVD'
 *
 * C source code generated on: Tue Mar 01 12:25:32 2016
 *
 */

/* Include files */
#include "MySVD.h"
#include "MySVD_emxutil.h"

/* Function Declarations */
static void b_eml_xaxpy(int32_T n, real_T a, const emxArray_real_T *x, int32_T
  ix0, emxArray_real_T *y, int32_T iy0);
static real_T b_eml_xnrm2(int32_T n, const emxArray_real_T *x, int32_T ix0);
static void b_eml_xscal(int32_T n, real_T a, emxArray_real_T *x, int32_T ix0);
static void c_eml_xaxpy(int32_T n, real_T a, const emxArray_real_T *x, int32_T
  ix0, emxArray_real_T *y, int32_T iy0);
static real_T eml_div(real_T x, real_T y);
static void eml_xaxpy(int32_T n, real_T a, int32_T ix0, emxArray_real_T *y,
                      int32_T iy0);
static real_T eml_xdotc(int32_T n, const emxArray_real_T *x, int32_T ix0, const
  emxArray_real_T *y, int32_T iy0);
static void eml_xgesvd(const emxArray_real_T *A, emxArray_real_T *U,
  emxArray_real_T *S, emxArray_real_T *V);
static real_T eml_xnrm2(int32_T n, const emxArray_real_T *x, int32_T ix0);
static void eml_xrot(int32_T n, emxArray_real_T *x, int32_T ix0, int32_T iy0,
                     real_T c, real_T s);
static void eml_xrotg(real_T *a, real_T *b, real_T *c, real_T *s);
static void eml_xscal(int32_T n, real_T a, emxArray_real_T *x, int32_T ix0);
static void eml_xswap(int32_T n, emxArray_real_T *x, int32_T ix0, int32_T iy0);

/* Function Definitions */
static void b_eml_xaxpy(int32_T n, real_T a, const emxArray_real_T *x, int32_T
  ix0, emxArray_real_T *y, int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if ((n < 1) || (a == 0.0)) {
  } else {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y->data[iy] += a * x->data[ix];
      ix++;
      iy++;
    }
  }
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

static void b_eml_xscal(int32_T n, real_T a, emxArray_real_T *x, int32_T ix0)
{
  int32_T i2;
  int32_T k;
  i2 = (ix0 + n) - 1;
  for (k = ix0; k <= i2; k++) {
    x->data[k - 1] *= a;
  }
}

static void c_eml_xaxpy(int32_T n, real_T a, const emxArray_real_T *x, int32_T
  ix0, emxArray_real_T *y, int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if ((n < 1) || (a == 0.0)) {
  } else {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y->data[iy] += a * x->data[ix];
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

static void eml_xgesvd(const emxArray_real_T *A, emxArray_real_T *U,
  emxArray_real_T *S, emxArray_real_T *V)
{
  emxArray_real_T *b_A;
  int32_T i0;
  int32_T kase;
  emxArray_real_T *s;
  int32_T qs;
  int32_T minnp;
  emxArray_real_T *e;
  emxArray_real_T *work;
  int32_T nrt;
  int32_T nct;
  int32_T q;
  int32_T iter;
  real_T ztest0;
  int32_T jj;
  int32_T pmq;
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
  b_emxInit_real_T(&b_A, 2);
  i0 = b_A->size[0] * b_A->size[1];
  b_A->size[0] = A->size[0];
  b_A->size[1] = A->size[1];
  emxEnsureCapacity((emxArray__common *)b_A, i0, (int32_T)sizeof(real_T));
  kase = A->size[0] * A->size[1];
  for (i0 = 0; i0 < kase; i0++) {
    b_A->data[i0] = A->data[i0];
  }

  emxInit_real_T(&s, 1);
  kase = A->size[0];
  qs = A->size[1];
  if (kase <= qs) {
    minnp = kase;
  } else {
    minnp = qs;
  }

  kase = A->size[0] + 1;
  qs = A->size[1];
  if (kase <= qs) {
  } else {
    kase = qs;
  }

  i0 = s->size[0];
  s->size[0] = kase;
  emxEnsureCapacity((emxArray__common *)s, i0, (int32_T)sizeof(real_T));
  for (i0 = 0; i0 < kase; i0++) {
    s->data[i0] = 0.0;
  }

  emxInit_real_T(&e, 1);
  kase = A->size[1];
  i0 = e->size[0];
  e->size[0] = kase;
  emxEnsureCapacity((emxArray__common *)e, i0, (int32_T)sizeof(real_T));
  for (i0 = 0; i0 < kase; i0++) {
    e->data[i0] = 0.0;
  }

  emxInit_real_T(&work, 1);
  kase = A->size[0];
  i0 = work->size[0];
  work->size[0] = kase;
  emxEnsureCapacity((emxArray__common *)work, i0, (int32_T)sizeof(real_T));
  for (i0 = 0; i0 < kase; i0++) {
    work->data[i0] = 0.0;
  }

  kase = A->size[0];
  qs = A->size[0];
  i0 = U->size[0] * U->size[1];
  U->size[0] = kase;
  emxEnsureCapacity((emxArray__common *)U, i0, (int32_T)sizeof(real_T));
  i0 = U->size[0] * U->size[1];
  U->size[1] = qs;
  emxEnsureCapacity((emxArray__common *)U, i0, (int32_T)sizeof(real_T));
  kase *= qs;
  for (i0 = 0; i0 < kase; i0++) {
    U->data[i0] = 0.0;
  }

  kase = A->size[1];
  qs = A->size[1];
  i0 = V->size[0] * V->size[1];
  V->size[0] = kase;
  emxEnsureCapacity((emxArray__common *)V, i0, (int32_T)sizeof(real_T));
  i0 = V->size[0] * V->size[1];
  V->size[1] = qs;
  emxEnsureCapacity((emxArray__common *)V, i0, (int32_T)sizeof(real_T));
  kase *= qs;
  for (i0 = 0; i0 < kase; i0++) {
    V->data[i0] = 0.0;
  }

  if ((A->size[0] == 0) || (A->size[1] == 0)) {
    kase = A->size[0];
    qs = A->size[0];
    if (kase <= qs) {
      i0 = kase;
    } else {
      i0 = qs;
    }

    for (kase = 0; kase + 1 <= i0; kase++) {
      U->data[kase + U->size[0] * kase] = 1.0;
    }

    kase = A->size[1];
    qs = A->size[1];
    if (kase <= qs) {
      i0 = kase;
    } else {
      i0 = qs;
    }

    for (kase = 0; kase + 1 <= i0; kase++) {
      V->data[kase + V->size[0] * kase] = 1.0;
    }
  } else {
    if (A->size[1] < 2) {
      kase = 2;
    } else {
      kase = A->size[1];
    }

    kase -= 2;
    qs = A->size[0];
    if (kase <= qs) {
      nrt = kase;
    } else {
      nrt = qs;
    }

    kase = A->size[0];
    kase--;
    qs = A->size[1];
    if (kase <= qs) {
      nct = kase;
    } else {
      nct = qs;
    }

    if (nct >= nrt) {
      i0 = nct;
    } else {
      i0 = nrt;
    }

    for (q = 0; q + 1 <= i0; q++) {
      qs = q + A->size[0] * q;
      iter = A->size[0] - q;
      if (q + 1 <= nct) {
        ztest0 = eml_xnrm2(iter, b_A, qs + 1);
        if (ztest0 > 0.0) {
          if (b_A->data[qs] < 0.0) {
            ztest0 = -ztest0;
          }

          s->data[q] = ztest0;
          ztest0 = eml_div(1.0, s->data[q]);
          eml_xscal(iter, ztest0, b_A, qs + 1);
          b_A->data[qs]++;
          s->data[q] = -s->data[q];
        } else {
          s->data[q] = 0.0;
        }
      }

      for (jj = q + 1; jj + 1 <= A->size[1]; jj++) {
        kase = q + A->size[0] * jj;
        if ((q + 1 <= nct) && (s->data[q] != 0.0)) {
          ztest0 = eml_xdotc(iter, b_A, qs + 1, b_A, kase + 1);
          ztest0 = -eml_div(ztest0, b_A->data[q + b_A->size[0] * q]);
          eml_xaxpy(iter, ztest0, qs + 1, b_A, kase + 1);
        }

        e->data[jj] = b_A->data[kase];
      }

      if (q + 1 <= nct) {
        for (kase = q; kase + 1 <= A->size[0]; kase++) {
          U->data[kase + U->size[0] * q] = b_A->data[kase + b_A->size[0] * q];
        }
      }

      if (q + 1 <= nrt) {
        pmq = (A->size[1] - q) - 1;
        ztest0 = b_eml_xnrm2(pmq, e, q + 2);
        if (ztest0 == 0.0) {
          e->data[q] = 0.0;
        } else {
          if (e->data[q + 1] < 0.0) {
            ztest0 = -ztest0;
          }

          e->data[q] = ztest0;
          ztest0 = eml_div(1.0, e->data[q]);
          b_eml_xscal(pmq, ztest0, e, q + 2);
          e->data[q + 1]++;
        }

        e->data[q] = -e->data[q];
        if ((q + 2 <= A->size[0]) && (e->data[q] != 0.0)) {
          for (kase = q + 1; kase + 1 <= A->size[0]; kase++) {
            work->data[kase] = 0.0;
          }

          for (jj = q + 1; jj + 1 <= A->size[1]; jj++) {
            b_eml_xaxpy(iter - 1, e->data[jj], b_A, (q + A->size[0] * jj) + 2,
                        work, q + 2);
          }

          for (jj = q + 1; jj + 1 <= A->size[1]; jj++) {
            ztest0 = eml_div(-e->data[jj], e->data[q + 1]);
            c_eml_xaxpy(iter - 1, ztest0, work, q + 2, b_A, (q + A->size[0] * jj)
                        + 2);
          }
        }

        for (kase = q + 1; kase + 1 <= A->size[1]; kase++) {
          V->data[kase + V->size[0] * q] = e->data[kase];
        }
      }
    }

    kase = A->size[1];
    qs = A->size[0] + 1;
    if (kase <= qs) {
      m = kase;
    } else {
      m = qs;
    }

    if (nct < A->size[1]) {
      s->data[nct] = b_A->data[nct + b_A->size[0] * nct];
    }

    if (A->size[0] < m) {
      s->data[m - 1] = 0.0;
    }

    if (nrt + 1 < m) {
      e->data[nrt] = b_A->data[nrt + b_A->size[0] * (m - 1)];
    }

    e->data[m - 1] = 0.0;
    if (nct + 1 <= A->size[0]) {
      for (jj = nct; jj + 1 <= A->size[0]; jj++) {
        for (kase = 1; kase <= A->size[0]; kase++) {
          U->data[(kase + U->size[0] * jj) - 1] = 0.0;
        }

        U->data[jj + U->size[0] * jj] = 1.0;
      }
    }

    for (q = nct - 1; q + 1 > 0; q--) {
      iter = A->size[0] - q;
      qs = q + A->size[0] * q;
      if (s->data[q] != 0.0) {
        for (jj = q; jj + 2 <= A->size[0]; jj++) {
          kase = (q + A->size[0] * (jj + 1)) + 1;
          ztest0 = eml_xdotc(iter, U, qs + 1, U, kase);
          ztest0 = -eml_div(ztest0, U->data[qs]);
          eml_xaxpy(iter, ztest0, qs + 1, U, kase);
        }

        for (kase = q; kase + 1 <= A->size[0]; kase++) {
          U->data[kase + U->size[0] * q] = -U->data[kase + U->size[0] * q];
        }

        U->data[qs]++;
        for (kase = 1; kase <= q; kase++) {
          U->data[(kase + U->size[0] * q) - 1] = 0.0;
        }
      } else {
        for (kase = 1; kase <= A->size[0]; kase++) {
          U->data[(kase + U->size[0] * q) - 1] = 0.0;
        }

        U->data[qs] = 1.0;
      }
    }

    for (q = A->size[1] - 1; q + 1 > 0; q--) {
      if ((q + 1 <= nrt) && (e->data[q] != 0.0)) {
        pmq = (A->size[1] - q) - 1;
        kase = (q + A->size[1] * q) + 2;
        for (jj = q; jj + 2 <= A->size[1]; jj++) {
          qs = (q + A->size[1] * (jj + 1)) + 2;
          ztest0 = eml_xdotc(pmq, V, kase, V, qs);
          ztest0 = -eml_div(ztest0, V->data[kase - 1]);
          eml_xaxpy(pmq, ztest0, kase, V, qs);
        }
      }

      for (kase = 1; kase <= A->size[1]; kase++) {
        V->data[(kase + V->size[0] * q) - 1] = 0.0;
      }

      V->data[q + V->size[0] * q] = 1.0;
    }

    for (q = 0; q + 1 <= m; q++) {
      if (s->data[q] != 0.0) {
        ztest = fabs(s->data[q]);
        ztest0 = eml_div(s->data[q], ztest);
        s->data[q] = ztest;
        if (q + 1 < m) {
          e->data[q] = eml_div(e->data[q], ztest0);
        }

        if (q + 1 <= A->size[0]) {
          i0 = A->size[0] * q + 1;
          eml_xscal(A->size[0], ztest0, U, i0);
        }
      }

      if ((q + 1 < m) && (e->data[q] != 0.0)) {
        ztest = fabs(e->data[q]);
        ztest0 = eml_div(ztest, e->data[q]);
        e->data[q] = ztest;
        s->data[q + 1] *= ztest0;
        i0 = A->size[1] * (q + 1) + 1;
        eml_xscal(A->size[1], ztest0, V, i0);
      }
    }

    nct = m;
    iter = 0;
    tiny = eml_div(2.2250738585072014E-308, 2.2204460492503131E-16);
    snorm = 0.0;
    for (kase = 0; kase + 1 <= m; kase++) {
      ztest0 = fabs(s->data[kase]);
      ztest = fabs(e->data[kase]);
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
        if ((ztest0 <= 2.2204460492503131E-16 * (fabs(s->data[q - 1]) + fabs
              (s->data[q]))) || (ztest0 <= tiny) || ((iter > 20) && (ztest0 <=
              2.2204460492503131E-16 * snorm))) {
          e->data[q - 1] = 0.0;
          exitg2 = TRUE;
        } else {
          q--;
        }
      }

      if (q == m - 1) {
        kase = 4;
      } else {
        qs = m;
        kase = m;
        exitg1 = FALSE;
        while ((exitg1 == FALSE) && (kase >= q)) {
          qs = kase;
          if (kase == q) {
            exitg1 = TRUE;
          } else {
            ztest0 = 0.0;
            if (kase < m) {
              ztest0 = fabs(e->data[kase - 1]);
            }

            if (kase > q + 1) {
              ztest0 += fabs(e->data[kase - 2]);
            }

            ztest = fabs(s->data[kase - 1]);
            if ((ztest <= 2.2204460492503131E-16 * ztest0) || (ztest <= tiny)) {
              s->data[kase - 1] = 0.0;
              exitg1 = TRUE;
            } else {
              kase--;
            }
          }
        }

        if (qs == q) {
          kase = 3;
        } else if (qs == m) {
          kase = 1;
        } else {
          kase = 2;
          q = qs;
        }
      }

      switch (kase) {
       case 1:
        ztest = e->data[m - 2];
        e->data[m - 2] = 0.0;
        for (kase = m - 2; kase + 1 >= q + 1; kase--) {
          ztest0 = s->data[kase];
          eml_xrotg(&ztest0, &ztest, &emm1, &sm);
          s->data[kase] = ztest0;
          if (kase + 1 > q + 1) {
            ztest = -sm * e->data[kase - 1];
            e->data[kase - 1] *= emm1;
          }

          i0 = A->size[1] * kase + 1;
          pmq = A->size[1] * (m - 1) + 1;
          eml_xrot(A->size[1], V, i0, pmq, emm1, sm);
        }
        break;

       case 2:
        ztest = e->data[q - 1];
        e->data[q - 1] = 0.0;
        for (kase = q; kase + 1 <= m; kase++) {
          eml_xrotg(&s->data[kase], &ztest, &emm1, &sm);
          ztest = -sm * e->data[kase];
          e->data[kase] *= emm1;
          i0 = A->size[0] * kase + 1;
          pmq = A->size[0] * (q - 1) + 1;
          eml_xrot(A->size[0], U, i0, pmq, emm1, sm);
        }
        break;

       case 3:
        varargin_1[0] = fabs(s->data[m - 1]);
        varargin_1[1] = fabs(s->data[m - 2]);
        varargin_1[2] = fabs(e->data[m - 2]);
        varargin_1[3] = fabs(s->data[q]);
        varargin_1[4] = fabs(e->data[q]);
        ztest0 = varargin_1[0];
        for (kase = 0; kase < 4; kase++) {
          if (varargin_1[kase + 1] > ztest0) {
            ztest0 = varargin_1[kase + 1];
          }
        }

        sm = eml_div(s->data[m - 1], ztest0);
        ztest = eml_div(s->data[m - 2], ztest0);
        emm1 = eml_div(e->data[m - 2], ztest0);
        sqds = eml_div(s->data[q], ztest0);
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
        for (kase = q + 1; kase < m; kase++) {
          eml_xrotg(&ztest, &ztest0, &emm1, &sm);
          if (kase > q + 1) {
            e->data[kase - 2] = ztest;
          }

          ztest0 = emm1 * s->data[kase - 1];
          ztest = sm * e->data[kase - 1];
          e->data[kase - 1] = emm1 * e->data[kase - 1] - sm * s->data[kase - 1];
          b = s->data[kase];
          s->data[kase] *= emm1;
          i0 = A->size[1] * (kase - 1) + 1;
          pmq = A->size[1] * kase + 1;
          eml_xrot(A->size[1], V, i0, pmq, emm1, sm);
          s->data[kase - 1] = ztest0 + ztest;
          ztest0 = sm * b;
          eml_xrotg(&s->data[kase - 1], &ztest0, &emm1, &sm);
          ztest = emm1 * e->data[kase - 1] + sm * s->data[kase];
          s->data[kase] = -sm * e->data[kase - 1] + emm1 * s->data[kase];
          ztest0 = sm * e->data[kase];
          e->data[kase] *= emm1;
          if (kase < A->size[0]) {
            i0 = A->size[0] * (kase - 1) + 1;
            pmq = A->size[0] * kase + 1;
            eml_xrot(A->size[0], U, i0, pmq, emm1, sm);
          }
        }

        e->data[m - 2] = ztest;
        iter++;
        break;

       default:
        if (s->data[q] < 0.0) {
          s->data[q] = -s->data[q];
          i0 = A->size[1] * q + 1;
          eml_xscal(A->size[1], -1.0, V, i0);
        }

        qs = q + 1;
        while ((q + 1 < nct) && (s->data[q] < s->data[qs])) {
          ztest = s->data[q];
          s->data[q] = s->data[qs];
          s->data[qs] = ztest;
          if (q + 1 < A->size[1]) {
            i0 = A->size[1] * q + 1;
            pmq = A->size[1] * (q + 1) + 1;
            eml_xswap(A->size[1], V, i0, pmq);
          }

          if (q + 1 < A->size[0]) {
            i0 = A->size[0] * q + 1;
            pmq = A->size[0] * (q + 1) + 1;
            eml_xswap(A->size[0], U, i0, pmq);
          }

          q = qs;
          qs++;
        }

        iter = 0;
        m--;
        break;
      }
    }
  }

  emxFree_real_T(&work);
  emxFree_real_T(&e);
  emxFree_real_T(&b_A);
  i0 = S->size[0];
  S->size[0] = minnp;
  emxEnsureCapacity((emxArray__common *)S, i0, (int32_T)sizeof(real_T));
  for (kase = 0; kase + 1 <= minnp; kase++) {
    S->data[kase] = s->data[kase];
  }

  emxFree_real_T(&s);
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

void MySVD(const emxArray_real_T *X, emxArray_real_T *U, emxArray_real_T *S,
           emxArray_real_T *V)
{
  emxArray_real_T *s;
  uint32_T uv0[2];
  int32_T k;
  int32_T loop_ub;
  emxInit_real_T(&s, 1);
  eml_xgesvd(X, U, s, V);
  for (k = 0; k < 2; k++) {
    uv0[k] = (uint32_T)X->size[k];
  }

  k = S->size[0] * S->size[1];
  S->size[0] = (int32_T)uv0[0];
  emxEnsureCapacity((emxArray__common *)S, k, (int32_T)sizeof(real_T));
  k = S->size[0] * S->size[1];
  S->size[1] = (int32_T)uv0[1];
  emxEnsureCapacity((emxArray__common *)S, k, (int32_T)sizeof(real_T));
  loop_ub = (int32_T)uv0[0] * (int32_T)uv0[1];
  for (k = 0; k < loop_ub; k++) {
    S->data[k] = 0.0;
  }

  for (k = 0; k < s->size[0]; k++) {
    S->data[((int32_T)(1.0 + (real_T)k) + S->size[0] * ((int32_T)(1.0 + (real_T)
               k) - 1)) - 1] = s->data[(int32_T)(1.0 + (real_T)k) - 1];
  }

  emxFree_real_T(&s);
}

/* End of code generation (MySVD.cpp) */
