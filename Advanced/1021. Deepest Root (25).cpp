// 有问题，结果9分
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
typedef long long LL;

vector<int> G[maxn];
int n,maxDepth=0;
vector<int> root;
bool vis[maxn]={false};

int BFS(int s){
    queue<int> q;
    q.push(s);
    int depth=0;
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        bool flag=false;
        for(int i=0;i<G[temp].size();i++){
            if(vis[G[temp][i]]==false){
                vis[G[temp][i]]=true;
                flag=true;
                q.push(G[temp][i]);
            }
        }
        if(flag)
            depth++;
    }
    return depth;
}

void DFS(int s){
    if(G[s].size()==0)  return;
    for(int i=0;i<G[s].size();i++){
        if(vis[G[s][i]]==false){
            vis[G[s][i]]=true;
            DFS(G[s][i]);
        }
    }
}

int main() {
    freopen("data.in", "r", stdin);
    scanf("%d", &n);
    for(int i=0;i<n-1;i++){
        int u,v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int block=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==false){
            DFS(i);
            block++;
        }
    }
    if(block>1){
        printf("Error: %d components", block);
        return 0;
    }
    for(int i=1;i<=n;i++){
        fill(vis,vis+maxn,false);
        int depth=BFS(i);
        if(depth>maxDepth){
            maxDepth=depth;
            root.clear();
            root.push_back(i);
        }else if(depth==maxDepth){
            root.push_back(i);
        }
    }
    sort(root.begin(),root.end());
    for(int i=0;i<root.size();i++){
        printf("%d\n", root[i]);
    }
    return 0;
}
