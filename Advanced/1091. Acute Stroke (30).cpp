/*1091. Acute Stroke (30)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
One important factor to identify acute stroke (急性脑卒中) is the volume of the stroke core. Given the results of image analysis in which the core regions are identified in each MRI slice, your job is to calculate the volume of the stroke core.

Input Specification:

Each input file contains one test case. For each case, the first line contains 4 positive integers: M, N, L and T, where M and N are the sizes of each slice (i.e. pixels of a slice are in an M by N matrix, and the maximum resolution is 1286 by 128); L (<=60) is the number of slices of a brain; and T is the integer threshold (i.e. if the volume of a connected core is less than T, then that core must not be counted).

Then L slices are given. Each slice is represented by an M by N matrix of 0's and 1's, where 1 represents a pixel of stroke, and 0 means normal. Since the thickness of a slice is a constant, we only have to count the number of 1's to obtain the volume. However, there might be several separated core regions in a brain, and only those with their volumes no less than T are counted. Two pixels are "connected" and hence belong to the same region if they share a common side, as shown by Figure 1 where all the 6 red pixels are connected to the blue one.


Figure 1
Output Specification:

For each case, output in a line the total volume of the stroke core.

Sample Input:
3 4 5 2
1 1 1 1
1 1 1 1
1 1 1 1
0 0 1 1
0 0 1 1
0 0 1 1
1 0 1 1
0 1 0 0
0 0 0 0
1 0 1 1
0 0 0 0
0 0 0 0
0 0 0 1
0 0 0 1
1 0 0 0
Sample Output:
26*/

#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 100100;
const int INF = 1000000000;

 struct node{
     int x,y,z;
 }Node;

int n,m,slice,T;
int pixel[1290][130][61];
int inq[1290][130][61]={false};
int X[6]={0,0,0,0,1,-1};
int Y[6]={0,0,1,-1,0,0};
int Z[6]={1,-1,0,0,0,0};

//boundary
bool judge(int x,int y,int z){
    if(x>=n||x<0||y>=m||y<0||z>=slice||z<0){
        return false;
    }
    if(pixel[x][y][z]==0||inq[x][y][z]==true) return false;
    return true;
}

int BFS(int x,int y,int z){
    int tot=0;
    queue<node> Q;
    Node.x=x,Node.y=y,Node.z=z;
    Q.push(Node);
    inq[x][y][z]=true;
    while (!Q.empty()){
        node top=Q.front();
        Q.pop();
        tot++;
        for (int i = 0; i < 6; ++i) {
            int newX=top.x+X[i];
            int newY=top.y+Y[i];
            int newZ=top.z+Z[i];
            if(judge(newX,newY,newZ)){
                Node.x=newX,Node.y=newY,Node.z=newZ;
                Q.push(Node);
                inq[newX][newY][newZ]=true;
            }
        }
    }
    if(tot>=T) return tot;
    else return 0;
}

int main() {
    // freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    scanf("%d%d%d%d", &n, &m, &slice, &T);
    for(int z=0;z<slice;z++){
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < m; ++y) {
                scanf("%d", &pixel[x][y][z]);
            }
        }
    }
    int ans=0;
    for (int z = 0; z < slice; ++z) {
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < m; ++y) {
                if(pixel[x][y][z]==1&&inq[x][y][z]==false){
                    ans+=BFS(x,y,z);
                }
            }
        }
    }
    printf("%d", ans);

    return 0;
}

