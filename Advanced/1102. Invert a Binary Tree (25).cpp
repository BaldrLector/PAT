/*1102. Invert a Binary Tree (25)
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
The following is from Max Howell @twitter:

Google: 90% of our engineers use the software you wrote (Homebrew), but you can't invert a binary tree on a whiteboard so fuck off.

Now it's your turn to prove that YOU CAN invert a binary tree!

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=10) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to N-1. Then N lines follow, each corresponds to a node from 0 to N-1, and gives the indices of the left and right children of the node. If the child does not exist, a "-" will be put at the position. Any pair of children are separated by a space.

Output Specification:

For each test case, print in the first line the level-order, and then in the second line the in-order traversal sequences of the inverted tree. There must be exactly one space between any adjacent numbers, and no extra space at the end of the line.

Sample Input:
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6
Sample Output:
3 7 2 6 4 0 5 1
6 5 7 4 3 2 0 1*/

#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 100011;
const int INF = 1000000000;

struct Node {
    int lchild, rchild;
} node[maxn];

int n, num = 0;

void levelOrder(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        printf("%d", top);
        num++;
        if (num < n) printf(" ");
        else printf("\n");
        if (node[top].lchild != -1) q.push(node[top].lchild);
        if (node[top].rchild != -1) q.push(node[top].rchild);
    }

}

void inOrder(int root) {
    if (root == -1) return;
    inOrder(node[root].lchild);
    printf("%d", root);
    num++;
    if (num < n) printf(" ");
    inOrder(node[root].rchild);
}

void InvertTree(int root) {
    if (root == -1) return;
    InvertTree(node[root].lchild);
    InvertTree(node[root].rchild);
    swap(node[root].lchild, node[root].rchild);
}

int main() {
    // freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    scanf("%d", &n);
    getchar();
    int root;
    bool isRoot[maxn];
    fill(isRoot,isRoot+maxn,true);
    for (int i = 0; i < n; ++i) {
        char left, right;
        scanf("%c %c", &left, &right);
        getchar();
        if (left != '-') {
            node[i].lchild = left - '0';
            isRoot[left-'0']=false;
        } else{
            node[i].lchild = -1;
        }
        if (right != '-') {
            node[i].rchild = right - '0';
            isRoot[right-'0']=false;
        } else{
            node[i].rchild = -1;
        }
    }
    for (int i = 0; i < n; ++i) {
        if(isRoot[i]==true){
            root=i;
            break;
        }
    }
    InvertTree(root);
    levelOrder(root);
    num=0;
    inOrder(root);

    return 0;
}

