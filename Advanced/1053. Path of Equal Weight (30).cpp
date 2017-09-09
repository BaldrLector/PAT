/*1053. Path of Equal Weight (30)
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
Given a non-empty tree with root R, and with weight Wi assigned to each tree node Ti. The weight of a path from R to L is defined to be the sum of the weights of all the nodes along the path from R to any leaf node L.

Now given any weighted tree, you are supposed to find all the paths with their weights equal to a given number. For example, let's consider the tree showed in Figure 1: for each node, the upper number is the node ID which is a two-digit number, and the lower number is the weight of that node. Suppose that the given number is 24, then there exists 4 different paths which have the same given weight: {10 5 2 7}, {10 4 10}, {10 3 3 6 2} and {10 3 3 6 2}, which correspond to the red edges in Figure 1.


Figure 1
Input Specification:

Each input file contains one test case. Each case starts with a line containing 0 < N <= 100, the number of nodes in a tree, M (< N), the number of non-leaf nodes, and 0 < S < 230, the given weight number. The next line contains N positive numbers where Wi (<1000) corresponds to the tree node Ti. Then M lines follow, each in the format:

ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the root ID to be 00.

Output Specification:

For each test case, print all the paths with weight S in non-increasing order. Each path occupies a line with printed weights from the root to the leaf in order. All the numbers must be separated by a space with no extra space at the end of the line.

Note: sequence {A1, A2, ..., An} is said to be greater than sequence {B1, B2, ..., Bm} if there exists 1 <= k < min{n, m} such that Ai = Bi for i=1, ... k, and Ak+1 > Bk+1.

Sample Input:
20 9 24
10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
00 4 01 02 03 04
02 1 05
04 2 06 07
03 3 11 12 13
06 1 09
07 2 08 10
16 1 15
13 3 14 16 17
17 2 18 19
Sample Output:
10 5 2 7
10 4 10
10 3 3 6 2
10 3 3 6 2*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 110;
const int INF = 0xfffffff;

struct Node {
    int val;
    vector<int> child;
} node[maxn];

bool vis[maxn] = {false};
int n, m, s;
int path[maxn];
void DFS(int nowVist, int numNode, int totalValue) {
    if (totalValue > s) return;
    if (totalValue == s) {
        if (node[nowVist].child.empty() == false) return;
        for (int i = 0; i < numNode; ++i) {
            printf("%d", node[path[i]].val);
            if(i<numNode-1)
                printf(" ");
            else
                printf("\n");
        }
    }
    for (int i = 0; i < node[nowVist].child.size(); ++i) {
          int child=node[nowVist].child[i];
        path[numNode]=child;
        DFS(child,numNode+1,totalValue+node[child].val);
    }
}

bool cmp(int a,int b){
    return node[a].val>node[b].val;
}

int main() {
    // freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    scanf("%d%d%d", &n, &m, &s);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &node[i].val);
    }
    for (int i = 0; i < m; ++i) {
        int id, k, child;
        scanf("%d%d", &id, &k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &child);
            node[id].child.push_back(child);
        }
        sort(node[id].child.begin(),node[id].child.end(),cmp);
    }
    path[0]=0;
    DFS(0,1,node[0].val);

    return 0;
}
