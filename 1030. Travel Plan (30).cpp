/*1030. Travel Plan (30)
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
A traveler's map gives the distances between cities along the highways, together with the cost of each highway. Now you are supposed to write a program to help a traveler to decide the shortest path between his/her starting city and the destination. If such a shortest path is not unique, you are supposed to output the one with the minimum cost, which is guaranteed to be unique.

Input Specification:

Each input file contains one test case. Each case starts with a line containing 4 positive integers N, M, S, and D, where N (<=500) is the number of cities (and hence the cities are numbered from 0 to N-1); M is the number of highways; S and D are the starting and the destination cities, respectively. Then M lines follow, each provides the information of a highway, in the format:

City1 City2 Distance Cost

where the numbers are all integers no more than 500, and are separated by a space.

Output Specification:

For each test case, print in one line the cities along the shortest path from the starting point to the destination, followed by the total distance and the total cost of the path. The numbers must be separated by a space and there must be no extra space at the end of output.

Sample Input
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
Sample Output
0 2 3 3 40*/

#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn = 510;
const int INF = 0xfffffff;

int n, m, st, ed;
int d[maxn], c[maxn], pre[maxn], G[maxn][maxn];
int cost[maxn][maxn] = {0};
bool vis[maxn] = {false};

void Dijkstra(int s) {
    fill(d, d + maxn, INF);
    fill(c, c + maxn, 0);
    d[s] = 0;
    c[s]=0;
    for (int i = 0; i < n; ++i) {
        pre[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; ++j) {
            if (vis[j] == false && d[j] < MIN) {
                MIN = d[j];
                u = j;
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 0; v < n; ++v) {
            if (vis[v] == false && G[u][v] != INF) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    c[v] = c[u] + cost[u][v];
                    pre[v] = u;
                } else if (d[u] + G[u][v] == d[v]) {
                    if (c[u] + cost[u][v] < c[v]) {
                        c[v] = c[u] + cost[u][v];
                        pre[v] = u;
                    }
                }
            }
        }
    }
}

void DFS(int v){
    if(v==st){
        printf("%d ", v);
        return;
    }
    DFS(pre[v]);
    printf("%d ", v);
}

int main() {
    freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    int u,v;
    scanf("%d%d%d%d", &n, &m, &st, &ed);
    fill(G[0],G[0]+maxn*maxn,INF);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v);
        scanf("%d%d", &G[u][v], &cost[u][v]);
        G[v][u]=G[u][v];
        cost[v][u]=cost[u][v];
    }
    Dijkstra(st);
    DFS(ed);
    printf("%d %d\n", d[ed], c[ed]);

    return 0;
}
