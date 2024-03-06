#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 24;
const int INF = 1e9;

int n, k;
int c[MAXN][MAXN];
int dp[1 << 11][1 << 11][11]; // Use 3D dp to store state: picked-up passengers, dropped-off passengers, and current bus position

int dfs(int picked, int dropped, int pos) {
    if (dropped == (1 << n) - 1) return c[pos][0]; // if all passengers dropped
    
    int &ans = dp[picked][dropped][pos];
    if (ans != -1) return ans;

    ans = INF;

    // pick up passengers if the bus has space and the passenger is not picked
    for (int i = 0; i < n && __builtin_popcount(picked) - __builtin_popcount(dropped) < k; i++) {
        if (!(picked & (1 << i))) {
            ans = min(ans, c[pos][i + 1] + dfs(picked | (1 << i), dropped, i + 1));
        }
    }

    // drop off passengers if they're on the bus and not yet dropped
    for (int i = 0; i < n; i++) {
        if ((picked & (1 << i)) && !(dropped & (1 << i))) {
            ans = min(ans, c[pos][i + n + 1] + dfs(picked, dropped | (1 << i), i + n + 1));
        }
    }

    return ans;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < 2 * n + 1; i++) {
        for (int j = 0; j < 2 * n + 1; j++) {
            cin >> c[i][j];
        }
    }

    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < (1 << n); j++) {
            for (int l = 0; l < 2 * n + 1; l++) {
                dp[i][j][l] = -1;
            }
        }
    }

    cout << dfs(0, 0, 0) << endl;

    return 0;
}
