#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V; // จำนวน vertices
    vector<vector<pair<int,int>>> adj; // adjacency list (vertex, weight)

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        if (u >= 0 && u < V && v >= 0 && v < V) {
            adj[u].push_back({v, w});
        }
    }

    void DFSUtil(int v, vector<bool> &visited) {
        visited[v] = true;
        cout << v << " ";
        for (auto &p : adj[v]) {
            int next = p.first;
            if (!visited[next])
                DFSUtil(next, visited);
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
        cout << endl;
    }

    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";
            for (auto &p : adj[u]) {
                int next = p.first;
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
    cin.tie(nullptr);

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
            traversalMode = true; // หลังจากนี้ห้ามเพิ่ม edge/vertex
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
