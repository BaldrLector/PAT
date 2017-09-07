#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 1100;

struct bign {
    int d[maxn];
    int len;

    bign() {
        fill(d, d + maxn, 0);
        len = 0;
    }
};

bign toBign(char str[]) {
    bign a;
    a.len = strlen(str);
    for (int i = 0; i < a.len; i++) {
        a.d[i] = str[a.len - i - 1] - '0';
    }
    return a;
}

bign reverseBign(bign a) {
    bign c = a;
    reverse(c.d, c.d + c.len);
    return c;
}

bign plusBign(bign a, bign b) {
    bign c;
    int carry=0;
    for (int i = 0; i < a.len||i<b.len; ++i) {
        int temp=carry+a.d[i]+b.d[i];
        c.d[c.len++]=temp%10;
        carry=temp/10;
    }
    while(carry!=0){
        c.d[c.len++]=carry%10;
        carry/=10;
    }
    return c;
}

bool judge(bign a){
    for(int i=0;i<a.len/2;i++){
        if(a.d[i]!=a.d[a.len-i-1])
            return false;
    }
    return true;
}

void printBign(bign a){
    for(int i=a.len-1;i>=0;i--){
        printf("%d",a.d[i]);
    }
    printf("\n");
}

int main() {
    int t,k=0;
    char str[10010];
    scanf("%s%d", str, &t);
    bign a=toBign(str);
    while(k<t&&judge(a)==false){
        bign b=a;
        reverse(b.d,b.d+b.len);
        a=plusBign(a,b);
        k++;
    }
    printBign(a);
    printf("%d\n",k);
    

    return 0;
}
