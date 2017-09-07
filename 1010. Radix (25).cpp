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

typedef long long LL;

int Map[256];
LL inf=(1LL << 63)-1;

void init(){
    for(char c='0';c<='9';c++){
        Map[c]=c-'0';
    }
    for(char c='a';c<='z';c++){
        Map[c]=c-'a'+10;
    }
}

LL convertTo10Num(char s[], int redix,LL t){
    int len=strlen(s);
    int sum=0;
    for(int i=0;i<len;i++){
        sum=sum*redix+Map[s[i]];
        if(sum<0||sum>t)    return -1;
    }
    return sum;
}

int cmp(char s[], int redix,LL t){
    LL num=convertTo10Num(s,redix,inf);
    if(num<0)   return 1;
    if(num<t)   return -1;
    else if(num==t) return 0;
    else return 1;
}

LL binarySearch(char N2[],LL left,LL right,LL t){
    LL mid;
    while(left<=right){
        mid=(left+right)/2;
        int flag=cmp(N2,mid,t);
        if(flag==0) return mid;
        else if(flag==-1) left=mid+1;
        else right=mid-1;
    }
    return -1;
}

int findLargestDigit(char N2[]){
    int k=-1;
    int len=strlen(N2);
    for(int i=0;i<len;i++){
        k=max(k,Map[N2[i]]);
    }
    return k+1;
}

char N1[20],N2[20],temp[20];
int tag,redix;

int main() {
    freopen("data.in", "r", stdin);
    init();
    scanf("%s %s %d %d", N1, N2, &tag, &redix);
    if(tag==2){
        strcpy(temp,N1);
        strcpy(N1,N2);
        strcpy(N2,temp);
    }
    LL t=convertTo10Num(N1,redix,inf);
    LL low=findLargestDigit(N2);
    LL high=max(low,t)+1;
    LL ans=binarySearch(N2,low,high,t);
    if(ans==-1) printf("Impossible\n");
    else printf("%lld\n", ans);

    return 0;
}
