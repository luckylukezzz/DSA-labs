#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to find the vertex with the minimum key value
int findMinKey(const vector<int>& key, const vector<bool>& mstSet) {
    int minVal = INT_MAX;
    int minIndex;

    for (int v = 0; v < key.size(); v++) {
        if (!mstSet[v] && key[v] < minVal) {
            minVal = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to print the Minimum Spanning Tree
void printMST(const vector<int>& parent, const vector<vector<int>>& graph) {
    cout << "Minimum Spanning Tree:" << endl;
    cout << "Edge : Weight" << endl;
    for (int i = 1; i < parent.size(); i++) {
        cout << parent[i] << " => " << i << ": " << graph[i][parent[i]] << endl;
    }
}

// Function to find the MST using Prim's algorithm
void primMST(const vector<vector<int>>& graph, int startVertex) {
    int size = graph.size();
    vector<int> parent(size, -1); // Array to store the parent of each vertex in MST
    vector<int> key(size, INT_MAX); // Array to store the key values of vertices
    vector<bool> mstSet(size, false); // Array to track if a vertex is included in MST

    key[startVertex] = 0; // Start with the given startVertex
    parent[startVertex] = -1; // StartVertex has no parent

    // Construct the MST with size-1 edges
    for (int count = 0; count < size - 1; count++) {
        int u = findMinKey(key, mstSet); // Find the vertex with the minimum key value
        mstSet[u] = true; // Include the vertex in the MST

        // Update the key values and parent for adjacent vertices not yet included in MST
        for (int v = 0; v < size; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u; // Set u as the parent of v in MST
                key[v] = graph[u][v]; // Update the key value of v
            }
        }
    }

    printMST(parent, graph); // Print the Minimum Spanning Tree
}

int main() {
    vector<vector<int>> graph = {
        {0, 3, 0, 0, 0, 1},
        {3, 0, 2, 1, 10, 0},
        {0, 2, 0, 3, 0, 5},
        {0, 1, 3, 0, 5, 0},
        {0, 10, 0, 5, 0, 4},
        {1, 0, 5, 0, 4, 0}
    };

    int startVertex = 0; // Starting vertex for MST

    primMST(graph, startVertex); // Find the MST using Prim's algorithm

    return 0;
}
