/*1094. The Largest Generation (25)
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
A family hierarchy is usually presented by a pedigree tree where all the nodes on the same level belong to the same generation. Your task is to find the generation with the largest population.

Input Specification:

Each input file contains one test case. Each case starts with two positive integers N (<100) which is the total number of family members in the tree (and hence assume that all the members are numbered from 01 to N), and M (<N) which is the number of family members who have children. Then M lines follow, each contains the information of a family member in the following format:

ID K ID[1] ID[2] ... ID[K]

where ID is a two-digit number representing a family member, K (>0) is the number of his/her children, followed by a sequence of two-digit ID's of his/her children. For the sake of simplicity, let us fix the root ID to be 01. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the largest population number and the level of the corresponding generation. It is assumed that such a generation is unique, and the root level is defined to be 1.

Sample Input:
23 13
21 1 23
01 4 03 02 04 05
03 3 06 07 08
06 2 12 13
13 1 21
08 2 15 16
02 2 09 10
11 2 19 20
17 1 22
05 1 11
07 1 14
09 1 17
10 1 18
Sample Output:
9 4*/

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

const int maxn = 100100;
const int INF = 1000000000;
struct node{
    int level;
    vector<int> child;
}Node[maxn];

bool vis[maxn]={false};
int n,m;
int depth[maxn]={0};
int maxLevel=1;
void BFS(int s){
    Node[s].level=1;
    queue<node> q;
    q.push(Node[s]);
    while (!q.empty()){
        node top=q.front();
        q.pop();
        depth[top.level]++;
        if(depth[top.level]>depth[maxLevel]){
            maxLevel=top.level;
        }
        for (int i = 0; i < top.child.size(); ++i) {
            int u=top.child[i];
            Node[u].level=top.level+1;
            q.push(Node[u]);
        }
    }

}

int main() {
    // freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int id,k,child;
        scanf("%d%d", &id, &k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &child);
            Node[id].child.push_back(child);
        }
    }
    BFS(1);
    printf("%d %d",  depth[maxLevel], maxLevel);

    return 0;
}

