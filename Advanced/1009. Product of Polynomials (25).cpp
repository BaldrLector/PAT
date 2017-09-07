#include<cstdio>

const int maxn = 10010;
struct Polynomial {
    int index;
    double coef;
} a[maxn], b[maxn];

int main() {
    int n1, n2;
    scanf("%d", &n1);
    int index, coef;
    for (int i = 0; i < n1; i++) {
        scanf("%d%lf", &a[i].index, &a[i].coef);
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d%lf", &b[i].index, &b[i].coef);
    }
    double ans[maxn] = {0};
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            ans[a[i].index + b[j].index] += a[i].coef * b[j].coef;
        }
    }
    int n = 0;
    for (int i = 0; i < maxn; i++) {
        if (ans[i] != 0) {
            n++;
        }
    }
    printf("%d", n);
    for (int i = maxn - 1; i >= 0; i--) {
        if (ans[i] != 0) {
            printf(" %d %.1f", i, ans[i]);
        }
    }

}
