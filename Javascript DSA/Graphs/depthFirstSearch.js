function depthFirstSearch(graph, start, visited = new Set()) {
    visited.add(start);
    console.log(start);

    for (const neighbor of graph[start]) {
        if (!visited.has(neighbor)) {
            depthFirstSearch(graph, neighbor, visited);
        }
    }
}

// Test cases
const graph1 = {
    0: [1, 3],
    1: [0, 2, 4],
    2: [1],
    3: [0, 4],
    4: [1, 3]
};
console.log("DFS starting from node 3 in graph1:");
depthFirstSearch(graph1, 3);

const graph2 = {
    A: ['B', 'C'],
    B: ['A', 'D', 'E'],
    C: ['A', 'F'],
    D: ['B'],
    E: ['B', 'F'],
    F: ['C', 'E']
};
console.log("\nDFS starting from node A in graph2:");
depthFirstSearch(graph2, 'A');

const graph3 = {
    X: ['Y'],
    Y: ['X', 'Z'],
    Z: ['Y', 'W'],
    W: ['Z']
};
console.log("\nDFS starting from node X in graph3:");
depthFirstSearch(graph3, 'X');

const graph4 = {
    1: [2],
    2: [1, 3],
    3: [2],
    4: []
};
console.log("\nDFS starting from node 1 in graph4:");
depthFirstSearch(graph4, 1);
console.log("\nDFS starting from node 4 in graph4:");
depthFirstSearch(graph4, 4);
