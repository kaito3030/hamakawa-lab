#include <stdio.h>
#include <math.h>

#define N 10

void pipotting(double A[][N+1], int c, int n)
{
    int m, i;
    double t;
    m = c;
    for (i = c + 1; i < n; ++i)
        if (fabs(A[m][c]) < fabs(A[i][c])) m = i;
    for (i = 0; i < n + 1; ++i)
    {
        t = A[m][i]; A[m][i] = A[c][i]; A[c][i] = t;
    }
}

int main()
{
    int n, i, j, k;
    char z, zz;

    static double a[N][N + 1], x[N], p, s;

    for (i = 0; i < n; ++i)  x[i] = 0;

    while (1)
    {
        puts("何元連立方程式ですか？ n =");
        scanf("%d", &n);
        if (n <= 1 || n >= (N - 1)) continue;

        for (i = 0; i < n; ++i)
            for (j = 0; j < n + 1; ++j)
                scanf("%lf", &a[i][j]);

        for (i = 0; i < n; ++i)
        {
            for (j = 0; j < n + 1; ++j)
                printf("%lf ", a[i][j]);
            puts("");
        }
        break;
    }

    for (i = 0; i < n; ++i)
    {
        pipotting(a, i, n);
        p = a[i][i];
        if (fabs(p) < 1.0e-6)
        {
            puts("一意解を持たない");
            return -1;
        }

        for (j = i; j < n + 1; ++j)
            a[i][j] = a[i][j] / p;

        for (j = 0; j < n; ++j)
        {
            if(j == i) continue;
            p = a[j][i];
            for (k = i; k < n + 1; ++k)
                a[j][k] = a[j][k] - a[i][k]  * p;
        }
    }

    for (i = 0; i < n; ++i)
    {
        x[i] = a[i][n];
    }

    for (i = 0; i < n; ++i)
        printf("x%d = %10.6lf\n", i + 1, x[i]);

    return 0;
}
