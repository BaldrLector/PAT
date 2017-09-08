/*1046. Shortest Distance (20)
时间限制
100 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
The task is really simple: given N exits on a highway which forms a simple cycle, you are supposed to tell the shortest distance between any pair of exits.

Input Specification:

Each input file contains one test case. For each case, the first line contains an integer N (in [3, 105]), followed by N integer distances D1 D2 ... DN, where Di is the distance between the i-th and the (i+1)-st exits, and DN is between the N-th and the 1st exits. All the numbers in a line are separated by a space. The second line gives a positive integer M (<=104), with M lines follow, each contains a pair of exit numbers, provided that the exits are numbered from 1 to N. It is guaranteed that the total round trip distance is no more than 107.

Output Specification:

For each test case, print your results in M lines, each contains the shortest distance between the corresponding given pair of exits.

Sample Input:
5 1 2 4 14 9
3
1 3
2 5
4 1
Sample Output:
3
10
7*/

#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 100010;
const int INF = 0xfffffff;


int d[maxn];

int main() {
    freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    int n, m;
    scanf("%d", &n);
    d[0] = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &d[i]);
        d[i] += d[i - 1];
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        if(a>b) swap(a,b);
        printf("%d\n", min(d[b-1]-d[a-1],d[n]+d[a-1]-d[b-1]));
    }

    return 0;
}
