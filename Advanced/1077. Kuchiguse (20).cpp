/*1077. Kuchiguse (20)
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
The Japanese language is notorious for its sentence ending particles. Personal preference of such particles can be considered as a reflection of the speaker's personality. Such a preference is called "Kuchiguse" and is often exaggerated artistically in Anime and Manga. For example, the artificial sentence ending particle "nyan~" is often used as a stereotype for characters with a cat-like personality:

Itai nyan~ (It hurts, nyan~)
Ninjin wa iyada nyan~ (I hate carrots, nyan~)
Now given a few lines spoken by the same character, can you find her Kuchiguse?

Input Specification:

Each input file contains one test case. For each case, the first line is an integer N (2<=N<=100). Following are N file lines of 0~256 (inclusive) characters in length, each representing a character's spoken line. The spoken lines are case sensitive.

Output Specification:

For each test case, print in one line the kuchiguse of the character, i.e., the longest common suffix of all N lines. If there is no such suffix, write "nai".

Sample Input 1:
3
Itai nyan~
Ninjin wa iyadanyan~
uhhh nyan~
Sample Output 1:
nyan~
Sample Input 2:
3
Itai!
Ninjinnwaiyada T_T
T_T
Sample Output 2:
nai*/
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 10020;
const int INF = 1000000000;

char s[100][256];

int main() {
    // freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    int n, ans = 0;
    scanf("%d", &n);
    getchar();
    int minL=256;
    for (int i = 0; i < n; ++i) {
        gets(s[i]);
        int len = strlen(s[i]);
        if (len < minL) minL = len;
        for (int j = 0; j < len / 2; ++j) {
            char temp = s[i][j];
            s[i][j] = s[i][len - j - 1];
            s[i][len - j - 1] = temp;
        }
    }
    for (int i = 0; i < minL; ++i) {
        char c = s[0][i];
        bool same = true;
        for (int j = 0; j < n; ++j) {
            if (c != s[j][i]) {
                same = false;
                break;
            }
        }
        if (same) ans++;
        else break;
    }
    if(ans){
        for(int i=ans-1;i>=0;i--){
            printf("%c", s[0][i]);
        }
    } else{
        printf("nai");
    }

    return 0;
}


