// dijkstra.js
// Dijkstra's Algorithm - Shortest Path in Weighted Graph
function dijkstra(graph, start) {
  const distances = {};
  const visited = new Set();

  // Initialize distances
  for (const node in graph) {
    distances[node] = Infinity;
  }
  distances[start] = 0;

  while (visited.size < Object.keys(graph).length) {
    // Find the unvisited node with the smallest distance
    let closestNode = null;
    for (const node in distances) {
      if (!visited.has(node) && (closestNode === null || distances[node] < distances[closestNode])) {
        closestNode = node;
      }
    }

    if (closestNode === null) break; // no more reachable nodes
    visited.add(closestNode);

    // Update distances to neighbors
    for (const neighbor in graph[closestNode]) {
      const newDist = distances[closestNode] + graph[closestNode][neighbor];
      if (newDist < distances[neighbor]) {
        distances[neighbor] = newDist;
      }
    }
  }

  return distances;
}

// Example usage
const graph = {
  A: { B: 2, C: 4 },
  B: { A: 2, C: 1, D: 7 },
  C: { A: 4, B: 1, D: 3 },
  D: { B: 7, C: 3 }
};

console.log("Shortest distances from A:", dijkstra(graph, "A"));
