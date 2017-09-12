/*1087. All Roads Lead to Rome (30)
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
Indeed there are many different tourist routes from our city to Rome. You are supposed to find your clients the route with the least cost while gaining the most happiness.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers N (2<=N<=200), the number of cities, and K, the total number of routes between pairs of cities; followed by the name of the starting city. The next N-1 lines each gives the name of a city and an integer that represents the happiness one can gain from that city, except the starting city. Then K lines follow, each describes a route between two cities in the format "City1 City2 Cost". Here the name of a city is a string of 3 capital English letters, and the destination is always ROM which represents Rome.

Output Specification:

For each test case, we are supposed to find the route with the least cost. If such a route is not unique, the one with the maximum happiness will be recommended. If such a route is still not unique, then we output the one with the maximum average happiness -- it is guaranteed by the judge that such a solution exists and is unique.

Hence in the first line of output, you must print 4 numbers: the number of different routes with the least cost, the cost, the happiness, and the average happiness (take the integer part only) of the recommended route. Then in the next line, you are supposed to print the route in the format "City1->City2->...->ROM".

Sample Input:
6 7 HZH
ROM 100
PKN 40
GDN 55
PRS 95
BLN 80
ROM GDN 1
BLN ROM 1
HZH PKN 1
PRS ROM 2
BLN HZH 2
PKN GDN 1
HZH PRS 1
Sample Output:
3 3 195 97
HZH->PRS->ROM*/

#include <cstdio>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

const int maxn = 210;
const int INF = 1000000000;

int G[maxn][maxn], w[maxn], d[maxn], weight[maxn];
int n, k, st, ed;
int num[maxn],pt[maxn],pre[maxn];

int cityNum = 0;
map<string, int> strToint;
map<int, string> intTostr;

int getCityID(string s) {
    if (strToint.find(s) != strToint.end()) {
        return strToint[s];
    } else {
        strToint[s] = cityNum;
        intTostr[cityNum] = s;
        return cityNum++;
    }
}

bool vis[maxn]={false};

void Dijkstra(int s) {
    fill(d, d + maxn, INF);
    fill(w, w + maxn, 0);
    fill(num,num+maxn,0);
    num[s]=1;
    w[s]=0;
    d[s]=0;
    for (int i = 0; i < cityNum; ++i) {
        int u=-1,MIN=INF;
        for (int j = 0; j < cityNum; ++j) {
            if(vis[j]==false&&d[j]<MIN) {
                u=j;
                MIN=d[j];
            }
        }
        if(u==-1) return;
        vis[u]=true;
        for(int v=0;v<cityNum;v++){
            if(vis[v]==false){
                if(d[v]>d[u]+G[u][v]){
                    d[v]=d[u]+G[u][v];
                    w[v]=w[u]+weight[v];
                    num[v]=num[u];
                    pre[v]=u;
                    pt[v]=pt[u]+1;
                } else if(d[v]==d[u]+G[u][v]){
                    num[v]+=num[u];
                    if(w[u]+weight[v]>w[v]){
                        w[v]=weight[v]+w[u];
                        pre[v]=u;
                        pt[v]=pt[u]+1;
                    } else if(w[u+weight[v]==w[v]]){
                        double uAvg=1.0*(w[u]+weight[v])/(pt[u]+1);
                        double vAvg=1.0*w[v]/pt[v];
                        if(uAvg>vAvg){
                            pt[v]=pt[u]+1;
                            pre[v]=u;
                        }
                    }
                }
            }
        }
    }
}

void printPath(int v){
    if(v==0){
        cout<<intTostr[v];
        return;
    }
    printPath(pre[v]);
    cout<<"->"<<intTostr[v];
}

int main() {
    // freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    fill(G[0], G[0] + maxn * maxn, INF);
    string s1, s2;
    int dis, h;
    scanf("%d%d", &n, &k);
    cin >> s1;
    st = getCityID(s1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> s1 >> h;
        int u = getCityID(s1);
        weight[u] = h;
    }
    for (int i = 0; i < k; ++i) {
        cin >> s1 >> s2 >> dis;
        int u = getCityID(s1);
        int v = getCityID(s2);
        G[u][v] = G[v][u] = dis;
    }
    Dijkstra(0);
    int rom=getCityID("ROM");
    printf("%d %d %d %d\n", num[rom], d[rom], w[rom], w[rom]/pt[rom]);
    printPath(rom);


    return 0;
}

