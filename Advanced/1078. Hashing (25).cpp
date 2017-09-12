/*1078. Hashing (25)
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
The task of this problem is simple: insert a sequence of distinct positive integers into a hash table, and output the positions of the input numbers. The hash function is defined to be "H(key) = key % TSize" where TSize is the maximum size of the hash table. Quadratic probing (with positive increments only) is used to solve the collisions.

Note that the table size is better to be prime. If the maximum size given by the user is not prime, you must re-define the table size to be the smallest prime number which is larger than the size given by the user.

Input Specification:

Each input file contains one test case. For each case, the first line contains two positive numbers: MSize (<=104) and N (<=MSize) which are the user-defined table size and the number of input numbers, respectively. Then N distinct positive integers are given in the next line. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print the corresponding positions (index starts from 0) of the input numbers in one line. All the numbers in a line are separated by a space, and there must be no extra space at the end of the line. In case it is impossible to insert the number, print "-" instead.

Sample Input:
4 4
10 6 4 15
Sample Output:
0 1 4 -
*/
*

#include <cstdio>
#include <cmath>

using namespace std;

const int maxn = 10020;
const int INF = 1000000000;

const int N = 11111;

bool isPrime(int n) {
    int sqr = (int) sqrt(1.0 * n);
    if (n <= 1) return false;
    for (int i = 2; i <= sqr; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

bool hashTable[N] = {false};

int main() {
    // freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    int n, Tsize, a;
    scanf("%d%d", &Tsize, &n);
    while (isPrime(Tsize) == false) {
        Tsize++;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        int M = a % Tsize;
        if (hashTable[M] == false) {
            hashTable[M] = true;
            if (i == 0) printf("%d", M);
            else printf(" %d", M);
        } else {
            int step;
            for (step = 1; step <=Tsize; step++) {
                M = (a + step * step) % Tsize;
                if (hashTable[M] == false) {
                    hashTable[M] = true;
                    if (i == 0) printf("%d", M);
                    else printf(" %d", M);
                    break;
                }
                if (step >= Tsize) {
                    if (i > 0) printf(" ");
                    printf("-");
                }
            }
        }
    }

    return 0;
}


