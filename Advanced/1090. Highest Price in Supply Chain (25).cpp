/*1090. Highest Price in Supply Chain (25)
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
A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）-- everyone involved in moving a product from supplier to customer.

Starting from one root supplier, everyone on the chain buys products from one's supplier in a price P and sell or distribute them in a price that is r% higher than P. It is assumed that each member in the supply chain has exactly one supplier except the root supplier, and there is no supply cycle.

Now given a supply chain, you are supposed to tell the highest price we can expect from some retailers.

Input Specification:

Each input file contains one test case. For each case, The first line contains three positive numbers: N (<=105), the total number of the members in the supply chain (and hence they are numbered from 0 to N-1); P, the price given by the root supplier; and r, the percentage rate of price increment for each distributor or retailer. Then the next line contains N numbers, each number Si is the index of the supplier for the i-th member. Sroot for the root supplier is defined to be -1. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the highest price we can expect from some retailers, accurate up to 2 decimal places, and the number of retailers that sell at the highest price. There must be one space between the two numbers. It is guaranteed that the price will not exceed 1010.

Sample Input:
9 1.80 1.00
1 5 4 4 -1 4 5 3 6
Sample Output:
1.85 2*/

#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 100100;
const int INF = 1000000000;

struct node{
    int level;
    vector<int> child;
}Node[maxn];

int n,root,maxDepth=0,num=0;
double p,r;

void DFS(int root,int depth) {
    if(Node[root].child.size()==0){
        if(depth>maxDepth)  {
            maxDepth=depth;
            num=1;
        } else if(depth==maxDepth){
            num++;
        }
        return;
    }
    for (int i = 0; i < Node[root].child.size(); ++i) {
        int u=Node[root].child[i];
        DFS(u,depth+1);
    }
}

int main() {
    // freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    scanf("%d%lf%lf", &n, &p, &r);
    r/=100;
    for (int i = 0; i < n; ++i) {
        int father;
        scanf("%d", &father);
        if(father==-1){
            root=i;
        } else{
            Node[father].child.push_back(i);
        }
    }
    DFS(root,0);

    printf("%.2f %d", p*pow(1+r,maxDepth), num);

    return 0;
}

