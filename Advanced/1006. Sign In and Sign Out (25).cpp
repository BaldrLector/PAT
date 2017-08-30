#include<cstdio>
#include <string>
#include <iostream>

using namespace std;
struct t {
    int hh, mm, ss;
};

bool earlier(t a, t b) {
    if (a.hh != b.hh)
        return a.hh < b.hh;
    else if (a.mm != b.mm)
        return a.mm < b.mm;
    else return a.ss < b.ss;
}

int main() {
 
    int n;
    scanf("%d", &n);
    string id;
    t come, leave, first, last;
    first.hh = first.mm = first.ss = 60;
    last.hh = last.mm = last.ss = 0;
    string firstone, lastone;
    for (int i = 0; i < n; i++) {
        cin >> id;
        scanf("%d:%d:%d %d:%d:%d", &come.hh, &come.mm, &come.ss, &leave.hh, &leave.mm, &leave.ss);
        if (earlier(come, first)) {
            first = come;
            firstone = id;
        }
        if (earlier(last, leave)) {
            last = leave;
            lastone = id;
        }
    }
    printf("%s %s", firstone.c_str(), lastone.c_str());
}
