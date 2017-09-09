/*1059. Prime Factors (25)
时间限制
100 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
HE, Qinming
Given any positive integer N, you are supposed to find all of its prime factors, and write them in the format N = p1^k1 * p2^k2 *…*pm^km.

Input Specification:

Each input file contains one test case which gives a positive integer N in the range of long int.

Output Specification:

Factor N in the format N = p1^k1 * p2^k2 *…*pm^km, where pi's are prime factors of N in increasing order, and the exponent ki is the number of pi -- hence when there is only one pi, ki is 1 and must NOT be printed out.

Sample Input:
97532468
Sample Output:
97532468=2^2*11*17*101*1291*/


//partical right
#include <cstdio>
#include <cmath>

using namespace std;

const int maxn = 100010;
const int INF = 0xfffffff;

bool isPrime(int n) {
	if (n == 1)
		return false;
	int sqr = (int) sqrt(1.0 * n);
	for (int i = 2; i <= sqr; ++i) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int pn = 0, p[maxn];

void findPrime() {
	for (int i = 1; i < maxn; ++i) {
		if (isPrime(i)) {
			p[pn++] = i;
		}
	}
}

struct factor{
	int x,cnt;
}fac[10];

int main() {
    // freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

	findPrime();
	long n;
	int num = 0;
	scanf("%ld", &n);
	if (n == 1) printf("1=1");
	else {
		printf("%ld=", n);
		int sqr=(int)sqrt(1.0*n);
		for (int i = 0; i < pn&&p[i]<=sqr; ++i) {
			if(n%p[i]==0){
				fac[num].x=p[i];
				fac[num].cnt=0;
				while(n%p[i]==0){
					n/=p[i];
					fac[num].cnt++;
				}
				num++;
			}
			if(n==1) break;
		}
		if(n!=1){
			fac[num].x=n;
			fac[num].cnt=1;
		}
		for (int i = 0; i < num; ++i) {
			if(i>0)
				printf("*");
			printf("%d", fac[i].x);
			if(fac[i].cnt>1)
				printf("^%d", fac[i].cnt);
		}
	}

	return 0;
}
