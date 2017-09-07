#include<cstdio>
#include <cmath>

using namespace std;

const int maxn = 2010;

bool isPrime(int n) {
    if (n <= 1)
        return false;
    int sq = (int) sqrt(1.0 * n);
    for (int i = 2; i <= sq; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int ToRedix(int num, int redix) {
    int a = 0;
    while (num != 0) {
        a = a * redix + num % redix;
        num /= redix;
    }
    return a;
}


int main() {
    int num, redix;

    while (true) {
        scanf("%d", &num);
        if (num < 0) break;
        scanf("%d", &redix);
        if (isPrime(num) == false) {
            printf("No\n");
        } else {

            if (isPrime(ToRedix(num, redix))) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    return 0;
}
