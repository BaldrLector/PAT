/*1062. Talent and Virtue (25)
时间限制
200 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Li
About 900 years ago, a Chinese philosopher Sima Guang wrote a history book in which he talked about people's talent and virtue. According to his theory, a man being outstanding in both talent and virtue must be a "sage（圣人）"; being less excellent but with one's virtue outweighs talent can be called a "nobleman（君子）"; being good in neither is a "fool man（愚人）"; yet a fool man is better than a "small man（小人）" who prefers talent than virtue.

Now given the grades of talent and virtue of a group of people, you are supposed to rank them according to Sima Guang's theory.

Input Specification:

Each input file contains one test case. Each case first gives 3 positive integers in a line: N (<=105), the total number of people to be ranked; L (>=60), the lower bound of the qualified grades -- that is, only the ones whose grades of talent and virtue are both not below this line will be ranked; and H (<100), the higher line of qualification -- that is, those with both grades not below this line are considered as the "sages", and will be ranked in non-increasing order according to their total grades. Those with talent grades below H but virtue grades not are cosidered as the "noblemen", and are also ranked in non-increasing order according to their total grades, but they are listed after the "sages". Those with both grades below H, but with virtue not lower than talent are considered as the "fool men". They are ranked in the same way but after the "noblemen". The rest of people whose grades both pass the L line are ranked after the "fool men".

Then N lines follow, each gives the information of a person in the format:

ID_Number Virtue_Grade Talent_Grade
where ID_Number is an 8-digit number, and both grades are integers in [0, 100]. All the numbers are separated by a space.
Output Specification:

The first line of output must give M (<=N), the total number of people that are actually ranked. Then M lines follow, each gives the information of a person in the same format as the input, according to the ranking rules. If there is a tie of the total grade, they must be ranked with respect to their virtue grades in non-increasing order. If there is still a tie, then output in increasing order of their ID's.

Sample Input:
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60
Sample Output:
12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90*/

#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 100010;
const int INF = 0xfffffff;

struct record {
    int id, dei, cai,sum;
    int flag;
} rec[maxn];

bool cmp(record a,record b){
    if(a.flag!=b.flag) return a.flag<b.flag;
    else if(a.sum!=b.sum) return a.sum>b.sum;
    else if(a.dei!=b.dei) return a.dei>b.dei;
    else return a.id<b.id;
}

vector<record> r;

int main() {
    // freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    int n, L, H;
    scanf("%d%d%d", &n, &L, &H);
    int m=n;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &rec[i].id, &rec[i].dei, &rec[i].cai);
        rec[i].sum=rec[i].dei+rec[i].cai;
        if(rec[i].dei<L||rec[i].cai<L){
            rec[i].flag=5;
            m--;
        } else if(rec[i].dei>=H&&rec[i].cai>=H) rec[i].flag=1;
        else if(rec[i].dei>=H&&rec[i].cai<H)    rec[i].flag=2;
        else if(rec[i].dei>=rec[i].cai) rec[i].flag=3;
        else rec[i].flag=4;
    }
    sort(rec,rec+n,cmp);
    printf("%d\n", m);
    for (int i = 0; i < m; ++i) {
        printf("%d %d %d\n", rec[i].id, rec[i].dei, rec[i].cai);
    }


    return 0;
}
