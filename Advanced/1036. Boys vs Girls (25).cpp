/*1036. Boys vs Girls (25)
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
This time you are asked to tell the difference between the lowest grade of all the male students and the highest grade of all the female students.

Input Specification:

Each input file contains one test case. Each case contains a positive integer N, followed by N lines of student information. Each line contains a student's name, gender, ID and grade, separated by a space, where name and ID are strings of no more than 10 characters with no space, gender is either F (female) or M (male), and grade is an integer between 0 and 100. It is guaranteed that all the grades are distinct.

Output Specification:

For each test case, output in 3 lines. The first line gives the name and ID of the female student with the highest grade, and the second line gives that of the male student with the lowest grade. The third line gives the difference gradeF-gradeM. If one such kind of student is missing, output "Absent" in the corresponding line, and output "NA" in the third line instead.

Sample Input 1:

3
Joe M Math990112 89
Mike M CS991301 100
Mary F EE990830 95
Sample Output 1:
Mary EE990830
Joe Math990112
6
Sample Input 2:
1
Jean M AA980920 60
Sample Output 2:
Absent
Jean AA980920
NA*/

#include <cstdio>

using namespace std;

const int maxn = 102510;
const int INF = 0xfffffff;

struct stu {
    char name[15], id[15];
    int score;
    char sex;
} s[maxn];

int main() {
    freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    int n, nf = 0, nm = 0, fHigh = 0, mLow = 100, idxm, idxf;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s %c %s %d", s[i].name, &s[i].sex, s[i].id, &s[i].score);
        if (s[i].sex == 'F') {
            nf++;
            if (fHigh <= s[i].score) {
                fHigh = s[i].score;
                idxf = i;
            }
        } else {
            nm++;
            if (mLow >= s[i].score) {
                mLow = s[i].score;
                idxm = i;
            }
        }
    }

    int flag;
    if (nf == 0 || nm == 0) flag = false;
    else flag = true;

    if (nf == 0) {
        printf("Absent\n");
    } else {
        printf("%s %s\n", s[idxf].name, s[idxf].id);
    }
    if (nm == 0) printf("Absent\n");
    else printf("%s %s\n", s[idxm].name, s[idxm].id);

    if(flag)    printf("%d", fHigh-mLow);
    else printf("NA");

    return 0;
}
