#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int a, b, w;

    Edge(int a, int b, int w) {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

long long dist[1005];
vector<Edge> edge_list;
int n, e;

bool bellman_ford(int s) {
    for (int i = 1; i <= n; i++) {
        dist[i] = LLONG_MAX;
    }
    dist[s] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (auto ed : edge_list) {
            int a = ed.a;
            int b = ed.b;
            int w = ed.w;

            if (dist[a] != LLONG_MAX && dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
            }
        }
    }

    for (auto ed : edge_list) {
        int a = ed.a;
        int b = ed.b;
        int w = ed.w;

        if (dist[a] != LLONG_MAX && dist[a] + w < dist[b]) {
            return true;
        }
    }

    return false;
}

int main() {
    cin >> n >> e;

    while (e--) {
        int a, b, w;
        cin >> a >> b >> w;
        edge_list.push_back(Edge(a, b, w));
    }

    int s;
    cin >> s;

    if (bellman_ford(s)) {
        cout << "Negative Cycle Detected" << endl;
        return 0;
    } 

    int t;
    cin >> t;

    while (t--) {
        int d;
        cin >> d;

        if (dist[d] == LLONG_MAX) {
            cout << "Not Possible" << endl;
        } else {
            cout << dist[d] << endl;
        }
    }

    return 0;
}