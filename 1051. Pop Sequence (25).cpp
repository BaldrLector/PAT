#include <cstdio>
#include <stack>

using namespace std;
const int maxn = 1100;

stack<int> st;
int arr[maxn];

int main() {
    freopen("C:\\Users\\71000\\CLionProjects\\demo\\data.in", "r", stdin);
    int m, n, k;
    scanf("%d%d%d", &m, &n, &k);
    while (k--) {
        while (!st.empty()) {
            st.pop();
        }
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &arr[i]);
        }
        bool flag = true;
        int current = 1;
        for (int i = 1; i <= n; i++) {
            st.push(i);
            if (st.size() > m) {
                flag = false;
                break;
            }
            while (!st.empty() && st.top() == arr[current]) {
                st.pop();
                current++;
            }
            while (!st.empty() && st.top() == arr[current]) {
                st.pop();
                current++;
            }
        }
        if(st.empty()==true&&flag==true){
            printf("YES\n");
        } else{
            printf("NO\n");
        }
    }

    return 0;
}
