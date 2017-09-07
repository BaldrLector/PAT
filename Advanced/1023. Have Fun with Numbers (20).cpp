//not all right
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 1100;

struct bign{
    int d[21];
    int len;
    bign(){
        memset(d,0, sizeof(d));
        len=0;
    }
};

bign change(char str[]){
    bign a;
    a.len=strlen(str);
    for(int i=0;i<a.len;i++){
        a.d[i]=str[a.len-i-1]-'0';
    }
    return a;
}

bign multi(bign a,int b){
    bign c;
    int carry=0;
    for(int i=0;i<a.len;i++){
        int temp=a.d[i]*b+carry;
        c.d[c.len++]=temp%10;
        carry=temp/10;
    }
    while (carry!=0){
        c.d[c.len++]=carry%10;
        carry/=10;
    }
    return c;
}

bool judge(bign a,bign b){
    if(a.len!=b.len) return false;
    int count[10]={0};
    for (int i = 0; i < a.len; ++i) {
        count[a.d[i]]++;
        count[b.d[i]]--;
    }
    for(int i=0;i<10;i++){
        if(count[i]!=0)
            return false;
    }
    return true;
}

void print(bign a){
    for (int i = a.len-1; i >=0 ; --i) {
        printf("%d", a.d[i]);
    }
}

int main() {
    freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    char str[30];
    scanf("%s", str);
    bign a=change(str);
    bign mul=multi(a,2);
    if(judge(a,mul)==true){
        printf("Yes\n");
        print(mul);
    } else{
        printf("No\n");
    }
    return 0;
}
