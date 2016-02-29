/*
 * MySVD.cpp
 *
 * Code generation for function 'MySVD'
 *
 * C source code generated on: Fri Feb 26 11:23:40 2016
 *
 */

/* Include files */
#include "MySVD.h"

/* Function Declarations */
static void b_eml_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[16], int32_T
  iy0);
static real_T b_eml_xdotc(int32_T n, const real_T x[16], int32_T ix0, const
  real_T y[16], int32_T iy0);
static void b_eml_xrot(real_T x[16], int32_T ix0, int32_T iy0, real_T c, real_T
  s);
static void b_eml_xscal(real_T a, real_T x[16], int32_T ix0);
static void b_eml_xswap(real_T x[16], int32_T ix0, int32_T iy0);
static void c_eml_xscal(real_T a, real_T x[4], int32_T ix0);
static real_T eml_div(real_T x, real_T y);
static void eml_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[8], int32_T iy0);
static real_T eml_xdotc(int32_T n, const real_T x[8], int32_T ix0, const real_T
  y[8], int32_T iy0);
static void eml_xgesvd(const real_T A[8], real_T U[16], real_T S[2], real_T V[4]);
static real_T eml_xnrm2(int32_T n, const real_T x[8], int32_T ix0);
static void eml_xrot(real_T x[4], int32_T ix0, int32_T iy0, real_T c, real_T s);
static void eml_xrotg(real_T *a, real_T *b, real_T *c, real_T *s);
static void eml_xscal(int32_T n, real_T a, real_T x[8], int32_T ix0);
static void eml_xswap(real_T x[4], int32_T ix0, int32_T iy0);

/* Function Definitions */
static void b_eml_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[16], int32_T
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

static void b_eml_xscal(real_T a, real_T x[16], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 3; k++) {
    x[k - 1] *= a;
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

static void eml_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[8], int32_T iy0)
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

static real_T eml_xdotc(int32_T n, const real_T x[8], int32_T ix0, const real_T
  y[8], int32_T iy0)
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

static void eml_xgesvd(const real_T A[8], real_T U[16], real_T S[2], real_T V[4])
{
  real_T b_A[8];
  real_T s[2];
  int32_T i;
  int32_T q;
  int32_T iter;
  real_T ztest0;
  int32_T m;
  real_T e[2];
  int32_T qs;
  real_T rt;
  real_T ztest;
  real_T tiny;
  real_T snorm;
  boolean_T exitg2;
  boolean_T exitg1;
  real_T sn;
  real_T varargin_1[5];
  real_T sqds;
  real_T b;
  memcpy(&b_A[0], &A[0], sizeof(real_T) << 3);
  for (i = 0; i < 2; i++) {
    s[i] = 0.0;
  }

  memset(&U[0], 0, sizeof(real_T) << 4);
  memset(&V[0], 0, sizeof(real_T) << 2);
  for (q = 0; q < 2; q++) {
    iter = q + (q << 2);
    ztest0 = eml_xnrm2(4 - q, b_A, iter + 1);
    if (ztest0 > 0.0) {
      if (b_A[iter] < 0.0) {
        s[q] = -ztest0;
      } else {
        s[q] = ztest0;
      }

      eml_xscal(4 - q, eml_div(1.0, s[q]), b_A, iter + 1);
      b_A[iter]++;
      s[q] = -s[q];
    } else {
      s[q] = 0.0;
    }

    i = q + 2;
    while (i < 3) {
      if (s[q] != 0.0) {
        eml_xaxpy(4 - q, -eml_div(eml_xdotc(4 - q, b_A, iter + 1, b_A, q + 5),
                   b_A[q + (q << 2)]), iter + 1, b_A, q + 5);
      }

      i = 3;
    }

    for (i = q; i + 1 < 5; i++) {
      U[i + (q << 2)] = b_A[i + (q << 2)];
    }
  }

  m = 1;
  e[0] = b_A[4];
  e[1] = 0.0;
  for (i = 0; i < 2; i++) {
    memset(&U[(i + 2) << 2], 0, sizeof(real_T) << 2);
    U[(i + ((i + 2) << 2)) + 2] = 1.0;
  }

  for (q = 1; q > -1; q += -1) {
    iter = q + (q << 2);
    if (s[q] != 0.0) {
      for (i = q + 1; i + 1 < 5; i++) {
        qs = (q + (i << 2)) + 1;
        b_eml_xaxpy(4 - q, -eml_div(b_eml_xdotc(4 - q, U, iter + 1, U, qs),
          U[iter]), iter + 1, U, qs);
      }

      for (i = q; i + 1 < 5; i++) {
        U[i + (q << 2)] = -U[i + (q << 2)];
      }

      U[iter]++;
      i = 1;
      while (i <= q) {
        U[4] = 0.0;
        i = 2;
      }
    } else {
      memset(&U[q << 2], 0, sizeof(real_T) << 2);
      U[iter] = 1.0;
    }
  }

  for (q = 1; q > -1; q += -1) {
    for (i = 0; i < 2; i++) {
      V[i + (q << 1)] = 0.0;
    }

    V[q + (q << 1)] = 1.0;
  }

  ztest0 = b_A[4];
  for (q = 0; q < 2; q++) {
    if (s[q] != 0.0) {
      rt = fabs(s[q]);
      ztest = eml_div(s[q], rt);
      s[q] = rt;
      if (q + 1 < 2) {
        ztest0 = eml_div(ztest0, ztest);
      }

      b_eml_xscal(ztest, U, (q << 2) + 1);
    }

    if ((q + 1 < 2) && (ztest0 != 0.0)) {
      rt = fabs(ztest0);
      ztest = eml_div(rt, ztest0);
      ztest0 = rt;
      s[1] *= ztest;
      c_eml_xscal(ztest, V, 3);
    }

    e[0] = ztest0;
  }

  iter = 0;
  tiny = eml_div(2.2250738585072014E-308, 2.2204460492503131E-16);
  snorm = 0.0;
  for (i = 0; i < 2; i++) {
    ztest0 = fabs(s[i]);
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

  while ((m + 1 > 0) && (!(iter >= 75))) {
    q = m;
    exitg2 = FALSE;
    while (!((exitg2 == TRUE) || (q == 0))) {
      ztest0 = fabs(e[0]);
      if ((ztest0 <= 2.2204460492503131E-16 * (fabs(s[0]) + fabs(s[1]))) ||
          (ztest0 <= tiny) || ((iter > 20) && (ztest0 <= 2.2204460492503131E-16 *
            snorm))) {
        e[0] = 0.0;
        exitg2 = TRUE;
      } else {
        q = 0;
      }
    }

    if (q == m) {
      i = 4;
    } else {
      qs = m + 1;
      i = m + 1;
      exitg1 = FALSE;
      while ((exitg1 == FALSE) && (i >= q)) {
        qs = i;
        if (i == q) {
          exitg1 = TRUE;
        } else {
          ztest0 = 0.0;
          if (i < m + 1) {
            ztest0 = fabs(e[0]);
          }

          if (i > q + 1) {
            ztest0 += fabs(e[0]);
          }

          ztest = fabs(s[i - 1]);
          if ((ztest <= 2.2204460492503131E-16 * ztest0) || (ztest <= tiny)) {
            s[i - 1] = 0.0;
            exitg1 = TRUE;
          } else {
            i--;
          }
        }
      }

      if (qs == q) {
        i = 3;
      } else if (qs == m + 1) {
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
      i = m;
      while (i >= q + 1) {
        ztest0 = s[0];
        eml_xrotg(&ztest0, &ztest, &rt, &sn);
        s[0] = ztest0;
        eml_xrot(V, 1, (m << 1) + 1, rt, sn);
        i = 0;
      }
      break;

     case 2:
      ztest = e[q - 1];
      e[q - 1] = 0.0;
      for (i = q; i + 1 <= m + 1; i++) {
        eml_xrotg(&s[i], &ztest, &rt, &sn);
        ztest = -sn * e[i];
        e[i] *= rt;
        b_eml_xrot(U, (i << 2) + 1, ((q - 1) << 2) + 1, rt, sn);
      }
      break;

     case 3:
      varargin_1[0] = fabs(s[m]);
      varargin_1[1] = fabs(s[m - 1]);
      varargin_1[2] = fabs(e[m - 1]);
      varargin_1[3] = fabs(s[q]);
      varargin_1[4] = fabs(e[q]);
      sn = varargin_1[0];
      for (i = 0; i < 4; i++) {
        if (varargin_1[i + 1] > sn) {
          sn = varargin_1[i + 1];
        }
      }

      rt = eml_div(s[m], sn);
      ztest0 = eml_div(s[0], sn);
      ztest = eml_div(e[0], sn);
      sqds = eml_div(s[q], sn);
      b = eml_div((ztest0 + rt) * (ztest0 - rt) + ztest * ztest, 2.0);
      ztest0 = rt * ztest;
      ztest0 *= ztest0;
      ztest = 0.0;
      if ((b != 0.0) || (ztest0 != 0.0)) {
        ztest = sqrt(b * b + ztest0);
        if (b < 0.0) {
          ztest = -ztest;
        }

        ztest = eml_div(ztest0, b + ztest);
      }

      ztest += (sqds + rt) * (sqds - rt);
      ztest0 = sqds * eml_div(e[q], sn);
      while (q + 1 <= m) {
        eml_xrotg(&ztest, &ztest0, &rt, &sn);
        ztest0 = rt * s[0];
        ztest = sn * e[0];
        e[0] = rt * e[0] - sn * s[0];
        b = s[1];
        s[1] *= rt;
        eml_xrot(V, 1, 3, rt, sn);
        s[0] = ztest0 + ztest;
        ztest0 = sn * b;
        eml_xrotg(&s[0], &ztest0, &rt, &sn);
        ztest = rt * e[0] + sn * s[1];
        s[1] = -sn * e[0] + rt * s[1];
        ztest0 = sn * e[1];
        e[1] *= rt;
        b_eml_xrot(U, 1, 5, rt, sn);
        q = 1;
      }

      e[0] = ztest;
      iter++;
      break;

     default:
      if (s[q] < 0.0) {
        s[q] = -s[q];
        c_eml_xscal(-1.0, V, (q << 1) + 1);
      }

      while ((q + 1 < 2) && (s[0] < s[1])) {
        rt = s[0];
        s[0] = s[1];
        s[1] = rt;
        eml_xswap(V, 1, 3);
        b_eml_xswap(U, 1, 5);
        q = 1;
      }

      iter = 0;
      m--;
      break;
    }
  }

  for (i = 0; i < 2; i++) {
    S[i] = s[i];
  }
}

static real_T eml_xnrm2(int32_T n, const real_T x[8], int32_T ix0)
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
    y = fabs(x[ix0 - 1]);
  } else {
    scale = 2.2250738585072014E-308;
    kend = (ix0 + n) - 1;
    for (k = ix0; k <= kend; k++) {
      absxk = fabs(x[k - 1]);
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

static void eml_xscal(int32_T n, real_T a, real_T x[8], int32_T ix0)
{
  int32_T i0;
  int32_T k;
  i0 = (ix0 + n) - 1;
  for (k = ix0; k <= i0; k++) {
    x[k - 1] *= a;
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

void MySVD(const real_T X[8], real_T U[16], real_T S[8], real_T V[4])
{
  real_T s[2];
  int32_T k;

  /* { */
  /* x = X(:,1); */
  /* y = X(:,2); */
  /* z = X(:,3); */
  /* P=[mean(x),mean(y),mean(z)]; */
  /* mX =[x-P(1),y-P(2),z-P(3)]; */
  /* } */
  eml_xgesvd(X, U, s, V);
  memset(&S[0], 0, sizeof(real_T) << 3);
  for (k = 0; k < 2; k++) {
    S[k + (k << 2)] = s[k];
  }
}

/* End of code generation (MySVD.cpp) */
