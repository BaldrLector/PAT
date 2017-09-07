#include<cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 2010;
struct record {
    char name[25];
    int month, dd, hh, mm;
    bool state;
} r[maxn], temp;
int toll[25] = {0};

bool cmp(record a, record b) {
    if (strcmp(a.name, b.name) != 0) {
        return strcmp(a.name, b.name) < 0;
    } else if (a.month != b.month) {
        return a.month < b.month;
    } else if (a.dd != b.dd) {
        a.dd < b.dd;
    } else if (a.hh != b.hh) {
        a.hh < b.hh;
    } else return a.mm < b.mm;
}

void get_ans(int on, int off, int &time, int &money) {
    temp = r[on];
    while (temp.dd < r[off].dd || temp.hh < r[off].hh || temp.mm < r[off].mm) {
        time++;
        money += toll[temp.hh];
        temp.mm++;
        if (temp.mm >= 60) {
            temp.hh++;
            temp.mm = 0;
        }
        if (temp.hh >= 24) {
            temp.dd++;
            temp.hh = 0;
        }
    }
}

int main() {
    freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);
    for (int i = 0; i < 24; i++) {
        scanf("%d", &toll[i]);
    }
    int n;
    scanf("%d", &n);
    char state[20];
    for (int i = 0; i < n; i++) {
        scanf("%s %d:%d:%d:%d %s", r[i].name, &r[i].month, &r[i].dd, &r[i].hh, &r[i].mm, state);
        if (strcmp(state, "on-line") == 0) {
            r[i].state = true;
        } else {
            r[i].state = false;
        }
    }
    sort(r, r + n, cmp);
    int on = 0, off, next;
    while (on < n) {
        int needPrint = 0;
        next = on;
        while (next < n && strcmp(r[next].name, r[on].name) == 0) {
            if (needPrint == 0 && r[next].state == true) {
                needPrint = 1;
            } else if (needPrint == 1 && r[next].state == false) {
                needPrint = 2;
            }
            next++;
        }
        if (needPrint < 2) {
            on = next;
            continue;
        }
        int Allmoney = 0;
        printf("%s %02d\n", r[on].name, r[on].month);
        while (on < next) {
            while (on < next - 1 && !(r[on].state == true && r[on + 1].state == false)) {
                on++;
            }
            off = on + 1;
            if (off == next) {
                on = next;
                break;
            }
            printf("%02d:%02d:%02d ", r[on].dd, r[on].hh, r[on].mm);
            printf("%02d:%02d:%02d ", r[off].dd, r[off].hh, r[off].mm);
            int time = 0, money = 0;
            get_ans(on, off, time, money);
            Allmoney += money;
            printf("%d $%2.f\n", time, money / 100.0);
            on = off + 1;
        }
        printf("Total amount: &%.2f\n", Allmoney / 100.0);
    }

    return 0;
}
