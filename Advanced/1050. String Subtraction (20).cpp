/*1050. String Subtraction (20)
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
Given two strings S1 and S2, S = S1 - S2 is defined to be the remaining string after taking all the characters in S2 from S1. Your task is simply to calculate S1 - S2 for any given strings. However, it might not be that simple to do it fast.

Input Specification:

Each input file contains one test case. Each case consists of two lines which gives S1 and S2, respectively. The string lengths of both strings are no more than 104. It is guaranteed that all the characters are visible ASCII codes and white space, and a new line character signals the end of a string.

Output Specification:

For each test case, print S1 - S2 in one line.

Sample Input:
They are students.
aeiou
Sample Output:
Thy r stdnts.*/

#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 10010;
const int INF = 0xfffffff;

bool HashTable[256]={false};

int main() {
    freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    char s1[maxn], s2[maxn];
    gets(s1);
    gets(s2);
    int len1 = strlen(s1), len2 = strlen(s2);
    for (int i = 0; i < len2; ++i) {
        HashTable[s2[i]]=true;
    }
    for (int i = 0; i < len1; ++i) {
        if(HashTable[s1[i]]==false)
            printf("%c", s1[i]);
    }

    return 0;
}
