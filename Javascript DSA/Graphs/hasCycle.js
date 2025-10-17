function hasCycle(graph, isDirected = true) {
    const visited = new Set();
    const stack = new Set();

    function dfs(node, parent = null) {
        if (stack.has(node)) return true;
        if (visited.has(node)) return false;

        visited.add(node);
        stack.add(node);

        for (const neighbor of graph[node] || []) {

            if (neighbor === parent && !isDirected) continue;
            if (dfs(neighbor, node)) return true;
        }

        stack.delete(node);
        return false;
    }

    for (const node in graph) {
        if (!visited.has(node) && dfs(node)) return true;
    }
    return false;
}

// Test cases for directed graph
const directedGraphWithCycle = { 0: [1], 1: [2], 2: [0] };
const directedGraphWithoutCycle = { 0: [1], 1: [2], 2: [3], 3: [] };

console.log("Directed Graphs:");
console.log(hasCycle(directedGraphWithCycle, true));
console.log(hasCycle(directedGraphWithoutCycle, true));

// Test cases for undirected graph
const undirectedGraphWithCycle = { 0: [1, 2], 1: [0, 2], 2: [0, 1] };
const undirectedGraphWithoutCycle = { 0: [1], 1: [0, 2], 2: [1, 3], 3: [2] };

console.log("\nUndirected Graphs:");
console.log(hasCycle(undirectedGraphWithCycle, false));
console.log(hasCycle(undirectedGraphWithoutCycle, false));
