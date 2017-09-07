#include<cstdio>

const int maxn = 10010;

int main() {
    float p[maxn] = {0};
    int n, index;
    float coef;
    for (int i = 0; i < 2; i++) {
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            scanf("%d%f", &index, &coef);
            p[index] += coef;
        }
    }
    int num = 0;
    for (int i = 0; i < maxn; i++) {
        if (p[i] != 0) {
            num++;
        }
    }
    printf("%d", num);
    for (int i = maxn-1; i >= 0; i--) {
        if (p[i] != 0) {
            printf(" %d %.1f", i, p[i]);
        }
    }
    return 0;
}
