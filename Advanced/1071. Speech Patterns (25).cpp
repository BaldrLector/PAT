/*1071. Speech Patterns (25)
时间限制
300 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
HOU, Qiming
People often have a preference among synonyms of the same word. For example, some may prefer "the police", while others may prefer "the cops". Analyzing such patterns can help to narrow down a speaker's identity, which is useful when validating, for example, whether it's still the same person behind an online avatar.

Now given a paragraph of text sampled from someone's speech, can you find the person's most commonly used word?

Input Specification:

Each input file contains one test case. For each case, there is one line of text no more than 1048576 characters in length, terminated by a carriage return '\n'. The input contains at least one alphanumerical character, i.e., one character from the set [0-9 A-Z a-z].

Output Specification:

For each test case, print in one line the most commonly occurring word in the input text, followed by a space and the number of times it has occurred in the input. If there are more than one such words, print the lexicographically smallest one. The word should be printed in all lower case. Here a "word" is defined as a continuous sequence of alphanumerical characters separated by non-alphanumerical characters or the line beginning/end.

Note that words are case insensitive.

Sample Input:
Can1: "Can a can can a can?  It can!"
Sample Output:
can 5
*/
*
#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>

using namespace std;

const int maxn = 100010;
const int INF = 0xfffffff;

bool check(char c){
    if(c>='0'&&c<='9') return true;
    if(c>='A'&&c<='Z') return true;
    if(c>='a'&&c<='z') return true;
    return false;
}

int main() {
    // freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);

    map<string,int> count;
    string str;
    getline(cin,str);
    int i=0;
    while (i<str.length()){
        string word;
        while (i<str.length()&&check(str[i])==true){
            if(str[i]>='A'&&str[i]<='Z'){
                str[i]+=32;
            }
            word+=str[i];
            i++;
        }
        if(word!=""){
            if(count.find(word)==count.end())   count[word]=1;
            else count[word]++;
        }
        while (i<str.length()&&check(str[i])==false){
            i++;
        }
    }
    string ans;
    int MAX=0;
    for(map<string,int>::iterator it=count.begin();it!=count.end();it++){
        if(it->second>MAX){
            MAX=it->second;
            ans=it->first;
        }
    }
    cout<<ans<<" "<<MAX<<endl;


    return 0;
}

