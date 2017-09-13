/*1105. Spiral Matrix (25)
时间限制
150 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
This time your job is to fill a sequence of N positive integers into a spiral matrix in non-increasing order. A spiral matrix is filled in from the first element at the upper-left corner, then move in a clockwise spiral. The matrix has m rows and n columns, where m and n satisfy the following: m*n must be equal to N; m>=n; and m-n is the minimum of all the possible values.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N. Then the next line contains N positive integers to be filled into the spiral matrix. All the numbers are no more than 104. The numbers in a line are separated by spaces.

Output Specification:

For each test case, output the resulting matrix in m lines, each contains n numbers. There must be exactly 1 space between two adjacent numbers, and no extra space at the end of each line.

Sample Input:
12
37 76 20 98 76 42 53 95 60 81 58 93
Sample Output:
98 95 93
42 37 81
53 20 76
58 60 76*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 10011;
const int INF = 1000000000;

int matrix[maxn][maxn], A[maxn];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    // freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    if (N == 1) {
        printf("%d", A[0]);
        return 0;
    }
    sort(A, A + N, cmp);
    int m = (int) ceil(sqrt(1.0 * N));
    while (N % m != 0) {
        m++;
    }
    int n = N / m, i = 1, j = 1, now = 0;
    int U = 1, D = m, L = 1, R = n;
    while (now < N) {
        while (now < N && j < R) {
            matrix[i][j] = A[now++];
            j++;
        }
        while (now < N && i < D) {
            matrix[i][j] = A[now++];
            i++;
        }
        while (now < N && j > L) {
            matrix[i][j] = A[now++];
            j--;
        }
        while (now < N && i > U) {
            matrix[i][j] = A[now++];
            i--;
        }
        U++, D--, L++, R--;
        i++, j++;
        if (now == N - 1) {
            matrix[i][j] = A[now++];
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d", matrix[i][j]);
            if (j < n) printf(" ");
            else printf("\n");
        }
    }

    return 0;
}

