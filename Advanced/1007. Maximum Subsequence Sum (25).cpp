#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<cstdlib>
#include<queue>
using namespace std;
const int maxn=10100;
const int INF=1000000000;

int a[maxn],dp[maxn],s[maxn];

int main() {
    freopen("data.in", "r", stdin);

    int n;
    bool flag=true;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]>=0) flag=false;
    }
    if(flag){
        printf("0 %d %d\n", a[0], a[n-1]);
        return 0;
    }
    dp[0]=a[0];
    s[0]=0;
    for(int i=1;i<n;i++){
        if(a[i]<dp[i-1]+a[i]){
            dp[i]=dp[i-1]+a[i];
            s[i]=s[i-1];
        }else{
            dp[i]=a[i];
            s[i]=i;
        }
    }
    int k=0;
    for(int i=1;i<n;i++){
        if(dp[i]>dp[k]){
            k=i;
        }
    }
    printf("%d %d %d\n", dp[k], a[s[k]], a[k]);
    return 0;
}
