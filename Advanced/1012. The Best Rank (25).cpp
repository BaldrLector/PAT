#include<cstdio>
#include <algorithm>

const int maxn = 2010;
char course[4] = { 'A','C', 'M', 'E'};
int Rank[100000000][4]={0};
struct stu {
    int id;
    int score[4];
} s[maxn];

int now;
bool cmp(stu a,stu b){
    return a.score[now]>b.score[now];
}

int main() {
    freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%d", &s[i].id,&s[i].score[1], &s[i].score[2], &s[i].score[3]);
        s[i].score[0] = (s[i].score[1] + s[i].score[2] + s[i].score[3]);
    }
    for (now = 0; now <4; ++now) {
        std::sort(s, s + n,cmp);
        Rank[s[0].id] [now]=1;
        for (int i = 0; i < n; ++i) {
            if(s[i].score[now]==s[i-1].score[now]){
                Rank[s[i].id][now]=Rank[s[i-1].id][now];
            } else{
                Rank[s[i].id][now]=i+1;
            }
        }
    }
    int query;
    for(int i=0;i<m;i++){
        scanf("%d", &query);
        if(Rank[query][0]==0){
            printf("N/A\n");
        } else{
            int k=0;
            for(int j=0;j<4;j++){
                if(Rank[query][j]<Rank[query][k]){
                    k=j;
                }
            }
            printf("%d %c\n", Rank[query][k], course[k]);
        }
    }
    return 0;
}
