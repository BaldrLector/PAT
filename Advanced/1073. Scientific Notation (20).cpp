/*1073. Scientific Notation (20)
时间限制
100 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
HOU, Qiming
Scientific notation is the way that scientists easily handle very large numbers or very small numbers. The notation matches the regular expression [+-][1-9]"."[0-9]+E[+-][0-9]+ which means that the integer portion has exactly one digit, there is at least one digit in the fractional portion, and the number and its exponent's signs are always provided even when they are positive.

Now given a real number A in scientific notation, you are supposed to print A in the conventional notation while keeping all the significant figures.

Input Specification:

Each input file contains one test case. For each case, there is one line containing the real number A in scientific notation. The number is no more than 9999 bytes in length and the exponent's absolute value is no more than 9999.

Output Specification:

For each test case, print in one line the input number A in the conventional notation, with all the significant figures kept, including trailing zeros,

Sample Input 1:
+1.23400E-03
Sample Output 1:
0.00123400
Sample Input 2:
-1.2E+10
Sample Output 2:
-12000000000*/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 1020;
const int INF = 1000000000;



int main() {
    // freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    string s;
    cin>>s;
    if(s=="0"){
        printf("0");
        return 0;
    }
    int pos;
    for (int i = 0; i < s.length(); ++i) {
        if(s[i]=='E'){
            pos=i;
            break;
        }
    }
    int e=0;
    if(s[0]=='-')   printf("-");
    for(int i=pos+2;i<s.length();i++){
        e=e*10+s[i]-'0';
    }
    if(s[pos+1]=='-'){
        printf("0.");
        for (int i = 1; i < e; ++i) {
            printf("0");
        }
        for (int i = 1; i < pos; ++i) {
            if(s[i]=='.') continue;
            printf("%c", s[i]);
        }
    } else{
        printf("%c", s[1]);
        for (int i = 3; i <pos ; ++i) {
            printf("%c", s[i]);
            if(i==e+2&&pos-3!=e){
                printf(".");
            }
        }
        for (int i = 0; i < e - pos + 3; ++i) {
            printf("0");
        }
    }

    return 0;
}

