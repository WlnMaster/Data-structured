#include <iostream>
#include <queue>
#include <string>
using namespace std;

const int MAXV = 100;

struct Edge {
    int to, weight;
};

class Graph {
    int V;
    Edge adj[MAXV][MAXV];
    int deg[MAXV];

public:
    Graph(int V) {
        this->V = V;
        for (int i = 0; i < V; i++) deg[i] = 0;
    }

    void addEdge(int u, int v, int w) {
        if (u >= 0 && u < V && v >= 0 && v < V && deg[u] < MAXV) {
            adj[u][deg[u]].to = v;
            adj[u][deg[u]].weight = w;
            deg[u]++;
        }
    }

    void DFSUtil(int v, bool visited[]) {
        visited[v] = true;
        cout << v << " ";
        for (int i = 0; i < deg[v]; i++) {
            int next = adj[v][i].to;
            if (!visited[next]) DFSUtil(next, visited);
        }
    }

    void DFS(int start) {
        bool visited[MAXV];
        for (int i = 0; i < V; i++) visited[i] = false;
        DFSUtil(start, visited);
        cout << endl;
    }

    void BFS(int start) {
        bool visited[MAXV];
        for (int i = 0; i < V; i++) visited[i] = false;
        queue<int> q;
        visited[start] = true;
        q.push(start);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";
            for (int i = 0; i < deg[u]; i++) {
                int next = adj[u][i].to;
                if (!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int V;
    cin >> V;
    Graph g(V);
    string cmd;
    bool traversalMode = false;
    while (cin >> cmd) {
        if (cmd == "e" && !traversalMode) {
            int u, v, w;
            cin >> u >> v >> w;
            g.addEdge(u, v, w);
        }
        else if (cmd == "s") {
            traversalMode = true;
        }
        else if (cmd == "d" && traversalMode) {
            int start;
            cin >> start;
            g.DFS(start);
        }
        else if (cmd == "b" && traversalMode) {
            int start;
            cin >> start;
            g.BFS(start);
        }
        else if (cmd == "q") {
            break;
        }
    }
    return 0;
}