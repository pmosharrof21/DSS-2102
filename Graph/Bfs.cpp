#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int startNode, const vector<vector<int>>& adj) {
    int numVertices = adj.size();
    vector<bool> visited(numVertices, false);
    queue<int> q;

    visited[startNode] = true;
    q.push(startNode);

    cout << "BFS Traversal starting from node " << startNode << ":\n";

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();

        cout << currentNode << " ";


        for (int neighbor : adj[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    int numVertices;
    int numEdges;

    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<int>> adj(numVertices);

    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);

    }

    int startNode;
    cout << "Enter the starting node for BFS: ";
    cin >> startNode;

    bfs(startNode, adj);

    return 0;
}
