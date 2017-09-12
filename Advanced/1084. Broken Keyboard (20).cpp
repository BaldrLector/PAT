/*1084. Broken Keyboard (20)
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
On a broken keyboard, some of the keys are worn out. So when you type some sentences, the characters corresponding to those keys will not appear on screen.

Now given a string that you are supposed to type, and the string that you actually type out, please list those keys which are for sure worn out.

Input Specification:

Each input file contains one test case. For each case, the 1st line contains the original string, and the 2nd line contains the typed-out string. Each string contains no more than 80 characters which are either English letters [A-Z] (case insensitive), digital numbers [0-9], or "_" (representing the space). It is guaranteed that both strings are non-empty.

Output Specification:

For each test case, print in one line the keys that are worn out, in the order of being detected. The English letters must be capitalized. Each worn out key must be printed once only. It is guaranteed that there is at least one worn out key.

Sample Input:
7_This_is_a_test
_hs_s_a_es
Sample Output:
7TI*/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 100020;
const int INF = 1000000000;

bool HashTable[256]={false};


int main() {
    // freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    int i=0,j=0;
    while(i<s1.length()&&j<s2.length()){
        if(s1[i]!=s2[j]){
            char c=s1[i];
            if(c>='a'&&c<='z')  c=c-'a'+'A';
            if(HashTable[c]== false){
                HashTable[c]=true;
                printf("%c", c);
            }
            i++;
        } else{
            i++;
            j++;
        }
    }

    return 0;
}

