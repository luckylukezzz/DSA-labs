#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findMinimumKey(const vector<int>& keyValues, const vector<bool>& mstSet) {
    int minValue = INT_MAX;
    int minIndex;

    for (int v = 0; v < keyValues.size(); v++) {
        if (!mstSet[v] && keyValues[v] < minValue) {
            minValue = keyValues[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printMinimumSpanningTree(const vector<int>& parentIndices, const vector<vector<int>>& graph) {
    cout << "Minimum Spanning Tree:" << endl;
    cout << "Edge  => Weight" << endl;
    for (int i = 1; i < parentIndices.size(); i++) {
        cout << parentIndices[i] << " to " << i << "=> " << graph[i][parentIndices[i]] << endl;
    }
}

void buildMinimumSpanningTree(const vector<vector<int>>& adjacencyMatrix) {
    int size = adjacencyMatrix.size();
    vector<int> parentIndices(size);
    vector<bool> mstSet(size, false);
    vector<int> keyValues(size, INT_MAX);

    keyValues[0] = 0; // Start with the first vertex

    for (int count = 0; count < size - 1; count++) {
        int u = findMinimumKey(keyValues, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < size; v++) {
            if (adjacencyMatrix[u][v] && !mstSet[v] && adjacencyMatrix[u][v] < keyValues[v]) {
                parentIndices[v] = u;
                keyValues[v] = adjacencyMatrix[u][v];
            }
        }
    }

    printMinimumSpanningTree(parentIndices, adjacencyMatrix);
}

int main() {
    vector<vector<int>> adjacencyMatrix = {
        {0, 3, 0, 0, 0, 1},
        {3, 0, 2, 1, 10, 0},
        {0, 2, 0, 3, 0, 5},
        {0, 1, 3, 0, 5, 0},
        {0, 10, 0, 5, 0, 4},
        {1, 0, 5, 0, 4, 0}
    };

    buildMinimumSpanningTree(adjacencyMatrix);

    return 0;
}
