#include<cstdio>

int main(){
    int n;
    int a[110];
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    int sum=0,now=0;
    for(int i=0;i<n;i++){
        if(a[i]>now){
            sum+=(a[i]-now)*6;
            now=a[i];
        }else if(a[i]<now){
            sum+=(now-a[i])*4;
            now=a[i];
        }
        sum+=5;
    }
    printf("%d", sum);
}
