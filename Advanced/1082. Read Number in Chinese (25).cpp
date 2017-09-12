/*1082. Read Number in Chinese (25)
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
Given an integer with no more than 9 digits, you are supposed to read it in the traditional Chinese way. Output "Fu" first if it is negative. For example, -123456789 is read as "Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu". Note: zero ("ling") must be handled correctly according to the Chinese tradition. For example, 100800 is "yi Shi Wan ling ba Bai".

Input Specification:

Each input file contains one test case, which gives an integer with no more than 9 digits.

Output Specification:

For each test case, print in a line the Chinese way of reading the number. The characters are separated by a space and there must be no extra space at the end of the line.

Sample Input 1:
-123456789
Sample Output 1:
Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu
Sample Input 2:
100800
Sample Output 2:
yi Shi Wan ling ba Bai*/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 100020;
const int INF = 1000000000;

char num[10][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
char wei[5][5]={"Shi","Bai","Qian","Wan","Yi"};


int main() {
    // freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    char str[15];
    gets(str);
    int len=strlen(str);
    int left=0,right=len-1;
    if(str[0]=='-'){
        printf("Fu");
        left++;
    }
    while(left+4<=right){
        right-=4;
    }
    while (left<len){
        bool flag=false;
        bool isPrint=false;
        while (left<=right){
            if(left>0&&str[left]=='0'){
                flag=true;
            } else{
                if(flag==true){
                    printf(" ling");
                    flag=false;
                }
                if(left>0)  printf(" ");
                printf("%s", num[str[left]-'0']);
                isPrint=true;
                if(left!=right){
                    printf(" %s", wei[right-left-1]);
                }
            }
            left++;
        }
        if(isPrint==true&&right!=len-1){
            printf(" %s", wei[(len-1-right)/4+2]);
        }
        right+=4;
    }

    return 0;
}

