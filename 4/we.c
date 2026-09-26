#include <stdio.h>
#include <stdlib.h>
int main () {
    int n, q;
    int l, r;
    while (scanf("%d %d", &n, &q) != EOF) {
        int* a = malloc (n * sizeof(int));
        int* pre = malloc ((n+1) * sizeof(int));
        pre[0] = 0;
        for (int i = 0; i < n; i++) {
            scanf ("%d", &a[i]);
            pre[i+1] = pre[i] + a[i];
        }
        for (int i = 0; i < q; i++) {
            scanf("%d %d", &l, &r);
            printf ("%d\n", pre[r] - pre[l-1]);
        }
    }
    return 0;
}