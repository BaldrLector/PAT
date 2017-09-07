#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<cstdlib>
#include<queue>
using namespace std;
const int maxn=10100;
const int INF=1000000000;
int n,m,k;
vector<int> Adj[maxn];
bool vis[maxn]={false};
int deletePoint;

void DFS(int s){
    if(s==deletePoint)  return;

    for(int i=0;i<Adj[s].size();i++){
        int u=Adj[s][i];
        if(vis[u]==false){
            vis[u]=true;
            DFS(u);
        }
    }
}

int main() {
    freopen("data.in", "r", stdin);

    scanf("%d%d%d", &n, &m, &k);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d", &u, &v);
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    for(int i=0;i<k;i++){
        fill(vis,vis+maxn,false);
        int ans=0;
        scanf("%d", &deletePoint);
        for(int j=1;j<=n;j++){
            if(j!=deletePoint&&vis[j]==false){
                DFS(j);
                ans++;
            }
        }
        printf("%d\n", ans-1);
    }

    return 0;
}
