/*1033. To Fill or Not to Fill (25)
时间限制
100 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
ZHANG, Guochuan
With highways available, driving a car from Hangzhou to any other city is easy. But since the tank capacity of a car is limited, we have to find gas stations on the way from time to time. Different gas station may give different price. You are asked to carefully design the cheapest route to go.

Input Specification:

Each input file contains one test case. For each case, the first line contains 4 positive numbers: Cmax (<= 100), the maximum capacity of the tank; D (<=30000), the distance between Hangzhou and the destination city; Davg (<=20), the average distance per unit gas that the car can run; and N (<= 500), the total number of gas stations. Then N lines follow, each contains a pair of non-negative numbers: Pi, the unit gas price, and Di (<=D), the distance between this station and Hangzhou, for i=1,...N. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print the cheapest price in a line, accurate up to 2 decimal places. It is assumed that the tank is empty at the beginning. If it is impossible to reach the destination, print "The maximum travel distance = X" where X is the maximum possible distance the car can run, accurate up to 2 decimal places.

Sample Input 1:
50 1300 12 8
6.00 1250
7.00 600
7.00 150
7.10 0
7.20 200
7.50 400
7.30 1000
6.85 300
Sample Output 1:
749.17
Sample Input 2:
50 1300 12 2
7.10 0
7.00 600
Sample Output 2:
The maximum travel distance = 1200.00*/

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 510;
const int INF = 0xfffffff;

struct station{
    double price,dis;
}st[maxn];

bool cmp(station a,station b){
    return a.dis<b.dis;
}
int main() {
    freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    int n;
    double cmax,d,davg;
    scanf("%lf%lf%lf%d", &cmax, &d, &davg, &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf%lf", &st[i].price, &st[i].dis);
    }
    st[n].price=0,st[n].dis=d;
    sort(st,st+n,cmp);
    if(st[0].dis!=0){
        printf("The maximum travel distance = 0.00\n");
    } else{
        int now=0;
        double ans=0,nowTank=0,MAX=cmax*davg;
        while (now<n){
            int k=-1;
            double priceMin=INF;
            for (int i = now+1; i <=n&&st[i].dis-st[now].dis<=MAX ; ++i) {
                if(st[i].price<priceMin){
                    k=i;
                    priceMin=st[i].price;
                    if(priceMin<st[now].price){
                        break;
                    }
                }
            }
            if(k==-1) break;
            double need=(st[k].dis-st[now].dis)/davg;
            if(priceMin<st[now].price){
                if(nowTank<need){
                    ans+=(need-nowTank)*st[now].price;
                    nowTank=0;
                } else{
                    nowTank-=need;
                }
            } else{
                ans+=(cmax-nowTank)*st[now].price;
                nowTank=cmax-need;
            }
            now=k;
        }
        if(now==n){
            printf("%.2f\n", ans);
        } else{
            printf("The maximum of travel distance = %.2f\n", st[now].dis+MAX);
        }
    }
    
    return 0;
}
