/*1057. Stack (30)
时间限制
150 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Stack is one of the most fundamental data structures, which is based on the principle of Last In First Out (LIFO). The basic operations include Push (inserting an element onto the top position) and Pop (deleting the top element). Now you are supposed to implement a stack with an extra operation: PeekMedian -- return the median value of all the elements in the stack. With N elements, the median value is defined to be the (N/2)-th smallest element if N is even, or ((N+1)/2)-th if N is odd.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<= 105). Then N lines follow, each contains a command in one of the following 3 formats:

Push key
Pop
PeekMedian
where key is a positive integer no more than 105.

Output Specification:

For each Push command, insert key into the stack and output nothing. For each Pop or PeekMedian command, print in a line the corresponding returned value. If the command is invalid, print "Invalid" instead.

Sample Input:
17
Pop
PeekMedian
Push 3
PeekMedian
Push 2
PeekMedian
Push 1
PeekMedian
Pop
Pop
Push 5
Push 4
PeekMedian
Pop
Pop
Pop
Pop
Sample Output:
Invalid
Invalid
3
2
2
1
2
4
4
5
3
Invalid*/

#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;

const int maxn = 100010;
const int INF = 0xfffffff;
const int sqrN=316;

stack<int> st;
int block[sqrN];
int table[maxn];

int PeeKMedian(int K) {
    int sum=0;
    int idx=0;
    while (sum+block[idx]<K){
        sum+=block[idx++];
    }
    int num=idx*sqrN;
    while(sum+table[num]<K){
        sum+=table[num++];
    }
    printf("%d\n", num);
}

void Push(int x){
    st.push(x);
    block[x/sqrN]++;
    table[x]++;
}

void Pop(){
    int x=st.top();
    st.pop();
    block[x/sqrN]--;
    table[x]--;
    printf("%d\n", x);
}

int main() {
    // freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

   int x,query;
    memset(block,0, sizeof(block));
    memset(table,0, sizeof(table));
    char cmd[20];
    scanf("%d", &query);
    for (int i = 0; i < query; ++i) {
        scanf("%s", cmd);
        if(strcmp(cmd,"Push")==0){
            scanf("%d", &x);
            Push(x);
        } else if(strcmp(cmd,"Pop")==0){
            if(st.empty()==true){
                printf("Invalid\n");
            } else{
                Pop();
            }
        } else{
            if(st.empty()==true){
                printf("Invalid\n");
            } else{
                int k=st.size();
                if(k%2==1)  k=(k+1)/2;
                else k=k/2;
                PeeKMedian(k);
            }
        }
    }

    return 0;
}
