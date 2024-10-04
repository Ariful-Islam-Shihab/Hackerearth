#include<bits/stdc++.h>
using namespace std;

class Edge {
public:
    int u, v, c;
    Edge(int u, int v, int c) {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

int BellmanFord(int V, vector<Edge> &edgeList, int source, int destination) {
    vector<int> dis(V + 1, INT_MAX);
    dis[source] = 0;
    
    // Relax all edges V-1 times
    for(int i = 0; i < V - 1; i++) {
        bool relaxed = false; // Add a flag to check if any relaxation occurred
        for(Edge x : edgeList) {
            if(dis[x.u] != INT_MAX && dis[x.u] + x.c < dis[x.v]) {
                dis[x.v] = dis[x.u] + x.c;
                relaxed = true;
            }
        }
        // If no relaxation happened, exit early
        if(!relaxed) break;
    }

    // Check for negative-weight cycles
    for(Edge x : edgeList) {
        if(dis[x.u] != INT_MAX && dis[x.u] + x.c < dis[x.v]) {
            return -1; // Negative cycle detected
        }
    }

    return dis[destination] == INT_MAX ? -1 : dis[destination];
}

int main() {
    int V, E;
    cin >> V >> E;

    int source, destination;
    cin >> source >> destination;
    vector<Edge> edgeList;
    for(int i = 0; i < E; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        edgeList.push_back(Edge(u, v, c));  // Directed edge u -> v with cost c
    }


    // Bellman-Ford for source -> destination
    int x = BellmanFord(V, edgeList, source, destination);

    // Bellman-Ford for destination -> source
    int y = BellmanFord(V, edgeList, destination, source);

    // Check if any of the paths don't exist or negative cycle is detected
    if(x == -1 || y == -1) {
        cout << "-1" << endl;
    } else {
        cout << x + y << endl; // Return the round-trip cost
    }

    return 0;
}
