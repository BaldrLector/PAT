/*1061. Dating (20)
时间限制
150 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Sherlock Holmes received a note with some strange strings: "Let's date! 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm". It took him only a minute to figure out that those strange strings are actually referring to the coded time "Thursday 14:04" -- since the first common capital English letter (case sensitive) shared by the first two strings is the 4th capital letter 'D', representing the 4th day in a week; the second common character is the 5th capital letter 'E', representing the 14th hour (hence the hours from 0 to 23 in a day are represented by the numbers from 0 to 9 and the capital letters from A to N, respectively); and the English letter shared by the last two strings is 's' at the 4th position, representing the 4th minute. Now given two pairs of strings, you are supposed to help Sherlock decode the dating time.

Input Specification:

Each input file contains one test case. Each case gives 4 non-empty strings of no more than 60 characters without white space in 4 lines.

Output Specification:

For each test case, print the decoded time in one line, in the format "DAY HH:MM", where "DAY" is a 3-character abbreviation for the days in a week -- that is, "MON" for Monday, "TUE" for Tuesday, "WED" for Wednesday, "THU" for Thursday, "FRI" for Friday, "SAT" for Saturday, and "SUN" for Sunday. It is guaranteed that the result is unique for each case.

Sample Input:
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm
Sample Output:
THU 14:04*/

#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

const int maxn = 100010;
const int INF = 0xfffffff;

char week[7][10] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main() {
    // freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    int i = 0;
    for (; i < s1.length() && i < s2.length(); ++i) {
        if (s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G') {
            printf("%s ", week[s1[i] - 'A']);
            break;
        }
    }
    for (i++; i < s1.length() && i < s2.length(); ++i) {
        if (s1[i] == s2[i]) {
            if (s1[i] >= 'A' && s1[i] <= 'N') {
                printf("%02d:", s1[i] - 'A' + 10);
                break;
            } else if (s1[i] >= '0' && s1[i] <= '9') {
                printf("%02d:", s1[i] - '0');
                break;
            }
        }
    }
    for (int i = 0; i < s3.length() && i < s4.length(); ++i) {
        if (s3[i] == s4[i]) {
            if ((s3[i]>='A'&&s3[i]<='Z')||(s3[i]>='a'&&s3[i]<='z')) {
                printf("%02d", i);
                break;
            }
        }
    }

    return 0;
}
