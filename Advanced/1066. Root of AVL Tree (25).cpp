/*1066. Root of AVL Tree (25)
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
An AVL tree is a self-balancing binary search tree. In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property. Figures 1-4 illustrate the rotation rules.

    
    
Now given a sequence of insertions, you are supposed to tell the root of the resulting AVL tree.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=20) which is the total number of keys to be inserted. Then N distinct integer keys are given in the next line. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print ythe root of the resulting AVL tree in one line.

Sample Input 1:
5
88 70 61 96 120
Sample Output 1:
70
Sample Input 2:
7
88 70 61 96 120 90 65
Sample Output 2:
88*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1010;
const int INF = 0xfffffff;

struct node {
    int data;
    node *left, *right;
    int Height;
}*root;

node* newNode(int x) {
    node* Node = new node;
    Node->data = x;
    Node->Height = 1;
    Node->left = Node->right = NULL;
    return Node;
}

int getHeight(node* root) {
    if (root == NULL) return 0;
    return root->Height;
}

void updataHeight(node* root) {
    root->Height = max(getHeight(root->left), getHeight(root->right)) + 1;
}

int getBalanceFactor(node* root) {
    return getHeight(root->left) - getHeight(root->right);
}

void L(node* &root) {
    node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    updataHeight(root);
    updataHeight(temp);
    root = temp;
}

void R(node* &root) {
    node *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updataHeight(root);
    updataHeight(temp);
    root = temp;
}

void InsertAVL(node* &root, int x) {
    if (root == NULL) {
        root = newNode(x);
        return;;
    }
    if (x < root->data) {
        InsertAVL(root->left, x);
        updataHeight(root);
        if (getBalanceFactor(root) == 2) {
            if (getBalanceFactor(root->left) == 1) {
                R(root);
            } else if (getBalanceFactor(root->left) == -1) {
                L(root->left);
                R(root);
            }
        }
    } else {
        InsertAVL(root->right, x);
        updataHeight(root);
        if (getBalanceFactor(root) == -2) {
            if (getBalanceFactor(root->right) == -1) {
                L(root);
            } else if (getBalanceFactor(root->right) == 1) {
                R(root->right);
                L(root);
            }
        }
    }
}

int main() {
    // freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        InsertAVL(root, x);
    }
    printf("%d", root->data);

    return 0;
}

