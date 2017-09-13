/*1096. Consecutive Factors (20)
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
Among all the factors of a positive integer N, there may exist several consecutive numbers. For example, 630 can be factored as 3*5*6*7, where 5, 6, and 7 are the three consecutive numbers. Now given any positive N, you are supposed to find the maximum number of consecutive factors, and list the smallest sequence of the consecutive factors.

Input Specification:

Each input file contains one test case, which gives the integer N (1<N<231).

Output Specification:

For each test case, print in the first line the maximum number of consecutive factors. Then in the second line, print the smallest sequence of the consecutive factors in the format "factor[1]*factor[2]*...*factor[k]", where the factors are listed in increasing order, and 1 is NOT included.

Sample Input:
630
Sample Output:
3
5*6*7*/

#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;



int main() {
    // freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    long long n;
    scanf("%lld", &n);
    long long sqr=(long long)sqrt(1.0*n),ansI=0,ansLen=0;
    for(long long i=2;i<=sqr;i++){
        long long temp=1,j=i;
        while (1){
            temp*=j;
            if(n%temp!=0) break;
            if(j-i+1>ansLen){
                ansI=i;
                ansLen=j-i+1;
            }
            j++;
        }
    }
    if(ansLen==0){
        printf("1\n%lld", n);
    } else{
        printf("%lld\n", ansLen);
        for(long long i=0;i<ansLen;i++){
            printf("%lld", ansI+i);
            if(i<ansLen-1){
                printf("*");
            }
        }
    }

    return 0;
}

