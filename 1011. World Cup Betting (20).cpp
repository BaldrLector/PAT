#include<cstdio>

char mp[3] = {'W', 'T', 'L'};
int main() {
    double ans=1;
    for (int i = 0; i < 3; i++) {
        double m, tmp;
        int m_index = 0;
        scanf("%lf", &m);
        for (int j = 0; j < 2; ++j) {
            scanf("%lf", &tmp);
            if (m < tmp) {
                m = tmp;
                m_index = j+1;
            }
        }
        ans *= m;
        printf("%c ", mp[m_index]);
    }
    printf("%.2f", (ans * 0.65 - 1) * 2);
}
