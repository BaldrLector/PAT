/*1055. The World's Richest (25)
时间限制
400 ms
内存限制
128000 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Forbes magazine publishes every year its list of billionaires based on the annual ranking of the world's wealthiest people. Now you are supposed to simulate this job, but concentrate only on the people in a certain range of ages. That is, given the net worths of N people, you must find the M richest people in a given range of their ages.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers: N (<=105) - the total number of people, and K (<=103) - the number of queries. Then N lines follow, each contains the name (string of no more than 8 characters without space), age (integer in (0, 200]), and the net worth (integer in [-106, 106]) of a person. Finally there are K lines of queries, each contains three positive integers: M (<= 100) - the maximum number of outputs, and [Amin, Amax] which are the range of ages. All the numbers in a line are separated by a space.

Output Specification:

For each query, first print in a line "Case #X:" where X is the query number starting from 1. Then output the M richest people with their ages in the range [Amin, Amax]. Each person's information occupies a line, in the format

Name Age Net_Worth
The outputs must be in non-increasing order of the net worths. In case there are equal worths, it must be in non-decreasing order of the ages. If both worths and ages are the same, then the output must be in non-decreasing alphabetical order of the names. It is guaranteed that there is no two persons share all the same of the three pieces of information. In case no one is found, output "None".
Sample Input:
12 4
Zoe_Bill 35 2333
Bob_Volk 24 5888
Anny_Cin 95 999999
Williams 30 -22
Cindy 76 76000
Alice 18 88888
Joe_Mike 32 3222
Michael 5 300000
Rosemary 40 5888
Dobby 24 5888
Billy 24 5888
Nobody 5 0
4 15 45
4 30 35
4 5 95
1 45 50
Sample Output:
Case #1:
Alice 18 88888
Billy 24 5888
Bob_Volk 24 5888
Dobby 24 5888
Case #2:
Joe_Mike 32 3222
Zoe_Bill 35 2333
Williams 30 -22
Case #3:
Anny_Cin 95 999999
Michael 5 300000
Alice 18 88888
Cindy 76 76000
Case #4:
None*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 500010;
const int INF = 0xfffffff;

struct rec {
    char name[15];
    int age, welth;
} allRec[maxn], validRec[maxn];

bool cmp(rec a, rec b) {
    if (a.welth != b.welth) return a.welth > b.welth;
    else if (a.age != b.age) return a.age < b.age;
    else return strcmp(a.name, b.name) < 0;
}

int main() {
    // freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%s%d%d", allRec[i].name, &allRec[i].age, &allRec[i].welth);
    }
    sort(allRec, allRec + n, cmp);
    for (int i = 1; i <= k; ++i) {
        printf("Case #%d:\n", i);
        bool flag = false;
        int num, minAge, maxAge;
        scanf("%d%d%d", &num, &minAge, &maxAge);
        int count=0;
        for (int l = 0; l < n; ++l) {
            if(count==num)
                break;
            if (allRec[l].age >= minAge && allRec[l].age <= maxAge) {
                flag = true;
                printf("%s %d %d\n", allRec[l].name, allRec[l].age, allRec[l].welth);
                count++;
            }
        }

        if (flag == false) {
            printf("None\n");
        }
    }

    return 0;
}
