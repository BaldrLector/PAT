/*1106. Lowest Price in Supply Chain (25)
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

Starting from one root supplier, everyone on the chain buys products from one's supplier in a price P and sell or distribute them in a price that is r% higher than P. Only the retailers will face the customers. It is assumed that each member in the supply chain has exactly one supplier except the root supplier, and there is no supply cycle.

Now given a supply chain, you are supposed to tell the lowest price a customer can expect from some retailers.

Input Specification:

Each input file contains one test case. For each case, The first line contains three positive numbers: N (<=105), the total number of the members in the supply chain (and hence their ID's are numbered from 0 to N-1, and the root supplier's ID is 0); P, the price given by the root supplier; and r, the percentage rate of price increment for each distributor or retailer. Then N lines follow, each describes a distributor or retailer in the following format:

Ki ID[1] ID[2] ... ID[Ki]

where in the i-th line, Ki is the total number of distributors or retailers who receive products from supplier i, and is then followed by the ID's of these distributors or retailers. Kj being 0 means that the j-th member is a retailer. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the lowest price we can expect from some retailers, accurate up to 4 decimal places, and the number of retailers that sell at the lowest price. There must be one space between the two numbers. It is guaranteed that the all the prices will not exceed 1010.

Sample Input:
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0
2 6 1
1 8
0
0
0
Sample Output:
1.8362 2*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100011;
const int INF = 1000000000;

struct Node {
    vector<int> child;
} node[maxn];
int n,num=0;
double p, r, ans = INF;

void DFS(int index,int depth) {
    if (node[index].child.size() == 0) {
        double price=p*pow(1+r,depth);
        if(price<ans){
            ans=price;
            num=1;
        } else if(price==ans){
            num++;
        }
        return;
    }
    for (int i = 0; i < node[index].child.size(); ++i) {
        int u=node[index].child[i];
        DFS(node[index].child[i],depth+1);
    }
}

int main() {
    // freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    scanf("%d%lf%lf", &n, &p, &r);
    r /= 100;
    for (int i = 0; i < n; ++i) {
        int k, child;
        scanf("%d", &k);
        if(k!=0){
            for (int j = 0; j < k; ++j) {
                scanf("%d", &child);
                node[i].child.push_back(child);
            }
        }
    }
    DFS(0,0);
    printf("%.4f %d", ans, num);

    return 0;
}

