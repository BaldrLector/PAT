/*1067. Sort with Swap(0,*) (25)
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
Given any permutation of the numbers {0, 1, 2,..., N-1}, it is easy to sort them in increasing order. But what if Swap(0, *) is the ONLY operation that is allowed to use? For example, to sort {4, 0, 2, 1, 3} we may apply the swap operations in the following way:

Swap(0, 1) => {4, 1, 2, 0, 3}
Swap(0, 3) => {4, 1, 2, 3, 0}
Swap(0, 4) => {0, 1, 2, 3, 4}

Now you are asked to find the minimum number of swaps need to sort the given permutation of the first N nonnegative integers.

Input Specification:

Each input file contains one test case, which gives a positive N (<=105) followed by a permutation sequence of {0, 1, ..., N-1}. All the numbers in a line are separated by a space.

Output Specification:

For each case, simply print in a line the minimum number of swaps need to sort the given permutation.

Sample Input:
10 3 5 7 2 6 4 9 0 8 1
Sample Output:
9*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100010;
const int INF = 0xfffffff;

int pos[maxn];

int main() {
    // freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    int n,ans=0;
    scanf("%d", &n);
    int left=n-1,num;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num);
        pos[num]=i;
        if(num==i&&num!=0){
            left--;
        }
    }
    int k=1;
    while (left>0){
        if(pos[0]==0){
            while (k<n){
                if(pos[k]!=k){
                    swap(pos[0],pos[k]);
                    ans++;
                    break;
                }
                k++;
            }
        }
        while (pos[0]!=0){
            swap(pos[0],pos[pos[0]]);
            ans++;
            left--;
        }
    }
    printf("%d", ans);


    return 0;
}
