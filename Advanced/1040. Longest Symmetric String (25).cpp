/*1040. Longest Symmetric String (25)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Given a string, you are supposed to output the length of the longest symmetric sub-string. For example, given "Is PAT&TAP symmetric?", the longest symmetric sub-string is "s PAT&TAP s", hence you must output 11.

Input Specification:

Each input file contains one test case which gives a non-empty string of length no more than 1000.

Output Specification:

For each test case, simply print the maximum length in a line.

Sample Input:
Is PAT&TAP symmetric?
Sample Output:
11
*/
*
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 1010;
const int INF = 0xfffffff;

char s[maxn];
int dp[maxn][maxn];

int main() {
    freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);
    memset(dp,0, sizeof(dp));
    gets(s);
    int len=strlen(s),ans=1;
    for (int i = 0; i < len; ++i) {
        dp[i][i]=1;
        if(i<len-1){
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                ans=2;
            }
        }
    }
    for (int L = 3; L <=len ; ++L) {
        for (int i = 0;i+L-1<len; ++i) {
            int j=i+L-1;
            if(s[i]==s[j]&&dp[i+1][j-1]==1){
                dp[i][j]=1;
                ans=L;
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}
