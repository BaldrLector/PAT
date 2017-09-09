/*1058. A+B in Hogwarts (20)
时间限制
50 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
If you are a fan of Harry Potter, you would know the world of magic has its own currency system -- as Hagrid explained it to Harry, "Seventeen silver Sickles to a Galleon and twenty-nine Knuts to a Sickle, it's easy enough." Your job is to write a program to compute A+B where A and B are given in the standard form of "Galleon.Sickle.Knut" (Galleon is an integer in [0, 107], Sickle is an integer in [0, 17), and Knut is an integer in [0, 29)).

Input Specification:

Each input file contains one test case which occupies a line with A and B in the standard form, separated by one space.

Output Specification:

For each test case you should output the sum of A and B in one line, with the same format as the input.

Sample Input:
3.2.1 10.16.27
Sample Output:
14.1.28*/

#include <cstdio>

using namespace std;

const int maxn = 100010;
const int INF = 0xfffffff;

const int Sickle = 29, Galleon = 29 * 17;

int main() {
    // freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    int a[2][3];
    for (int i = 0; i < 2; ++i) {
        scanf("%d.%d.%d", &a[i][0], &a[i][1], &a[i][2]);
    }
    for (int i = 0; i < 3; ++i) {
        a[0][i]+=a[1][i];
    }
    a[0][1]+=a[0][2]/29;
    a[0][2]%=29;
    a[0][0]+=a[0][1]/17;
    a[0][1]%=17;
    printf("%d.%d.%d", a[0][0], a[0][1], a[0][2]);

    return 0;
}
