/*1101. Quick Sort (25)
时间限制
200 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CAO, Peng
There is a classical process named partition in the famous quick sort algorithm. In this process we typically choose one element as the pivot. Then the elements less than the pivot are moved to its left and those larger than the pivot to its right. Given N distinct positive integers after a run of partition, could you tell how many elements could be the selected pivot for this partition?

For example, given N = 5 and the numbers 1, 3, 2, 4, and 5. We have:

1 could be the pivot since there is no element to its left and all the elements to its right are larger than it;
3 must not be the pivot since although all the elements to its left are smaller, the number 2 to its right is less than it as well;
2 must not be the pivot since although all the elements to its right are larger, the number 3 to its left is larger than it as well;
and for the similar reason, 4 and 5 could also be the pivot.
Hence in total there are 3 pivot candidates.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<= 105). Then the next line contains N distinct positive integers no larger than 109. The numbers in a line are separated by spaces.

Output Specification:

For each test case, output in the first line the number of pivot candidates. Then in the next line print these candidates in increasing order. There must be exactly 1 space between two adjacent numbers, and no extra space at the end of each line.

Sample Input:
5
1 3 2 4 5
Sample Output:
3
1 4 5*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100011;
const int INF = 1000000000;

int leftMax[maxn], rightMin[maxn], a[maxn];

int main() {
    // freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    int n, m = 0;
    int ans[maxn];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    leftMax[0] = 0;
    for (int i = 1; i < n; ++i) {
        leftMax[i] = max(leftMax[i - 1], a[i - 1]);
    }
    rightMin[n - 1] = INF;
    for (int i = n - 2; i >= 0; i--) {
        rightMin[i] = min(rightMin[i + 1], a[i + 1]);
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] < rightMin[i] && a[i] > leftMax[i])
            ans[m++] = a[i];
    }
    printf("%d\n", m);
    for (int i = 0; i < m; ++i) {
        printf("%d", ans[i]);
        if (i < m - 1) printf(" ");
    }
    printf("\n");
    
    return 0;
}

