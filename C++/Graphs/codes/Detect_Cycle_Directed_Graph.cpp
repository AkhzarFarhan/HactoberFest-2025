/*
* C++ Solution for "Detect Cycle in a Directed Graph"
*
* This algorithm uses DFS to detect a cycle. It keeps track
* of visited nodes and nodes currently in the recursion stack.
* If a node is visited that is already in the recursion stack,
* a cycle (a back-edge) is found.
*
* Contributor: Priyanka Anand
* Submitted for Hacktoberfest 2025
*/

#include <iostream>
#include <vector>
#include <list>

class Graph {
    int V; // Number of vertices
    std::list<int>* adj; // Adjacency list

    // Recursive utility for DFS
    bool isCyclicUtil(int v, std::vector<bool>& visited, std::vector<bool>& recStack) {
        if (visited[v] == false) {
            // Mark the current node as visited and part of recursion stack
            visited[v] = true;
            recStack[v] = true;

            // Recur for all the vertices adjacent to this vertex
            for (int neighbor : adj[v]) {
                if (!visited[neighbor] && isCyclicUtil(neighbor, visited, recStack)) {
                    return true;
                } else if (recStack[neighbor]) {
                    // If the neighbor is in the recursion stack,
                    // then there is a cycle (back-edge).
                    return true;
                }
            }
        }
        recStack[v] = false; // Remove the vertex from recursion stack
        return false;
    }

public:
    Graph(int V) {
        this->V = V;
        adj = new std::list<int>[V];
    }

    ~Graph() {
        delete[] adj;
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w); // Add w to v’s list.
    }

    // Returns true if the graph contains a cycle, else false.
    bool isCyclic() {
        // Mark all the vertices as not visited and
        // not part of recursion stack
        std::vector<bool> visited(V, false);
        std::vector<bool> recStack(V, false);

        // Call the recursive helper function to detect
        // cycle in different DFS trees
        for (int i = 0; i < V; i++) {
            if (!visited[i] && isCyclicUtil(i, visited, recStack)) {
                return true;
            }
        }
        return false;
    }
};

// Main function to test the implementation
int main() {
    // Create a graph with 4 vertices
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0); // This edge creates a cycle 0-1-2-0
    g.addEdge(2, 3);
    g.addEdge(3, 3); // This edge creates a self-loop

    if (g.isCyclic())
        std::cout << "Test Case 1: Graph contains a cycle (Expected: Yes)" << std::endl;
    else
        std::cout << "Test Case 1: Graph doesn't contain a cycle (Expected: Yes)" << std::endl;

    // Create a graph without a cycle
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);

    if (g2.isCyclic())
        std::cout << "Test Case 2: Graph contains a cycle (Expected: No)" << std::endl;
    else
        std::cout << "Test Case 2: Graph doesn't contain a cycle (Expected: No)" << std::endl;

    return 0;
}