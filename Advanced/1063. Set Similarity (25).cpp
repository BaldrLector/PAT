/*1063. Set Similarity (25)
时间限制
300 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Given two sets of integers, the similarity of the sets is defined to be Nc/Nt*100%, where Nc is the number of distinct common numbers shared by the two sets, and Nt is the total number of distinct numbers in the two sets. Your job is to calculate the similarity of any given pair of sets.

Input Specification:

Each input file contains one test case. Each case first gives a positive integer N (<=50) which is the total number of sets. Then N lines follow, each gives a set with a positive M (<=104) and followed by M integers in the range [0, 109]. After the input of sets, a positive integer K (<=2000) is given, followed by K lines of queries. Each query gives a pair of set numbers (the sets are numbered from 1 to N). All the numbers in a line are separated by a space.

Output Specification:

For each query, print in one line the similarity of the sets, in the percentage form accurate up to 1 decimal place.

Sample Input:
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3
Sample Output:
50.0%
33.3%*/

#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int maxn = 100010;
const int INF = 0xfffffff;

const int N=51;
set<int> st[N];

void compare(int x,int y){
    int totalNum=st[y].size(),sameNum=0;
    for(set<int>::iterator it=st[x].begin();it!=st[x].end();it++){
        if(st[y].find(*it)!=st[y].end()){
            sameNum++;
        } else{
            totalNum++;
        }
    }
    printf("%.1f%%\n", sameNum*100.0/totalNum);
}

int main() {
    // freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    int n,q,k,v,st1,st2;
    scanf("%d", &n);
    for (int i = 1; i <=n; ++i) {
        scanf("%d", &k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &v);
            st[i].insert(v);
        }
    }
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        scanf("%d%d", &st1, &st2);
        compare(st1,st2);
    }

    return 0;
}
