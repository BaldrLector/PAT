/*1034. Head of a Gang (30)
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
One way that the police finds the head of a gang is to check people's phone calls. If there is a phone call between A and B, we say that A and B is related. The weight of a relation is defined to be the total time length of all the phone calls made between the two persons. A "Gang" is a cluster of more than 2 persons who are related to each other with total relation weight being greater than a given threshold K. In each gang, the one with maximum total weight is the head. Now given a list of phone calls, you are supposed to find the gangs and the heads.

Input Specification:

Each input file contains one test case. For each case, the first line contains two positive numbers N and K (both less than or equal to 1000), the number of phone calls and the weight threthold, respectively. Then N lines follow, each in the following format:

Name1 Name2 Time

where Name1 and Name2 are the names of people at the two ends of the call, and Time is the length of the call. A name is a string of three capital letters chosen from A-Z. A time length is a positive integer which is no more than 1000 minutes.

Output Specification:

For each test case, first print in a line the total number of gangs. Then for each gang, print in a line the name of the head and the total number of the members. It is guaranteed that the head is unique for each gang. The output must be sorted according to the alphabetical order of the names of the heads.

Sample Input 1:
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 1:
2
AAA 3
GGG 3
Sample Input 2:
8 70
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 2:
0*/

#include <cstdio>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

const int maxn = 2510;
const int INF = 0xfffffff;

map<int, string> intTostring;
map<string, int> stringToint;
map<string, int> Gang;
int G[maxn][maxn] = {0};
int weight[maxn] = {0};
int n, k, numPersion = 0;
bool vis[maxn] = {false};

void DFS(int nowVisit, int &head, int &numMember, int &totalValue) {
    numMember++;
    vis[nowVisit] = true;
    if (weight[nowVisit] > weight[head]) {
        head = nowVisit;
    }
    for (int i = 0; i < numPersion; ++i) {
        if (G[nowVisit][i] > 0) {
            totalValue += G[nowVisit][i];
            G[nowVisit][i] = G[i][nowVisit] = 0;
            if (vis[i] == false) {
                DFS(i, head, numMember, totalValue);
            }
        }
    }
}

void DFSTrave() {
    for (int i = 0; i < numPersion; ++i) {
        if (vis[i] == false) {
            int head = i, numMember = 0, totalValue = 0;
            DFS(i, head, numMember, totalValue);
            if (numMember > 2 && totalValue > k) {
                Gang[intTostring[head]] = numMember;
            }
        }
    }
}

int getId(string str) {
    if (stringToint.find(str) != stringToint.end()) {
        return stringToint[str];
    } else {
        stringToint[str] = numPersion;
        intTostring[numPersion] = str;
        return numPersion++;
    }
}

int main() {

    int w;
    string str1, str2;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> str1 >> str2 >> w;
        int id1 = getId(str1);
        int id2 = getId(str2);
        weight[id1] += w;
        weight[id2] += w;
        G[id1][id2] += w;
        G[id2][id1] += w;
    }
    DFSTrave();
    cout << Gang.size() << endl;
    map<string, int>::iterator it;
    for (it = Gang.begin(); it != Gang.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}

