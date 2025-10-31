/*
* C++ Solution for "Detect Cycle in an Undirected Graph"
*
* This algorithm uses a Disjoint Set Union (DSU) data structure,
* also known as Union-Find.
*
* We iterate through each edge (u, v) in the graph.
* For each edge, we find the "parents" (representatives) of u and v.
* - If the parents are the same, it means u and v are already
* in the same set, and adding this edge creates a cycle.
* - If the parents are different, we "union" the two sets.
*
* Contributor: Priyanka Anand
* Submitted for Hacktoberfest 2025
*/

#include <iostream>
#include <vector>
#include <numeric> // For std::iota

// A structure to represent a Disjoint Set Union (DSU)
struct DSU {
    std::vector<int> parent;

    // Constructor
    DSU(int n) {
        parent.resize(n);
        // Initialize all elements to be their own parents
        std::iota(parent.begin(), parent.end(), 0); 
    }

    // Find the representative (root) of the set containing element i
    int find(int i) {
        if (parent[i] == i)
            return i;
        // Path compression
        return parent[i] = find(parent[i]); 
    }

    // Perform union of two sets x and y
    void unite(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        if (root_x != root_y) {
            parent[root_x] = root_y;
        }
    }
};

// A structure to represent an undirected graph
class Graph {
    int V; // Number of vertices
    std::vector<std::pair<int, int>> edges; // List of edges

public:
    Graph(int V) {
        this->V = V;
    }

    void addEdge(int u, int v) {
        edges.push_back({u, v});
    }

    // The main function to check if the graph contains a cycle
    bool isCyclic() {
        DSU dsu(V);

        // Iterate through all edges
        for (auto& edge : edges) {
            int u = edge.first;
            int v = edge.second;

            int parent_u = dsu.find(u);
            int parent_v = dsu.find(v);

            // If both vertices are already in the same set,
            // adding this edge creates a cycle.
            if (parent_u == parent_v) {
                return true;
            }

            // Otherwise, perform union
            dsu.unite(u, v);
        }
        return false;
    }
};

// Main function to test the implementation
int main() {
    // Create a graph with 3 vertices and 3 edges
    Graph g1(3);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(0, 2); // This edge creates a cycle 0-1-2-0

    if (g1.isCyclic())
        std::cout << "Test Case 1: Graph contains a cycle (Expected: Yes)" << std::endl;
    else
        std::cout << "Test Case 1: Graph doesn't contain a cycle (Expected: Yes)" << std::endl;

    // Create a graph without a cycle
    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);

    if (g2.isCyclic())
        std::cout << "Test Case 2: Graph contains a cycle (Expected: No)" << std::endl;
    else
        std::cout << "Test Case 2: Graph doesn't contain a cycle (Expected: No)" << std::endl;

    return 0;
}