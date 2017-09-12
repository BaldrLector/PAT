/*1086. Tree Traversals Again (25)
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
An inorder binary tree traversal can be implemented in a non-recursive way with a stack. For example, suppose that when a 6-node binary tree (with the keys numbered from 1 to 6) is traversed, the stack operations are: push(1); push(2); push(3); pop(); pop(); push(4); pop(); pop(); push(5); push(6); pop(); pop(). Then a unique binary tree (shown in Figure 1) can be generated from this sequence of operations. Your task is to give the postorder traversal sequence of this tree.


Figure 1
Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=30) which is the total number of nodes in a tree (and hence the nodes are numbered from 1 to N). Then 2N lines follow, each describes a stack operation in the format: "Push X" where X is the index of the node being pushed onto the stack; or "Pop" meaning to pop one node from the stack.

Output Specification:

For each test case, print the postorder traversal sequence of the corresponding tree in one line. A solution is guaranteed to exist. All the numbers must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop
Sample Output:
3 4 2 6 5 1
*/
*
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

const int maxn = 50;
const int INF = 1000000000;

struct node {
    int data;
    node *rchild;
    node *lchild;
};

int pre[maxn], in[maxn], post[maxn];
int n;

node* Create(int preL, int preR, int inL, int inR) {
    if (preL > preR) return NULL;
    node *root = new node;
    root->data = pre[preL];
    int k;
    for (k = inL; k < inR; k++) {
        if (in[k] == pre[preL]) {
            break;
        }
    }
    int numLeft = k - inL;
    root->lchild = Create(preL + 1, preL + numLeft, inL, k - 1);
    root->rchild = Create(preL + numLeft + 1, preR, k + 1, inR);
    return root;
}

int num = 0;

void postOrder(node *root) {
    if (root == NULL)
        return;
    postOrder(root->lchild);
    postOrder(root->rchild);
    printf("%d", root->data);
    num++;
    if (num < n)
        printf(" ");
}

int main() {
    // freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    scanf("%d", &n);
    char str[5];
    stack<int> st;
    int x, preIndex = 0, inIndex = 0;
    for (int i = 0; i < 2 * n; ++i) {
        scanf("%s", str);
        if (strcmp(str, "Push") == 0) {
            scanf("%d", &x);
            pre[preIndex++] = x;
            st.push(x);
        } else {
            in[inIndex++] = st.top();
            st.pop();
        }
    }

    node *root = Create(0, n - 1, 0, n - 1);
    postOrder(root);

    return 0;
}

