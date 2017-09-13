/*1093. Count PAT's (25)
时间限制
120 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CAO, Peng
The string APPAPT contains two PAT's as substrings. The first one is formed by the 2nd, the 4th, and the 6th characters, and the second one is formed by the 3rd, the 4th, and the 6th characters.

Now given any string, you are supposed to tell the number of PAT's contained in the string.

Input Specification:

Each input file contains one test case. For each case, there is only one line giving a string of no more than 105 characters containing only P, A, or T.

Output Specification:

For each test case, print in one line the number of PAT's contained in the string. Since the result may be a huge number, you only have to output the result moded by 1000000007.

Sample Input:
APPAPT
Sample Output:
2
*/
*
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 100100;
const int INF = 1000000000;
const int MOD=1000000007;

int p[maxn]={0};
int t=0;
long long ans=0;

int main() {
    // freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    string s;
    cin>>s;
    for (int i = 0; i < s.length(); ++i) {
        if(s[i]=='P'){
            if(i==0)    p[0]=1;
            else p[i]=p[i-1]+1;
        } else{
            if(i==0)    p[0]=0;
            else  p[i]=p[i-1];
        }
    }
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]=='T')   t++;
        else if(s[i]=='A')  ans=(ans+p[i]*t)%MOD;
    }
    printf("%d", ans);

    return 0;
}

