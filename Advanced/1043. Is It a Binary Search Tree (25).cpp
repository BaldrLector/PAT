/*1043. Is It a Binary Search Tree (25)
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
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
If we swap the left and right subtrees of every node, then the resulting tree is called the Mirror Image of a BST.

Now given a sequence of integer keys, you are supposed to tell if it is the preorder traversal sequence of a BST or the mirror image of a BST.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=1000). Then N integer keys are given in the next line. All the numbers in a line are separated by a space.

Output Specification:

For each test case, first print in a line "YES" if the sequence is the preorder traversal sequence of a BST or the mirror image of a BST, or "NO" if not. Then if the answer is "YES", print in the next line the postorder traversal sequence of that tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

Sample Input 1:
7
8 6 5 7 10 8 11
Sample Output 1:
YES
5 7 6 8 11 10 8
Sample Input 2:
7
8 10 11 8 6 7 5
Sample Output 2:
YES
11 8 10 7 5 6 8
Sample Input 3:
7
8 6 8 5 10 9 11
Sample Output 3:
NO*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1010;
const int INF = 0xfffffff;

struct node{
    int data;
    node *left,*right;
};

void Insert(node* &root,int data){
    if(root==NULL){
        root=new node;
        root->data=data;
        root->left=root->right=NULL;
        return;
    }
    if(data<root->data) Insert(root->left,data);
    else Insert(root->right,data);
}

void preOrder(node* root,vector<int>& vi){
    if(root==NULL) return;;
    vi.push_back(root->data);
    preOrder(root->left,vi);
    preOrder(root->right,vi);
}

void preOrderMirror(node* root,vector<int>& vi){
    if(root==NULL) return;
    vi.push_back(root->data);
    preOrderMirror(root->right,vi);
    preOrderMirror(root->left,vi);
}

void postOrder(node* root,vector<int>& vi){
    if(root==NULL) return;
    postOrder(root->left,vi);
    postOrder(root->right,vi);
    vi.push_back(root->data);
}

void postOrderMirror(node* root,vector<int>& vi){
    if(root==NULL) return;
    postOrderMirror(root->right,vi);
    postOrderMirror(root->left,vi);
    vi.push_back(root->data);
}

vector<int> origin,pre,preM,post,postM;
int main() {
    int n,data;
    node *root=NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &data);
        origin.push_back(data);
        Insert(root,data);
    }
    preOrder(root,pre);
    preOrderMirror(root,preM);
    postOrder(root,post);
    postOrderMirror(root,postM);
    if(origin==pre){
        printf("YES\n");
        for (int i = 0; i < post.size(); ++i) {
            printf("%d", post[i]);
            if(i<post.size()-1)
                printf(" ");
        }
    } else if(origin==preM){
        printf("YES\n");
        for (int i = 0; i < postM.size(); ++i) {
            printf("%d", postM[i]);
            if(i<postM.size()-1)
                printf(" ");
        }
    } else{
        printf("NO");
    }

    return 0;
}
