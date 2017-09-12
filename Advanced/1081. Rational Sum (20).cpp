/*1081. Rational Sum (20)
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
Given N rational numbers in the form "numerator/denominator", you are supposed to calculate their sum.

Input Specification:

Each input file contains one test case. Each case starts with a positive integer N (<=100), followed in the next line N rational numbers "a1/b1 a2/b2 ..." where all the numerators and denominators are in the range of "long int". If there is a negative number, then the sign must appear in front of the numerator.

Output Specification:

For each test case, output the sum in the simplest form "integer numerator/denominator" where "integer" is the integer part of the sum, "numerator" < "denominator", and the numerator and the denominator have no common factor. You must output only the fractional part if the integer part is 0.

Sample Input 1:
5
2/5 4/15 1/30 -2/60 8/3
Sample Output 1:
3 1/3
Sample Input 2:
2
4/3 2/3
Sample Output 2:
2
Sample Input 3:
3
1/3 -1/6 1/8
Sample Output 3:
7/24*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100020;
const int INF = 1000000000;

long long gcd(long long a,long long b){
    return b==0?a:gcd(b,a%b);
}

struct Fraction{
    long long up,down;
};

Fraction reduction(Fraction result){
    if(result.down<0){
        result.down=-result.down;
        result.up=-result.up;
    }
    if(result.up==0){
        result.down=1;
    } else{
        int d=gcd(abs(result.up),abs(result.down));
        result.up/=d;
        result.down/=d;
    }
    return result;
}

Fraction add(Fraction f1,Fraction f2){
    Fraction result;
    result.up=f1.up*f2.down+f1.down*f2.up;
    result.down=f1.down*f2.down;
    return reduction(result);
}

Fraction minus(Fraction f1,Fraction f2){
    Fraction result;
    result.up=f1.up*f2.down-f1.down*f2.up;
    result.down=f1.down*f2.down;
    return reduction(result);
}

Fraction multi(Fraction f1,Fraction f2){
    Fraction result;
    result.up=f1.up*f2.up;
    result.down=f1.down*f2.down;
    return reduction(result);
}

Fraction divide(Fraction f1,Fraction f2){
    Fraction result;
    result.up=f1.up*f2.down;
    result.down=f1.down*f2.up;
    return reduction(result);
}

void showResult(Fraction r){
    reduction(r);
    if(r.down==1) printf("%lld\n", r.up);
    else if(abs(r.up)>r.down){
        printf("%lld %lld/%lld", r.up/r.down, abs(r.up)%r.down, r.down);
    } else{
        printf("%lld/%lld", r.up, r.down);
    }
}



int main() {
    // freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    int n;
    Fraction sum,temp;
    scanf("%d", &n);

    sum.up=0;sum.down=1;

    for (int i = 0; i < n; ++i) {
        scanf("%lld/%lld", &temp.up, &temp.down);
        sum=add(sum,temp);
    }

    showResult(sum);

    return 0;
}

