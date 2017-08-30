#include<cstdio>
using namespace std;
const int maxn=100;

int main(){
    //freopen("data.in","r",stdin);
    int a,b;
    scanf("%d%d", &a, &b);
    a+=b;
    if(a==0){
        printf("0");
        return 0;
    }
    if(a<0){
        a=-a;
        printf("-");
    }
    int ans[maxn]={0};
    int n=0;
    while(a!=0){
        ans[n++]=a%10;
        a/=10;
    }
    for(int i=n-1;i>=0;i--){
        printf("%d", ans[i]);
        if(i%3==0&&i!=0)
            printf(",");
    }

    return 0;
}