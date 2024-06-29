#include"Header.h"
int CountXM(int m, int n) {
    if (n == 1 || m == 1) {
        return 1;
    }
    if (n > m)
    {
        return CountXM(m, m);
    }
    if (m == n)
    {
        return CountXM(m, n - 1) + 1;
    }

    if (n < m)
    {
        return CountXM(m, (n - 1)) + CountXM((m - n), n);
    }
    if (m == 0)
        return 1;
    int count = 0;
    for (int i = 1; i <= n && i <= m; i++) {
        count += CountXM(m - i, i);
    }
    return count;
}
double Calculate(int n, int m = 1) {
    if (m == n) 
        return sqrt(1 + n + n);
    else 
        return sqrt(1 + (n + m) * Calculate(n, m + 1));
}
