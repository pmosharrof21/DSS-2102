#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

struct Edge {
    int source;
    int destination;
    int weight;
};

int main() {
    int numVertices;
    int numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;
    vector<Edge> edges(numEdges);
    cout << "Enter the edges (source destination weight):\n";
    for (int i = 0; i < numEdges; ++i) {
        cin >> edges[i].source >> edges[i].destination >> edges[i].weight;
    }
    int sourceVertex;
    cout << "Enter the source vertex: ";
    cin >> sourceVertex;
    vector<int> distances(numVertices, INT_MAX);
    distances[sourceVertex] = 0;
    for (int i = 1; i <= numVertices - 1; ++i) {
        for (int j = 0; j < numEdges; ++j) {
            int u = edges[j].source;
            int v = edges[j].destination;
            int weight = edges[j].weight;
            if (distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
            }
        }
    }
    for (int j = 0; j < numEdges; ++j) {
        int u = edges[j].source;
        int v = edges[j].destination;
        int weight = edges[j].weight;
        if (distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
            cout << "Graph contains negative cycle" << endl;
            return 0;
        }
    }
    cout << "Shortest distances from source vertex " << sourceVertex << ":\n";
    for (int i = 0; i < numVertices; ++i) {
        if (distances[i] == INT_MAX) {
            cout << "Vertex " << i << ": Infinity" << endl;
        } else {
            cout << "Vertex " << i << ": " << distances[i] << endl;
        }
    }
    return 0;
}
