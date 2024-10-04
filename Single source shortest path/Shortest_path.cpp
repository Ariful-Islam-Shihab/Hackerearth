#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int u, v;
    long long int c;
    Edge(int u, int v, long long int c) {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

long long int BellmanFord(int V, vector<Edge> &edgeList, int source = 1) {
    vector<long long int> dis(V + 1, LLONG_MAX);
    dis[source] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        bool relaxed = false; // Flag to check if any relaxation occurred
        for (Edge x : edgeList) {
            if (dis[x.u] != LLONG_MAX && dis[x.u] + x.c < dis[x.v]) {
                dis[x.v] = dis[x.u] + x.c;
                relaxed = true;
            }
        }
        // If no relaxation happened, exit early
        if (!relaxed) break;
    }

    // Check for negative-weight cycles
    for (Edge x : edgeList) {
        if (dis[x.u] != LLONG_MAX && dis[x.u] + x.c < dis[x.v]) {
            return -1; // Negative cycle detected
        }
    }

    return dis[V] == LLONG_MAX ? -1 : dis[V];
}

int main() {
    int T;
    cin >> T; // Number of test cases
    while (T--) {
        int V, E;
        cin >> V >> E; // Read vertices and edges count
        vector<Edge> edgeList;

        // Read edges
        for (int i = 0; i < E; i++) {
            int u, v;
            long long int w;
            cin >> u >> v >> w; // Read edge from u to v with weight w
            // Check valid vertex indices
            if (u >= 1 && u <= V && v >= 1 && v <= V) {
                edgeList.push_back(Edge(u, v, w));
            } else {
                cout << "Invalid edge: " << u << " -> " << v << endl;
            }
        }
        for(int i = 2; i <= V ; i++)
            edgeList.push_back(Edge(i,i-1,0));
        long long int result = BellmanFord(V, edgeList);
        cout << result << endl; // Output the result for each test case
    }
    return 0;
}
