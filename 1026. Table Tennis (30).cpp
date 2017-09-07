/*
1026. Table Tennis (30)

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
A table tennis club has N tables available to the public. The tables are numbered from 1 to N. For any pair of players, if there are some tables open when they arrive, they will be assigned to the available table with the smallest number. If all the tables are occupied, they will have to wait in a queue. It is assumed that every pair of players can play for at most 2 hours.

Your job is to count for everyone in queue their waiting time, and for each table the number of players it has served for the day.

One thing that makes this procedure a bit complicated is that the club reserves some tables for their VIP members. When a VIP table is open, the first VIP pair in the queue will have the priviledge to take it. However, if there is no VIP in the queue, the next pair of players can take it. On the other hand, if when it is the turn of a VIP pair, yet no VIP table is available, they can be assigned as any ordinary players.

Input Specification:

Each input file contains one test case. For each case, the first line contains an integer N (<=10000) - the total number of pairs of players. Then N lines follow, each contains 2 times and a VIP tag: HH:MM:SS - the arriving time, P - the playing time in minutes of a pair of players, and tag - which is 1 if they hold a VIP card, or 0 if not. It is guaranteed that the arriving time is between 08:00:00 and 21:00:00 while the club is open. It is assumed that no two customers arrives at the same time. Following the players' info, there are 2 positive integers: K (<=100) - the number of tables, and M (< K) - the number of VIP tables. The last line contains M table numbers.

Output Specification:

For each test case, first print the arriving time, serving time and the waiting time for each pair of players in the format shown by the sample. Then print in a line the number of players served by each table. Notice that the output must be listed in chronological order of the serving time. The waiting time must be rounded up to an integer minute(s). If one cannot get a table before the closing time, their information must NOT be printed.

Sample Input:
9
20:52:00 10 0
08:00:00 20 0
08:02:00 30 0
20:51:00 10 0
08:10:00 5 0
08:12:00 10 1
20:50:00 10 0
08:01:30 15 1
20:53:00 10 1
3 1
2
Sample Output:
08:00:00 08:00:00 0
08:01:30 08:01:30 0
08:02:00 08:02:00 0
08:12:00 08:16:30 5
08:10:00 08:20:00 10
20:50:00 20:50:00 0
20:51:00 20:51:00 0
20:52:00 20:52:00 0
3 3 2
*/

//未完成

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int K = 111;
const int INF = 100000000;

struct Player {
    int arriveTime, startTime, trainTime;
    bool isVip;
} newPlayer;

struct Table {
    int enTime, numServe;
    bool isVip;
} table[K];

vector<Player> player;

int covertTime(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
}

bool cmpArriveTime(Player a, Player b) {
    return a.arriveTime < b.arriveTime;
}

bool cmpStartTime(Player a, Player b) {
    return a.startTime < b.startTime;
}

int nextVipPlayer(int VIPi) {
    VIPi++;
    while (VIPi < player.size() && player[VIPi].isVip == 0) {
        VIPi++;
    }
    return VIPi;
}

void allotTable(int pid, int tid) {
    if (player[pid].arriveTime <= table[tid].enTime) {
        player[pid].startTime = table[tid].enTime;
    } else {
        player[pid].startTime = player[pid].arriveTime;
    }
    table[tid].enTime=player[pid].startTime+player[pid].trainTime;
    table[tid].numServe++;
}

int main() {
    freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);
    int k, m, n, VIPTable;
    scanf("%d", &n);
    int stTime = covertTime(8, 0, 0);
    int endTime = covertTime(21, 0, 0);
    for (int i = 0; i < n; i++) {
        int h, m, s, trainTime, isVIP;
        scanf("%d:%d:%d %d %d", &h, &m, &s, &trainTime, &isVIP);
        newPlayer.arriveTime = covertTime(h, m, s);
        newPlayer.startTime = endTime;
        if (newPlayer.arriveTime >= endTime) continue;
        newPlayer.trainTime=trainTime<=120?trainTime*60:7200;
        newPlayer.isVip = isVIP;
        player.push_back(newPlayer);
    }
    scanf("%d%d", &k, &m);
    for (int i = 1; i <=k; ++i) {
        table[i].enTime=stTime;
        table[i].numServe=table[i].isVip=0;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &VIPTable);
        table[VIPTable].isVip=1;
    }
    sort(player.begin(),player.end(),cmpArriveTime);
    int i=0,Vipi=-1;
    Vipi=nextVipPlayer(Vipi);
    while (i<player.size()){
        int idx=-1,minEndtime=INF;
        for (int j = 1; j <=k; ++j) {
            if(table[j].enTime<minEndtime){
                minEndtime=table[j].enTime;
                idx=j;
            }
        }
        if(table[idx].enTime>=endTime) break;
        if(player[i].isVip==1&&i<Vipi){
            i++;
            continue;
        }
        if(table[idx].isVip==1){
            if(player[i].isVip==1){
                allotTable(i,idx);
                if(Vipi==i) Vipi=nextVipPlayer(Vipi);
                i++;
            } else{
                if(Vipi<player.size()&&player[Vipi].arriveTime<=table[idx].enTime){
                    allotTable(Vipi,idx);
                    Vipi=nextVipPlayer(Vipi);
                } else{
                    allotTable(i,idx);
                    i++;
                }
            }
        } else{
            if(player[i].isVip==0){
                allotTable(i,idx);
                i++;
            } else{
                int VIPidx=-1,minVipEndTime=INF;
                for (int j = 1; j <=k; ++j) {
                    if(table[j].isVip==1&&table[j].enTime<minVipEndTime){
                        minVipEndTime=table[j].enTime;
                        VIPidx=j;
                    }
                }
                if(VIPidx!=-1&&player[i].arriveTime>=table[VIPidx].enTime){
                    allotTable(i,VIPidx);
                    if(Vipi==i) Vipi=nextVipPlayer(Vipi);
                    i++;
                } else{
                    allotTable(i,idx);
                    if(Vipi==1) Vipi=nextVipPlayer(Vipi);
                    i++;
                }
            }
        }
    }
    sort(player.begin(),player.end(),cmpStartTime);
    for (int i = 0; i < player.size()&&player[i].startTime<endTime; ++i) {
        int t1=player[i].arriveTime;
        int t2=player[i].startTime;
        printf("%02d:%02d:%02d ", t1/3600, t1%3600/60, t1%60);
        printf("%02d:%02d:%02d ", t2/3600, t2%3600/60, t2%60);
        printf("%.0f\n", round((t2-t1))/60.0);

    }

    for (int i = 1; i <=k; ++i) {
        printf("%d", table[i].numServe);
        if(i<k) printf(" ");
    }

    return 0;
}
