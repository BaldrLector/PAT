#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 30010;

struct student {
    char id[15];
    int score;
    int local;
    int R, localR;
} s[maxn];

bool cmp(student a, student b) {
    if(a.score!=b.score)
        return a.score>b.score;
    else
        return strcmp(a.id,b.id)<0;
}

int main() {

    int n, k;
    int snum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &k);
        for (int j = 0; j < k; ++j) {
            scanf("%s %d", s[snum].id, &s[snum].score);
            s[snum].local = i;
            snum++;
        }
        sort(s + snum - k, s + snum, cmp);
        s[snum - k].localR = 1;
        for (int j = snum - k + 1; j < snum; j++) {
            if (s[j].score != s[j - 1].score) {
                s[j].localR = j - snum + k + 1;
            } else {
                s[j].localR = s[j - 1].localR;
            }
        }

    }
    sort(s, s + snum, cmp);
    s[0].R = 1;
    for (int i = 1; i < snum; i++) {
        if (s[i].score != s[i - 1].score) {
            s[i].R = i+1;
        } else {
            s[i].R = s[i - 1].R;
        }
    }
    printf("%d\n", snum);
    for (int i = 0; i < snum; i++) {
        printf("%s %d %d %d\n", s[i].id, s[i].R, s[i].local, s[i].localR);
    }

    return 0;
}
