/*1089. Insert or Merge (25)
时间限制
200 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
According to Wikipedia:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list. Each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. It repeats until no input elements remain.

Merge sort works as follows: Divide the unsorted list into N sublists, each containing 1 element (a list of 1 element is considered sorted). Then repeatedly merge two adjacent sublists to produce new sorted sublists until there is only 1 sublist remaining.

Now given the initial sequence of integers, together with a sequence which is a result of several iterations of some sorting method, can you tell which sorting method we are using?

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=100). Then in the next line, N integers are given as the initial sequence. The last line contains the partially sorted sequence of the N numbers. It is assumed that the target sequence is always ascending. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in the first line either "Insertion Sort" or "Merge Sort" to indicate the method used to obtain the partial result. Then run this method for one more iteration and output in the second line the resulting sequence. It is guaranteed that the answer is unique for each test case. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

Sample Input 1:
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
Sample Output 1:
Insertion Sort
1 2 3 5 7 8 9 4 6 0
Sample Input 2:
10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
Sample Output 2:
Merge Sort
1 2 3 8 4 5 7 9 0 6*/

#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 210;
const int INF = 1000000000;

const int N=111;
int origin[N],tempOri[N],changed[N];
int n;

bool isSame(int a[],int b[]){
    for (int i = 0; i < n; ++i) {
        if(a[i]!=b[i]){
            return false;
        }
    }
    return true;
}

bool showArray(int a[]){
    for (int i = 0; i < n; ++i) {
        printf("%d", a[i]);
        if(i!=n-1)  printf(" ");
    }
    printf("\n");
}

bool insertSort(){
    bool flag=false;
    for (int i = 1; i < n; ++i) {
        if(i!=1&&isSame(tempOri,changed)){
            flag=true;
        }
        int tmep=tempOri[i],j=i;
        while (j>0&&tempOri[j-1]>tmep){
            tempOri[j]=tempOri[j-1];
            j--;
        }
        tempOri[j]=tmep;
        if(flag==true){
            return true;
        }
    }
    return false;
}

void mergeSort(){
    bool flag=false;
    for(int step=2;step/2<=n;step*=2){
        if(step!=2&&isSame(tempOri,changed)){
            flag=true;
        }
        for (int i = 0; i < n; i+=step) {
            sort(tempOri+i,tempOri+min(i+step,n));
        }
        if(flag==true){
            showArray(tempOri);
            return;
        }
    }
}

int main() {
    // freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", & origin[i]);
        tempOri[i]=origin[i];
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &changed[i]);
    }
    if(insertSort()){
        printf("Insertion Sort\n");
        showArray(tempOri);
    } else{
        printf("Merge Sort\n");
        for (int i = 0; i < n; ++i) {
            tempOri[i]=origin[i];
        }
        mergeSort();
    }

    return 0;
}

