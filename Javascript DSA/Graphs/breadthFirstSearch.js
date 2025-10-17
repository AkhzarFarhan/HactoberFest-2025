function breadthFirstSearch(graph, start) {
    const visited = new Set();
    const queue = [start];
    visited.add(start);

    while (queue.length > 0) {
        const node = queue.shift();
        console.log(node);

        for (const neighbor of graph[node]) {
            if (!visited.has(neighbor)) {
                visited.add(neighbor);
                queue.push(neighbor);
            }
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
console.log("BFS starting from node 3 in graph1:");
breadthFirstSearch(graph1, 3);

const graph2 = {
    A: ['B', 'C'],
    B: ['A', 'D', 'E'],
    C: ['A', 'F'],
    D: ['B'],
    E: ['B', 'F'],
    F: ['C', 'E']
};
console.log("\nBFS starting from node A in graph2:");
breadthFirstSearch(graph2, 'A');

const graph3 = {
    X: ['Y'],
    Y: ['X', 'Z'],
    Z: ['Y', 'W'],
    W: ['Z']
};
console.log("\nBFS starting from node X in graph3:");
breadthFirstSearch(graph3, 'X');

const graph4 = {
    1: [2],
    2: [1, 3],
    3: [2],
    4: []
};
console.log("\nBFS starting from node 1 in graph4:");
breadthFirstSearch(graph4, 1);
console.log("\nBFS starting from node 4 in graph4:");
breadthFirstSearch(graph4, 4);
