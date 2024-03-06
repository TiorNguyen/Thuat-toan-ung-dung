#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 60;
const int INF = 1e9;

int m, n, conflictCount;
vector<int> teacherCourses[11]; // preference list of teachers
vector<pair<int, int>> conflicts;

int cap[MAXN][MAXN], flow[MAXN][MAXN];
vector<int> adj[MAXN];
int pred[MAXN];

bool bfs(int s, int t) {
    memset(pred, -1, sizeof(pred));
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int next : adj[cur]) {
            if (pred[next] == -1 && cap[cur][next] - flow[cur][next] > 0) {
                pred[next] = cur;
                if (next == t) return true;
                q.push(next);
            }
        }
    }
    return false;
}

int fordFulkerson(int s, int t) {
    int maxFlow = 0;
    while (bfs(s, t)) {
        int pathFlow = INF;
        for (int v = t; v != s; v = pred[v]) {
            int u = pred[v];
            pathFlow = min(pathFlow, cap[u][v] - flow[u][v]);
        }
        for (int v = t; v != s; v = pred[v]) {
            int u = pred[v];
            flow[u][v] += pathFlow;
            flow[v][u] -= pathFlow;
        }
        maxFlow += pathFlow;
    }
    return maxFlow;
}

bool canDistribute(int mid) {
    memset(cap, 0, sizeof(cap));
    memset(flow, 0, sizeof(flow));
    for (int i = 0; i < MAXN; i++) adj[i].clear();

    int s = 0, t = m + n + 1;

    // Connect source to teachers
    for (int i = 1; i <= m; i++) {
        cap[s][i] = mid;
        adj[s].push_back(i);
        adj[i].push_back(s);
    }

    // Connect teachers to courses
    for (int i = 1; i <= m; i++) {
        for (int course : teacherCourses[i]) {
            cap[i][m + course] = 1;
            adj[i].push_back(m + course);
            adj[m + course].push_back(i);
        }
    }

    // Connect courses to sink
    for (int i = 1; i <= n; i++) {
        cap[m + i][t] = 1;
        adj[m + i].push_back(t);
        adj[t].push_back(m + i);
    }

    return fordFulkerson(s, t) == n;
}

int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        int k, course;
        cin >> k;
        while (k--) {
            cin >> course;
            teacherCourses[i].push_back(course);
        }
    }
    cin >> conflictCount;
    while (conflictCount--) {
        int a, b;
        cin >> a >> b;
        conflicts.push_back({a, b});
    }

    int l = 1, r = n, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (canDistribute(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << (ans == -1 ? -1 : ans) << endl;

    return 0;
}
