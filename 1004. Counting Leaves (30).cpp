#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;

const int maxn = 10010;

int ans[maxn] = {0}, maxHeitgh = 0;
struct Node {
    int level;
    vector<int> child;
} node[maxn];

void LevelTrave(int s) {
    queue<Node> q;
    node[s].level = 0;
    q.push(node[s]);
    while (!q.empty()) {
        Node temp = q.front();
        q.pop();
        if (temp.child.size() == 0) {
            ans[temp.level]++;
        }
        int nowLevel = temp.level;
        maxHeitgh = max(nowLevel, maxHeitgh);
        for (int i = 0; i < temp.child.size(); i++) {
            Node child = node[temp.child[i]];
            child.level = nowLevel + 1;
            q.push(child);
        }
    }
}

int main() {
    int id, k, child;
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &id, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &child);
            node[id].child.push_back(child);
        }
        node[id].level = -1;
    }
    LevelTrave(1);

    for (int i = 0; i <= maxHeitgh; i++) {
        printf("%d", ans[i]);
        if (i != maxHeitgh)
            printf(" ");
    }
    return 0;
}

