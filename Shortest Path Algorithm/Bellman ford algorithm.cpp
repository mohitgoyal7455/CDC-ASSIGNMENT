#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000000;

struct Edge {
    int a, b, cost;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].a >> edges[i].b >> edges[i].cost;
    }

    int v, t;
    cin >> v >> t;

    vector<int> d(n, INF);
    d[v] = 0;
    vector<int> p(n, -1);

    for (;;) {
        bool any = false;
        for (Edge e : edges) {
            if (d[e.a] < INF && d[e.b] > d[e.a] + e.cost) {
                d[e.b] = d[e.a] + e.cost;
                p[e.b] = e.a;
                any = true;
            }
        }
        if (!any) break;
    }

    if (d[t] == INF) {
        cout << "No path from " << v << " to " << t << "." << endl;
    } else {
        vector<int> path;
        for (int cur = t; cur != -1; cur = p[cur])
            path.push_back(cur);
        reverse(path.begin(), path.end());

        cout << "Path from " << v << " to " << t << ": ";
        for (int u : path)
            cout << u << ' ';
        cout << endl;

        cout << "Distance: " << d[t] << endl;
    }

    return 0;
}
