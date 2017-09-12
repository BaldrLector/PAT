/*1076. Forwards on Weibo (30)
时间限制
3000 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Weibo is known as the Chinese version of Twitter. One user on Weibo may have many followers, and may follow many other users as well. Hence a social network is formed with followers relations. When a user makes a post on Weibo, all his/her followers can view and forward his/her post, which can then be forwarded again by their followers. Now given a social network, you are supposed to calculate the maximum potential amount of forwards for any specific user, assuming that only L levels of indirect followers are counted.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers: N (<=1000), the number of users; and L (<=6), the number of levels of indirect followers that are counted. Hence it is assumed that all the users are numbered from 1 to N. Then N lines follow, each in the format:

M[i] user_list[i]

where M[i] (<=100) is the total number of people that user[i] follows; and user_list[i] is a list of the M[i] users that are followed by user[i]. It is guaranteed that no one can follow oneself. All the numbers are separated by a space.

Then finally a positive K is given, followed by K UserID's for query.

Output Specification:

For each UserID, you are supposed to print in one line the maximum potential amount of forwards this user can triger, assuming that everyone who can view the initial post will forward it once, and that only L levels of indirect followers are counted.

Sample Input:
7 3
3 2 3 4
0
2 5 6
2 3 1
2 3 4
1 4
1 5
2 2 6
Sample Output:
4
5*/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 10020;
const int INF = 1000000000;

struct Node{
    int id,layer;
};

vector<Node> Adj[maxn];
bool vis[maxn] = {false};

int BFS(int s,int l){
    int numForword=0;
    queue<Node> q;
    Node start;
    start.id=s;
    start.layer=0;
    q.push(start);
    vis[start.id]=true;
    while (!q.empty()){
        Node topNode=q.front();
        q.pop();
        int u=topNode.id;
        for (int i = 0; i < Adj[u].size(); ++i) {
            Node next=Adj[u][i];
            next.layer=topNode.layer+1;
            if(vis[next.id]==false&&next.layer<=l){
                q.push(next);
                vis[next.id]=true;
                numForword++;
            }
        }
    }
    return numForword;
}

int main() {
    // freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    int n,L,numFollow,idFollow;
    scanf("%d%d", &n, &L);
    for (int i = 1; i <= n; i++) {
        Node user;
        user.id=i;
        scanf("%d", &numFollow);
        for (int j = 0; j < numFollow; ++j) {
            scanf("%d", &idFollow);
            Adj[idFollow].push_back(user);
        }
    }
    int numQuery,s;
    scanf("%d", &numQuery);
    for (int i = 0; i < numQuery; ++i) {
        memset(vis,false, sizeof(vis));
        scanf("%d", &s);
        int numForward=BFS(s,L);
        printf("%d\n", numForward);
    }



    return 0;
}

