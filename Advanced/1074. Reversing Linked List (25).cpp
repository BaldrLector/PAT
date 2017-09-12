/*1074. Reversing Linked List (25)
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
Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L. For example, given L being 1→2→3→4→5→6, if K = 3, then you must output 3→2→1→6→5→4; if K = 4, you must output 4→3→2→1→5→6.

Input Specification:

Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (<= 105) which is the total number of nodes, and a positive K (<=N) which is the length of the sublist to be reversed. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Data Next

where Address is the position of the node, Data is an integer, and Next is the position of the next node.

Output Specification:

For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.

Sample Input:
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
Sample Output:
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1*/

//particial right
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100020;
const int INF = 1000000000;

struct Node {
	int adress, val, next;
	int order;
} node[maxn], r[maxn];

bool cmp(Node a, Node b) {
	return a.order < b.order;
}

int main() {
    // freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

	for (int i = 0; i < maxn; ++i) {
		node[i].order = maxn;
	}
	int s, n, k, adress;
	scanf("%d%d%d", &s, &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &adress);
		node[adress].adress = adress;
		scanf("%d%d", &node[adress].val, &node[adress].next);
	}
	int p = s, count = 0;
	while (p != -1) {
		node[p].order = count++;
		p = node[p].next;
	}
	sort(node, node + maxn, cmp);
	n = count;
	for (int i = 0; i < n / k; ++i) {
		for (int j = (i + 1) * k - 1; j > i * k; j--) {
			printf("%05d %d %05d\n", node[j].adress, node[j].val, node[j - 1].adress);
		}
		printf("%05d %d ", node[i * k].adress, node[i * k].val);
		if (i < n / k - 1) {
			printf("%05d\n", node[(i + 2) * k - 1].adress);
		} else {
			if (n % k == 0) {
				printf("-1\n");
			} else {
				printf("%05d\n", node[(i + 1) * k].adress);
				for (int i = n / k * k; i < n; i++) {
					printf("%05d %d ", node[(i + 1) * k].adress, node[i].val);
					if (i < n - 1) {
						printf("%05d\n", node[i + 1].adress);
					} else {
						printf("-1\n");
					}
				}
			}
		}
	}

	return 0;
}

