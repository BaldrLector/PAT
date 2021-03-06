/*1049. Counting Ones (30)
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
The task is simple: given any positive integer N, you are supposed to count the total number of 1's in the decimal form of the integers from 1 to N. For example, given N being 12, there are five 1's in 1, 10, 11, and 12.

Input Specification:

Each input file contains one test case which gives the positive N (<=230).

Output Specification:

For each test case, print the number of 1's in one line.

Sample Input:
12
Sample Output:
5*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100010;
const int INF = 0xfffffff;

int main() {

    int n,a=1,left,right,ans=0,now;
    scanf("%d", &n);
    while(n/a!=0){
        left=n/(a*10);
        now=n/a%10;
        right=n%a;
        if(now==0)  ans+=left*a;
        else if(now==1) ans+=left*a+right+1;
        else ans+=(left+1)*a;
        a*=10;
    }
    printf("%d\n", ans);

    return 0;
}
