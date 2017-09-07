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

//Right Answer
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 100100;

vector<int> node[maxn];
vector<int> MaxHeigthRoot;
int MaxHeigth = 0;
bool vis[maxn] = {false};


void BFS(int s) {
    for (int i = 0; i < node[s].size(); i++) {
        int u = node[s][i];
        if (vis[u] == false) {
            vis[u] = true;
            BFS(u);
        }
    }
}

int getHeight(int root) {
    int height = 1;
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        bool flag = false;
        int temp = q.front();
        q.pop();
        for (int i = 0; i < node[temp].size(); i++) {
            int u = node[temp][i];
            if (vis[u] == false) {
                if (flag == false) {
                    flag = true;
                    height++;
                }
                vis[u]= true;
                q.push(u);
            }
        }
    }
    return height;
}

vector<int> temp, Ans;
int maxH=0;
void DFS(int u,int Height,int pre){
    if(Height>maxH){
        temp.clear();
        temp.push_back(u);
        maxH=Height;
    } else if(Height==maxH){
        temp.push_back(u);
    }

    for(int i=0;i<node[u].size();i++){
        if(node[u][i]==pre) continue;
        DFS(node[u][i],Height+1,u);
    }
}

int main() {
    freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d%d", &v, &u);
        node[v].push_back(u);
        node[u].push_back(v);
    }
    int block = 0;
    for (int i = 1; i <= n; ++i) {
        if (vis[i] == false) {
            BFS(i);
            block++;
        }
    }
    if (block > 1) {
        printf("Error: %d components\n", block);
        return 0;
    }
/*    for (int i = 1; i <= n; ++i) {
        fill(vis,vis+maxn,false);
        int tempHeight=getHeight(i);
        if(tempHeight>MaxHeigth){
            MaxHeigth=tempHeight;
            MaxHeigthRoot.clear();
            MaxHeigthRoot.push_back(i);
        } else if(tempHeight==MaxHeigth){
            MaxHeigthRoot.push_back(i);
        }
    }
    sort(MaxHeigthRoot.begin(),MaxHeigthRoot.end());

    for (int i = 0; i < MaxHeigthRoot.size(); ++i) {
        printf("%d\n", MaxHeigthRoot[i]);
    }*/

    DFS(1,1,-1);
    Ans=temp;
    DFS(Ans[0],1,-1);
    for(int i=0;i<temp.size();i++){
        Ans.push_back(temp[i]);
    }
    sort(Ans.begin(),Ans.end());
    printf("%d\n", Ans[0]);
    for(int i=1;i<Ans.size();i++){
        if(Ans[i]!=Ans[i-1]){
            printf("%d\n", Ans[i]);
        }
    }

    return 0;
}

