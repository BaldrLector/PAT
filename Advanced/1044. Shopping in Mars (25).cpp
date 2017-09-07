/*1044. Shopping in Mars (25)
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
Shopping in Mars is quite a different experience. The Mars people pay by chained diamonds. Each diamond has a value (in Mars dollars M$). When making the payment, the chain can be cut at any position for only once and some of the diamonds are taken off the chain one by one. Once a diamond is off the chain, it cannot be taken back. For example, if we have a chain of 8 diamonds with values M$3, 2, 1, 5, 4, 6, 8, 7, and we must pay M$15. We may have 3 options:

1. Cut the chain between 4 and 6, and take off the diamonds from the position 1 to 5 (with values 3+2+1+5+4=15).
2. Cut before 5 or after 6, and take off the diamonds from the position 4 to 6 (with values 5+4+6=15).
3. Cut before 8, and take off the diamonds from the position 7 to 8 (with values 8+7=15).
Now given the chain of diamond values and the amount that a customer has to pay, you are supposed to list all the paying options for the customer.

If it is impossible to pay the exact amount, you must suggest solutions with minimum lost.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 numbers: N (<=105), the total number of diamonds on the chain, and M (<=108), the amount that the customer has to pay. Then the next line contains N positive numbers D1 ... DN (Di<=103 for all i=1, ..., N) which are the values of the diamonds. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print "i-j" in a line for each pair of i <= j such that Di + ... + Dj = M. Note that if there are more than one solution, all the solutions must be printed in increasing order of i.

If there is no solution, output "i-j" for pairs of i <= j such that Di + ... + Dj > M with (Di + ... + Dj - M) minimized. Again all the solutions must be printed in increasing order of i.

It is guaranteed that the total value of diamonds is sufficient to pay the given amount.

Sample Input 1:
16 15
3 2 1 5 4 6 8 7 16 10 15 11 9 12 14 13
Sample Output 1:
1-5
4-6
7-8
11-11
Sample Input 2:
5 13
2 4 5 7 9
Sample Output 2:
2-4
4-5
*/
*
#include <cstdio>

using namespace std;

const int maxn = 100010;
const int INF = 0xfffffff;

int sum[maxn];
int n, S, nearS = 100000010;

int upper_bound(int L, int R, int x) {
    int left = L, right = R, mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (sum[mid] > x) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {

    sum[0] = 0;
    scanf("%d%d", &n, &S);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &sum[i]);
        sum[i] += sum[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
        int j=upper_bound(i,n+1,sum[i-1]+S);
        if(sum[j-1]-sum[i-1]==S){
            nearS=S;
            break;
        } else if(j<=n&&sum[j]-sum[i-1]<nearS){
            nearS=sum[j]-sum[i-1];
        }
    }
    for (int i = 1; i <=n; ++i) {
        int j=upper_bound(i,n+1,sum[i-1]+nearS);
        if(sum[j-1]-sum[i-1]==nearS){
            printf("%d-%d\n", i,j-1);
        }
    }

    return 0;
}
