/*1072. Gas Station (30)
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
A gas station has to be built at such a location that the minimum distance between the station and any of the residential housing is as far away as possible. However it must guarantee that all the houses are in its service range.

Now given the map of the city and several candidate locations for the gas station, you are supposed to give the best recommendation. If there are more than one solution, output the one with the smallest average distance to all the houses. If such a solution is still not unique, output the one with the smallest index number.

Input Specification:

Each input file contains one test case. For each case, the first line contains 4 positive integers: N (<= 103), the total number of houses; M (<= 10), the total number of the candidate locations for the gas stations; K (<= 104), the number of roads connecting the houses and the gas stations; and DS, the maximum service range of the gas station. It is hence assumed that all the houses are numbered from 1 to N, and all the candidate locations are numbered from G1 to GM.

Then K lines follow, each describes a road in the format
P1 P2 Dist
where P1 and P2 are the two ends of a road which can be either house numbers or gas station numbers, and Dist is the integer length of the road.

Output Specification:

For each test case, print in the first line the index number of the best location. In the next line, print the minimum and the average distances between the solution and all the houses. The numbers in a line must be separated by a space and be accurate up to 1 decimal place. If the solution does not exist, simply output “No Solution”.

Sample Input 1:
4 3 11 5
1 2 2
1 4 2
1 G1 4
1 G2 3
2 3 2
2 G2 1
3 4 2
3 G3 2
4 G1 3
G2 G1 1
G3 G2 2
Sample Output 1:
G1
2.0 3.3
Sample Input 2:
2 1 2 10
1 G1 9
2 G1 20
Sample Output 2:
No Solution
*/
*

//particial right

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 1020;
const int INF = 1000000000;

bool vis[maxn] = {false};
int d[maxn];
int n, m, k, ds, G[maxn][maxn];

void Dijkstra(int s) {
    fill(d, d + maxn, INF);
    d[s] = 0;
    for (int i = 0; i < n + m; ++i) {
        int u = -1, MIN = INF;
        for (int j = 1; j <= n + m; ++j) {
            if (vis[j] == false && d[j] < MIN) {
                MIN = d[j];
                u = j;
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 1; v <= n + m; ++v) {
            if (vis[v] == false && G[u][v] != INF) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                }
            }
        }
    }
}

int getID(char str[]) {
    int i = 0, len = strlen(str), ID = 0;
    while (i < len) {
        if (str[i] != 'G') {
            ID = ID * 10 + (str[i] - '0');
        }
        i++;
    }
    if (str[0] == 'G') return n + ID;
    else return ID;
}

int main() {
    freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    scanf("%d%d%d%d", &n, &m, &k, &ds);
    int u, v, w;
    char city1[5], city2[5];
    fill(G[0], G[0] + maxn * maxn, INF);
    for (int i = 0; i < k; ++i) {
        scanf("%s %s %d", city1, city2, &w);
        u = getID(city1);
        v = getID(city2);
        G[u][v] = G[v][u] = w;
    }
    double ansDis = -1, ansAvg = INF;
    int ansID = -1;
    for (int i = n + 1; i <= n + m; i++) {
        double minDis = INF, avg = 0;
        Dijkstra(i);
        for (int j = 1; j <= n; ++j) {
            if (d[j] > ds) {
                minDis = -1;
                break;
            }
            if (d[j] < minDis) minDis = d[j];
            avg += 1.0 * d[j] / n;
        }
        if (minDis == -1) continue;
        if (minDis > ansDis) {
            ansID = i;
            ansDis = minDis;
            ansAvg = avg;
        } else if (minDis == ansDis && avg < ansAvg) {
            ansID = i;
            ansAvg = avg;
        }
    }
    if (ansID == -1) printf("No Solution\n");
    else {
        printf("G%d\n", ansID - n);
        printf("%.1f %.1f\n", ansDis, ansAvg);
    }

    return 0;
}

