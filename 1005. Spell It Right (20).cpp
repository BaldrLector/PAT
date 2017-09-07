#include<cstdio>
#include<cstring>

const int maxn=10010;
char mp[10][20]={"zero","one","two","three","four","five","six","seven","eight","nine"};
int main(){
    char a[maxn];
    scanf("%s", a);
    if(a[0]=='0'){
        printf("zero");
        return 0;
    }
    int len=strlen(a);
    int sum=0;
    for(int i=0;i<len;i++){
        sum+=a[i]-'0';
    }
    int ans[maxn],n=0;
    while(sum!=0){
        ans[n++]=sum%10;
        sum/=10;
    }
    for(int i=n-1;i>=0;i--){
        printf("%s", mp[ans[i]]);
        if(i!=0)
            printf(" ");
    }
    return 0;
}
