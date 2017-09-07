#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn=100100;

struct rec{
    char id[10],name[10];
    int score;
}r[maxn];

bool cmp1(rec a,rec b){
    return strcmp(a.id,b.id)<0;
}

bool cmp2(rec a,rec b){
    if(strcmp(a.name,b.name)!=0)    return strcmp(a.name,b.name)<0;
    else return strcmp(a.id,b.id)<0;
}

bool cmp3(rec a,rec b){
    if(a.score!=b.score) return a.score<b.score;
    else return strcmp(a.id,b.id)<0;
}

int main() {
    freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);
    int n,c;
    scanf("%d%d", &n, &c);
    for (int i = 0; i < n; ++i) {
        scanf("%s%s%d", r[i].id, r[i].name, &r[i].score);
    }
    switch (c){
        case 1:sort(r,r+n,cmp1);
            break;
        case 2:sort(r,r+n,cmp2);
            break;
        case 3:sort(r,r+n,cmp3);
            break;
    }

    for (int i = 0; i < n; ++i) {
        printf("%s %s %d\n", r[i].id, r[i].name, r[i].score);
    }

    return 0;
}
