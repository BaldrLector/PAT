/*1088. Rational Arithmetic (20)
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
For two rational numbers, your task is to implement the basic arithmetics, that is, to calculate their sum, difference, product and quotient.

Input Specification:

Each input file contains one test case, which gives in one line the two rational numbers in the format "a1/b1 a2/b2". The numerators and the denominators are all in the range of long int. If there is a negative sign, it must appear only in front of the numerator. The denominators are guaranteed to be non-zero numbers.

Output Specification:

For each test case, print in 4 lines the sum, difference, product and quotient of the two rational numbers, respectively. The format of each line is "number1 operator number2 = result". Notice that all the rational numbers must be in their simplest form "k a/b", where k is the integer part, and a/b is the simplest fraction part. If the number is negative, it must be included in a pair of parentheses. If the denominator in the division is zero, output "Inf" as the result. It is guaranteed that all the output integers are in the range of long int.

Sample Input 1:
2/3 -4/2
Sample Output 1:
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
Sample Input 2:
5/3 0/6
Sample Output 2:
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf
*/
*

// particail right
#include <cstdio>
#include <cmath>

using namespace std;

const int maxn = 210;
const int INF = 1000000000;

struct Fraction {
    long long up, down;
};

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

Fraction reduction(Fraction f) {
    if (f.down < 0) {
        f.up = -f.up;
        f.down = -f.down;
    }
    if (f.up == 0) {
        f.down = 1;
    } else {
        int d = gcd(abs(f.up), abs(f.down));
        f.up /= d;
        f.down /= d;
    }
    return f;
}

Fraction add(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down + f1.down * f2.up;
    result.down = f1.down * f2.down;
    return reduction(result);
}

Fraction minus(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down - f2.up * f1.down;
    result.down = f2.down * f1.down;
    return reduction(result);
}

Fraction multi(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.up;
    result.down = f2.down * f2.down;
    return reduction(result);
}

Fraction divide(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down;
    result.down = f1.down * f2.up;
    return reduction(result);
}

void showResult(Fraction r) {
    r = reduction(r);
    if (r.up < 0) printf("(");
    if (r.down == 1) printf("%lld", r.up);
    else if (abs(r.up) > r.down) {
        printf("%lld %lld/%lld", r.up / r.down, (long long)abs(r.up) % r.down, r.down);
    } else {
        printf("%lld/%lld", r.up, r.down);
    }
    if (r.up < 0) printf(")");
}

int main() {
    // freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    Fraction a, b;
    scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
    showResult(a);
    printf(" + ");
    showResult(b);
    printf(" = ");
    showResult(add(a, b));
    printf("\n");

    showResult(a);
    printf(" - ");
    showResult(b);
    printf(" = ");
    showResult(minus(a, b));
    printf("\n");

    showResult(a);
    printf(" * ");
    showResult(b);
    printf(" = ");
    showResult(multi(a, b));
    printf("\n");

    showResult(a);
    printf(" / ");
    showResult(b);
    printf(" = ");
    if (b.up == 0) printf("Inf");
    else showResult(divide(a, b));


    return 0;
}

