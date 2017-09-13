/*1100. Mars Numbers (20)
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
People on Mars count their numbers with base 13:

Zero on Earth is called "tret" on Mars.
The numbers 1 to 12 on Earch is called "jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec" on Mars, respectively.
For the next higher digit, Mars people name the 12 numbers as "tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou", respectively.
For examples, the number 29 on Earth is called "hel mar" on Mars; and "elo nov" on Mars corresponds to 115 on Earth. In order to help communication between people from these two planets, you are supposed to write a program for mutual translation between Earth and Mars number systems.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (< 100). Then N lines follow, each contains a number in [0, 169), given either in the form of an Earth number, or that of Mars.

Output Specification:

For each number, print in a line the corresponding number in the other language.

Sample Input:
4
29
5
elo nov
tam
Sample Output:
hel mar
may
115
13
*/

#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

const int maxn = 100011;

string unitDigit[13]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string tenDigit[13]={"tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
string numTostr[170];
map<string,int> strTonum;

void init(){
    for (int i = 0; i < 13; ++i) {
        numTostr[i]=unitDigit[i];
        strTonum[unitDigit[i]]=i;
        numTostr[i*13]=tenDigit[i];
        strTonum[tenDigit[i]]=i*13;
    }
    for(int i=1;i<13;i++){
        for(int j=1;j<13;j++){
            string str=tenDigit[i]+" "+unitDigit[j];
            numTostr[i*13+j]=str;
            strTonum[str]=i*13+j;
        }
    }
}

int main() {
    // freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    init();
    int T;
    scanf("%d%*c", &T);
    while (T--){
        string str;
        getline(cin,str);
        if(str[0]>='0'&&str[0]<='9'){
            int num=0;
            for (int i = 0; i < str.length(); ++i) {
                num=num*10+(str[i]-'0');
            }
            cout<<numTostr[num]<<endl;
        } else{
            cout<<strTonum[str]<<endl;
        }
    }
    

    return 0;
}

