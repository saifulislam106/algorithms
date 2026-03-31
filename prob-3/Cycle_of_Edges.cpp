#include <bits/stdc++.h>
using namespace std;

int parent[100005];

int find(int node) {
    if (parent[node] == node) return node;


    int leader = find(parent[node]);
    parent[node] = leader;
    return leader;
}

void dsu_union(int a, int b) {
    int leaderA = find(a);
    int leaderB = find(b);

    if (leaderA != leaderB) {
        parent[leaderA] = leaderB;
    }
}

int main() {
    memset(parent, -1, sizeof(parent));
    int n, e;
    cin >> n >> e;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int cycleCount = 0;

    while (e--) {
        int u, v;
        cin >> u >> v;

        if (find(u) == find(v)) {
            cycleCount++; 
        } else {
            dsu_union(u, v);
        }
    }

    cout << cycleCount << endl;

    return 0;
}