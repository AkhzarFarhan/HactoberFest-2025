# Dijkstra's shortest path algorithm for weighted graphs (non-negative weights)

import heapq
from typing import Dict, List, Tuple

def dijkstra(adj: Dict[int, List[Tuple[int,int]]], src: int) -> Dict[int, float]:
    """
    adj: adjacency list {u: [(v, weight), ...], ...}
    src: source node
    returns distance dict
    """
    dist = {node: float('inf') for node in adj}
    dist[src] = 0
    heap = [(0, src)]
    while heap:
        d, u = heapq.heappop(heap)
        if d > dist[u]:
            continue
        for v, w in adj.get(u, []):
            nd = d + w
            if nd < dist.get(v, float('inf')):
                dist[v] = nd
                heapq.heappush(heap, (nd, v))
    return dist

# ---------- Example ----------
if __name__ == "__main__":
    graph = {
        0: [(1, 4), (2, 1)],
        1: [(3, 1)],
        2: [(1, 2), (3, 5)],
        3: []
    }
    print(dijkstra(graph, 0))  # shortest distances from 0
