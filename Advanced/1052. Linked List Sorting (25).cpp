/*1052. Linked List Sorting (25)
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
A linked list consists of a series of structures, which are not necessarily adjacent in memory. We assume that each structure contains an integer key and a Next pointer to the next structure. Now given a linked list, you are supposed to sort the structures according to their key values in increasing order.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive N (< 105) and an address of the head node, where N is the total number of nodes in memory and the address of a node is a 5-digit positive integer. NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Key Next

where Address is the address of the node in memory, Key is an integer in [-105, 105], and Next is the address of the next node. It is guaranteed that all the keys are distinct and there is no cycle in the linked list starting from the head node.

Output Specification:

For each test case, the output format is the same as that of the input, where N is the total number of nodes in the list and all the nodes must be sorted order.

Sample Input:
5 00001
11111 100 -1
00001 0 22222
33333 100000 11111
12345 -1 33333
22222 1000 12345
Sample Output:
5 12345
12345 -1 00001
00001 0 11111
11111 100 22222
22222 1000 33333
33333 100000 -1
*/
*
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100010;
const int INF = 0xfffffff;

struct Node {
    int id, next, val;
    bool flag;
} node[maxn];

bool cmp(Node a, Node b) {
    if (a.flag == false || b.flag == false) {
        return a.flag > b.flag;
    } else
        return a.val < b.val;
}

int main() {
    // freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    for (int i = 0; i < maxn; ++i) {
        node[i].flag=false;
    }
    int n, st;
    scanf("%d%d", &n, &st);
    for (int i = 0; i < n; ++i) {
        int id;
        scanf("%d", &id);
        node[id].id = id;
        scanf("%d%d", &node[id].val, &node[id].next);
    }
    int numberNode = 0, now = st;
    while (now != -1) {
        node[now].flag=true;
        now = node[now].next;
        numberNode++;
    }
    if(numberNode==0){
        printf("0 -1");
    } else{
        sort(node, node + maxn, cmp);
        printf("%d %05d\n", numberNode, node[0].id);
        for (int i = 0; i < numberNode; i++) {
            if (i < numberNode - 1)
                printf("%05d %d %05d\n", node[i].id, node[i].val, node[i + 1].id);
            else
                printf("%05d %d -1", node[i].id, node[i].val);
        }
    }

    return 0;
}
