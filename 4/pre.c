#include<stdio.h>
#include<stdlib.h>
int main() {
    int n, m, q;
    while (scanf("%d %d %d", &n, &m, &q) != EOF) {
        long long *num = malloc (n * m * sizeof(*num));
        long long *pre = malloc ((n + 1) * (m + 1) * sizeof(*num));
        for (int i = 0; i < n; i++) {
            pre[0] = 0;
            pre[(i+1)*(m+1)] = 0;
            for (int j = 0; j < m; j++) {
                scanf ("%lld", &num[i*m + j]);
                if (i == 0) { pre[j+1] = 0;}
                pre[(i+1)*(m+1)+(j+1)] = pre[i*(m+1)+(j+1)] + pre[(i+1)*(m+1)+j] - pre[i*(m+1)+j] + num[i*m+j];
            }
        }
        for (int k = 0; k < q; k++) {
            long long x1, y1, x2, y2;
            scanf ("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
            long long d = pre[x2*(m+1)+y2] - pre[x2*(m+1)+(y1-1)] - pre[(x1-1)*(m+1)+y2] + pre[(x1-1)*(m+1)+(y1-1)];
            printf ("%lld\n", d);
        }
    }
}