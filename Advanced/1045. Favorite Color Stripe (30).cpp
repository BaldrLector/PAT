/*1045. Favorite Color Stripe (30)
时间限制
200 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Eva is trying to make her own color stripe out of a given one. She would like to keep only her favorite colors in her favorite order by cutting off those unwanted pieces and sewing the remaining parts together to form her favorite color stripe.

It is said that a normal human eye can distinguish about less than 200 different colors, so Eva's favorite colors are limited. However the original stripe could be very long, and Eva would like to have the remaining favorite stripe with the maximum length. So she needs your help to find her the best result.

Note that the solution might not be unique, but you only have to tell her the maximum length. For example, given a stripe of colors {2 2 4 1 5 5 6 3 1 1 5 6}. If Eva's favorite colors are given in her favorite order as {2 3 1 5 6}, then she has 4 possible best solutions {2 2 1 1 1 5 6}, {2 2 1 5 5 5 6}, {2 2 1 5 5 6 6}, and {2 2 3 1 1 5 6}.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=200) which is the total number of colors involved (and hence the colors are numbered from 1 to N). Then the next line starts with a positive integer M (<=200) followed by M Eva's favorite color numbers given in her favorite order. Finally the third line starts with a positive integer L (<=10000) which is the length of the given stripe, followed by L colors on the stripe. All the numbers in a line are separated by a space.

Output Specification:

For each test case, simply print in a line the maximum length of Eva's favorite stripe.

Sample Input:
6
5 2 3 1 5 6
12 2 2 4 1 5 5 6 3 1 1 5 6
Sample Output:
7*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 10010;
const int INF = 0xfffffff;

const int maxc = 210;

int A[maxn], B[maxn], dp[maxc][maxn];

int main() {
    freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    int n, m, L;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &A[i]);
    }
    scanf("%d", &L);

    for (int i = 1; i <= L; ++i) {
        scanf("%d", &B[i]);
    }      
    
    //boundary
    for (int i = 0; i <= m; ++i) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= L; ++i) {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= L; ++j) {
            int MAX = max(dp[i - 1][j], dp[i][j - 1]);
            if (A[i] == B[j]) {
                dp[i][j] = MAX + 1;
            } else {
                dp[i][j] = MAX;
            }
        }
    }
    printf("%d\n", dp[m][L]);

    return 0;
}
