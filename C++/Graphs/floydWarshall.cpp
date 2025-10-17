/*
        Floyd-Warshall algorithm Simulator for finding the shortest path between all pairs of 
        nodes in a weighted graph. This algorithm works for both directed and undirected 
        graphs and can handle negative weights, but it assumes there are no negative weight 
        cycles.
 */

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Graph {
public:
    Graph(int nodes);
    void addEdge(int u, int v, int weight);
    void floydWarshall();
    void printShortestDistance(int u, int v);
    void printShortestPath(int u, int v);
    
private:
    int numNodes;
    vector<vector<int>> distance;
    vector<vector<int>> next; // For path reconstruction
    const int INF = numeric_limits<int>::max();

    void initializeGraph();
};

// Graph constructor
Graph::Graph(int nodes) : numNodes(nodes) {
    initializeGraph();
}

// Initialize the distance and next matrices
void Graph::initializeGraph() {
    distance.resize(numNodes, vector<int>(numNodes, INF));
    next.resize(numNodes, vector<int>(numNodes, -1));

    for (int i = 0; i < numNodes; ++i) {
        distance[i][i] = 0;
        next[i][i] = i;
    }
}

// Add an edge to the graph
void Graph::addEdge(int u, int v, int weight) {
    distance[u][v] = weight;
    next[u][v] = v; // For reconstructing the path
}

// Floyd-Warshall algorithm
void Graph::floydWarshall() {
    for (int k = 0; k < numNodes; ++k) {
        for (int i = 0; i < numNodes; ++i) {
            for (int j = 0; j < numNodes; ++j) {
                if (distance[i][k] != INF && distance[k][j] != INF &&
                    distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

// Print the shortest distance between two nodes
void Graph::printShortestDistance(int u, int v) {
    if (distance[u][v] == INF) {
        cout << "No path from node " << u << " to node " << v << endl;
    } else {
        cout << "Shortest distance from node " << u << " to node " << v << ": " << distance[u][v] << endl;
    }
}

// Print the shortest path between two nodes
void Graph::printShortestPath(int u, int v) {
    if (next[u][v] == -1) {
        cout << "No path from node " << u << " to node " << v << endl;
        return;
    }

    vector<int> path;
    for (int at = u; at != v; at = next[at][v]) {
        if (at == -1) {
            cout << "No path from node " << u << " to node " << v << endl;
            return;
        }
        path.push_back(at);
    }
    path.push_back(v);

    cout << "Shortest path from node " << u << " to node " << v << ": ";
    for (int i = 0; i < path.size(); ++i) {
        cout << path[i] << (i + 1 < path.size() ? " -> " : "\n");
    }
}

// Main function
int main() {
    int numNodes;
    cout << "Enter the number of nodes in the graph: ";
    cin >> numNodes;

    Graph graph(numNodes);

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add edge\n";
        cout << "2. Compute shortest distances (Floyd-Warshall)\n";
        cout << "3. Print shortest distance between two nodes\n";
        cout << "4. Print shortest path between two nodes\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int u, v, weight;
                cout << "Enter edge (u v weight): ";
                cin >> u >> v >> weight;
                graph.addEdge(u, v, weight);
                break;
            }
            case 2: {
                graph.floydWarshall();
                cout << "Floyd-Warshall algorithm executed.\n";
                break;
            }
            case 3: {
                int u, v;
                cout << "Enter source and destination nodes: ";
                cin >> u >> v;
                graph.printShortestDistance(u, v);
                break;
            }
            case 4: {
                int u, v;
                cout << "Enter source and destination nodes: ";
                cin >> u >> v;
                graph.printShortestPath(u, v);
                break;
            }
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
