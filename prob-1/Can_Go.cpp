#include <bits/stdc++.h>
using namespace std;

char grid[105][105];
bool vis[105][105];
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};
int n, m;
bool found = false;

bool valid(int i, int j) {
    return !(i < 0 || j < 0 || i >= n || j >= m);
}

void dfs(int si, int sj) {
    if (found) return;

    vis[si][sj] = true;

    if (grid[si][sj] == 'B') {
        found = true;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != '#') {
            dfs(ci, cj);
        }
    }
}

int main() {
    cin >> n >> m;

    int si = -1, sj = -1;

    for (int i = 0; i < n; i++) {
        cin >> grid[i]; 
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                si = i;
                sj = j;
            }
        }
    }

    if (si == -1) {
        cout << "NO";
        return 0;
    }

    memset(vis, false, sizeof(vis));

    dfs(si, sj);

    cout << (found ? "YES" : "NO");
}