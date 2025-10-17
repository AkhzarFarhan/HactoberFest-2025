"""
graph_algorithms.py

What does it contain:
- Representation helpers (directed/undirected, weighted/unweighted)
- BFS, DFS (iterative + recursive)
- Connected Components (undirected), Strongly Connected Components (Kosaraju)
- Topological Sort (Kahn + DFS variants)
- Cycle Detection (directed/undirected)
- Bipartite Check (BFS coloring)
- Shortest Paths:
    - Unweighted (BFS)
    - Dijkstra (non-negative weights)
    - Bellman–Ford (negative edges; detects negative cycles)
    - Floyd–Warshall (all-pairs; detects negative cycles)
- Minimum Spanning Tree:
    - Kruskal (Union-Find)
    - Prim (PQ)
- Bridges & Articulation Points (Tarjan)
- Eulerian Path/Circuit checks (undirected)
- A*

Use:
    cd Python/Graph_based_algorithms
    python graph_algorithms.py --demo
"""

from __future__ import annotations
from collections import deque, defaultdict
from dataclasses import dataclass
from typing import Any, Callable, Dict, Iterable, List, Optional, Set, Tuple
import heapq
import math
import sys
import argparse

# --------------------------- Graph representation ---------------------------

@dataclass(frozen=True)
class Edge:
    u: Any
    v: Any
    w: float = 1.0

def build_adj(
    edges: Iterable[Tuple[Any, Any, float]],
    directed: bool = False
) -> Dict[Any, List[Tuple[Any, float]]]:
    """Build adjacency list from (u,v,w)."""
    adj: Dict[Any, List[Tuple[Any, float]]] = defaultdict(list)
    for u, v, w in edges:
        adj[u].append((v, w))
        if not directed:
            adj[v].append((u, w))
        if u not in adj:
            adj[u] = adj[u]
        if v not in adj:
            adj[v] = adj[v]
    return dict(adj)

# ------------------------------ Traversals ----------------------------------

def bfs(adj: Dict[Any, List[Tuple[Any, float]]], src: Any) -> List[Any]:
    """Breadth-first traversal order (unweighted semantics)."""
    seen, order = {src}, []
    q = deque([src])
    while q:
        u = q.popleft()
        order.append(u)
        for v, _ in adj.get(u, []):
            if v not in seen:
                seen.add(v)
                q.append(v)
    return order

def dfs_iter(adj: Dict[Any, List[Tuple[Any, float]]], src: Any) -> List[Any]:
    """Iterative DFS pre-order."""
    seen, order = set(), []
    st = [src]
    while st:
        u = st.pop()
        if u in seen: 
            continue
        seen.add(u)
        order.append(u)
        for v, _ in reversed(adj.get(u, [])):
            if v not in seen:
                st.append(v)
    return order

def dfs_recursive(
    adj: Dict[Any, List[Tuple[Any, float]]], src: Any, order: Optional[List[Any]] = None, _seen: Optional[Set[Any]] = None
) -> List[Any]:
    """Recursive DFS pre-order."""
    if order is None: order = []
    if _seen is None: _seen = set()
    _seen.add(src)
    order.append(src)
    for v, _ in adj.get(src, []):
        if v not in _seen:
            dfs_recursive(adj, v, order, _seen)
    return order

# --------------------------- Connected Components ---------------------------

def connected_components(adj: Dict[Any, List[Tuple[Any, float]]]) -> List[List[Any]]:
    """Undirected CCs."""
    seen, comps = set(), []
    for node in adj.keys():
        if node in seen: 
            continue
        comp, q = [], deque([node])
        seen.add(node)
        while q:
            u = q.popleft()
            comp.append(u)
            for v, _ in adj.get(u, []):
                if v not in seen:
                    seen.add(v)
                    q.append(v)
        comps.append(comp)
    return comps

# --------------------------- Strongly Connected Components ------------------

def kosaraju_scc(adj_dir: Dict[Any, List[Tuple[Any, float]]]) -> List[List[Any]]:
    """Kosaraju's algorithm (directed)."""
    rev: Dict[Any, List[Tuple[Any, float]]] = defaultdict(list)
    for u, nbrs in adj_dir.items():
        for v, w in nbrs:
            rev[v].append((u, w))
        if u not in rev:
            rev[u] = rev[u]
    order, seen = [], set()

    def dfs1(u: Any) -> None:
        seen.add(u)
        for v, _ in adj_dir.get(u, []):
            if v not in seen:
                dfs1(v)
        order.append(u)

    for u in adj_dir.keys():
        if u not in seen:
            dfs1(u)

    comps, seen2 = [], set()

    def dfs2(u: Any, bucket: List[Any]) -> None:
        seen2.add(u)
        bucket.append(u)
        for v, _ in rev.get(u, []):
            if v not in seen2:
                dfs2(v, bucket)

    for u in reversed(order):
        if u not in seen2:
            bucket: List[Any] = []
            dfs2(u, bucket)
            comps.append(bucket)
    return comps

# ------------------------------ Topological Sort ----------------------------

def topo_kahn(adj_dir: Dict[Any, List[Tuple[Any, float]]]) -> List[Any]:
    """Kahn's algorithm (BFS in-degree). Raises ValueError on cycles."""
    indeg = {u: 0 for u in adj_dir}
    for u, nbrs in adj_dir.items():
        for v, _ in nbrs:
            indeg[v] = indeg.get(v, 0) + 1
            if v not in indeg:
                indeg[v] = indeg[v]
    q = deque([u for u, d in indeg.items() if d == 0])
    order = []
    while q:
        u = q.popleft()
        order.append(u)
        for v, _ in adj_dir.get(u, []):
            indeg[v] -= 1
            if indeg[v] == 0:
                q.append(v)
    if len(order) != len(indeg):
        raise ValueError("Graph has at least one cycle; topological sort impossible.")
    return order

def topo_dfs(adj_dir: Dict[Any, List[Tuple[Any, float]]]) -> List[Any]:
    """DFS-based topo order (raises ValueError on cycles)."""
    WHITE, GRAY, BLACK = 0, 1, 2
    color = {u: WHITE for u in adj_dir}
    order: List[Any] = []

    def dfs(u: Any) -> None:
        color[u] = GRAY
        for v, _ in adj_dir.get(u, []):
            c = color.get(v, WHITE)
            if c == GRAY:
                raise ValueError("Cycle detected.")
            if c == WHITE:
                dfs(v)
        color[u] = BLACK
        order.append(u)

    for u in adj_dir.keys():
        if color[u] == WHITE:
            dfs(u)
    return list(reversed(order))

# ------------------------------- Cycle Checks -------------------------------

def has_cycle_undirected(adj: Dict[Any, List[Tuple[Any, float]]]) -> bool:
    """Detect cycle in undirected graph via DFS and parent tracking."""
    seen: Set[Any] = set()

    def dfs(u: Any, parent: Any) -> bool:
        seen.add(u)
        for v, _ in adj.get(u, []):
            if v == parent:
                continue
            if v in seen or dfs(v, u):
                return True
        return False

    for u in adj.keys():
        if u not in seen and dfs(u, None):
            return True
    return False

def has_cycle_directed(adj_dir: Dict[Any, List[Tuple[Any, float]]]) -> bool:
    """Detect cycle in directed graph using colors."""
    WHITE, GRAY, BLACK = 0, 1, 2
    color = {u: WHITE for u in adj_dir}

    def dfs(u: Any) -> bool:
        color[u] = GRAY
        for v, _ in adj_dir.get(u, []):
            c = color.get(v, WHITE)
            if c == GRAY:
                return True
            if c == WHITE and dfs(v):
                return True
        color[u] = BLACK
        return False

    return any(color[u] == WHITE and dfs(u) for u in adj_dir)

# ------------------------------ Bipartite Check -----------------------------

def is_bipartite(adj: Dict[Any, List[Tuple[Any, float]]]) -> bool:
    """Check bipartiteness via BFS coloring (undirected)."""
    color: Dict[Any, int] = {}
    for start in adj.keys():
        if start in color:
            continue
        color[start] = 0
        q = deque([start])
        while q:
            u = q.popleft()
            for v, _ in adj.get(u, []):
                if v not in color:
                    color[v] = color[u] ^ 1
                    q.append(v)
                elif color[v] == color[u]:
                    return False
    return True

# ------------------------------ Shortest Paths ------------------------------

def shortest_path_unweighted(adj: Dict[Any, List[Tuple[Any, float]]], src: Any) -> Dict[Any, int]:
    """BFS distances (unweighted)."""
    dist = {src: 0}
    q = deque([src])
    while q:
        u = q.popleft()
        for v, _ in adj.get(u, []):
            if v not in dist:
                dist[v] = dist[u] + 1
                q.append(v)
    return dist

def dijkstra(adj: Dict[Any, List[Tuple[Any, float]]], src: Any) -> Dict[Any, float]:
    """Dijkstra for non-negative weights."""
    dist: Dict[Any, float] = {src: 0.0}
    pq: List[Tuple[float, Any]] = [(0.0, src)]
    seen: Set[Any] = set()
    while pq:
        d, u = heapq.heappop(pq)
        if u in seen:
            continue
        seen.add(u)
        for v, w in adj.get(u, []):
            nd = d + float(w)
            if nd < dist.get(v, math.inf):
                dist[v] = nd
                heapq.heappush(pq, (nd, v))
    return dist

def bellman_ford(
    edges: Iterable[Edge],
    nodes: Iterable[Any],
    src: Any
) -> Tuple[Dict[Any, float], bool]:
    """
    Bellman–Ford: returns (dist, has_negative_cycle_reachable_from_src).
    nodes: iterable of vertices; edges: Edge(u,v,w)
    """
    dist = {n: math.inf for n in nodes}
    dist[src] = 0.0
    n = len(dist)
    edgelist = list(edges)
    for _ in range(n - 1):
        updated = False
        for e in edgelist:
            if dist[e.u] + e.w < dist[e.v]:
                dist[e.v] = dist[e.u] + e.w
                updated = True
        if not updated:
            break
    has_neg = any(dist[e.u] + e.w < dist[e.v] for e in edgelist)
    return dist, has_neg

def floyd_warshall(nodes: List[Any], adj_dir: Dict[Any, List[Tuple[Any, float]]]) -> Tuple[Dict[Any, Dict[Any, float]], bool]:
    """
    Floyd–Warshall all-pairs shortest paths.
    Returns (dist, has_negative_cycle).
    """
    dist: Dict[Any, Dict[Any, float]] = {i: {j: math.inf for j in nodes} for i in nodes}
    for i in nodes:
        dist[i][i] = 0.0
    for u, nbrs in adj_dir.items():
        for v, w in nbrs:
            dist[u][v] = min(dist[u][v], float(w))
    for k in nodes:
        for i in nodes:
            dik = dist[i][k]
            if dik == math.inf: 
                continue
            for j in nodes:
                v = dik + dist[k][j]
                if v < dist[i][j]:
                    dist[i][j] = v
    has_neg = any(dist[x][x] < 0 for x in nodes)
    return dist, has_neg

# ---------------------------------- A* --------------------------------------

def astar(
    adj: Dict[Any, List[Tuple[Any, float]]],
    src: Any,
    goal: Any,
    h: Optional[Callable[[Any], float]] = None
) -> Tuple[Dict[Any, float], Dict[Any, Any]]:
    """
    A* shortest path. h(node) is admissible heuristic (defaults to 0).
    Returns (g_score, parent) for path reconstruction to 'goal'.
    """
    if h is None:
        h = lambda _: 0.0
    g: Dict[Any, float] = {src: 0.0}
    f: Dict[Any, float] = {src: h(src)}
    openpq: List[Tuple[float, Any]] = [(f[src], src)]
    parent: Dict[Any, Any] = {}

    closed: Set[Any] = set()
    while openpq:
        _, u = heapq.heappop(openpq)
        if u == goal:
            break
        if u in closed:
            continue
        closed.add(u)
        for v, w in adj.get(u, []):
            tentative = g[u] + float(w)
            if tentative < g.get(v, math.inf):
                g[v] = tentative
                f[v] = tentative + h(v)
                parent[v] = u
                heapq.heappush(openpq, (f[v], v))
    return g, parent

# ---------------------------------- MST -------------------------------------

class UnionFind:
    def __init__(self, nodes: Iterable[Any]):
        self.p = {x: x for x in nodes}
        self.r = {x: 0 for x in nodes}
    def find(self, x: Any) -> Any:
        while self.p[x] != x:
            self.p[x] = self.p[self.p[x]]
            x = self.p[x]
        return x
    def union(self, a: Any, b: Any) -> bool:
        ra, rb = self.find(a), self.find(b)
        if ra == rb: return False
        if self.r[ra] < self.r[rb]:
            ra, rb = rb, ra
        self.p[rb] = ra
        if self.r[ra] == self.r[rb]:
            self.r[ra] += 1
        return True

def kruskal_mst(nodes: Iterable[Any], edges: Iterable[Edge]) -> Tuple[List[Edge], float]:
    """Kruskal MST for undirected graphs; edges treated as undirected."""
    uf = UnionFind(nodes)
    mst: List[Edge] = []
    total = 0.0
    for e in sorted(edges, key=lambda e: e.w):
        if uf.union(e.u, e.v):
            mst.append(e)
            total += e.w
    return mst, total

def prim_mst(adj: Dict[Any, List[Tuple[Any, float]]], start: Optional[Any] = None) -> Tuple[List[Edge], float]:
    """Prim MST for connected undirected graphs."""
    if not adj:
        return [], 0.0
    if start is None:
        start = next(iter(adj))
    seen: Set[Any] = {start}
    pq: List[Tuple[float, Any, Any]] = []
    for v, w in adj[start]:
        heapq.heappush(pq, (float(w), start, v))
    mst: List[Edge] = []
    total = 0.0
    while pq and len(seen) < len(adj):
        w, u, v = heapq.heappop(pq)
        if v in seen:
            continue
        seen.add(v)
        mst.append(Edge(u, v, w))
        total += w
        for x, wx in adj[v]:
            if x not in seen:
                heapq.heappush(pq, (float(wx), v, x))
    return mst, total

# ----------------------- Bridges & Articulation Points ----------------------

def bridges(adj: Dict[Any, List[Tuple[Any, float]]]) -> List[Tuple[Any, Any]]:
    """Tarjan bridges in undirected graph."""
    timer = 0
    tin: Dict[Any, int] = {}
    low: Dict[Any, int] = {}
    res: List[Tuple[Any, Any]] = []
    seen: Set[Any] = set()

    def dfs(u: Any, p: Any) -> None:
        nonlocal timer
        seen.add(u)
        tin[u] = low[u] = timer; timer += 1
        for v, _ in adj.get(u, []):
            if v == p:
                continue
            if v in seen:
                low[u] = min(low[u], tin[v])
            else:
                dfs(v, u)
                low[u] = min(low[u], low[v])
                if low[v] > tin[u]:
                    res.append((u, v))

    for u in adj.keys():
        if u not in seen:
            dfs(u, None)
    return res

def articulation_points(adj: Dict[Any, List[Tuple[Any, float]]]) -> Set[Any]:
    """Tarjan articulation points in undirected graph."""
    timer = 0
    tin: Dict[Any, int] = {}
    low: Dict[Any, int] = {}
    res: Set[Any] = set()
    seen: Set[Any] = set()

    def dfs(u: Any, p: Any) -> None:
        nonlocal timer
        seen.add(u)
        tin[u] = low[u] = timer; timer += 1
        children = 0
        for v, _ in adj.get(u, []):
            if v == p:
                continue
            if v in seen:
                low[u] = min(low[u], tin[v])
            else:
                dfs(v, u)
                low[u] = min(low[u], low[v])
                if low[v] >= tin[u] and p is not None:
                    res.add(u)
                children += 1
        if p is None and children > 1:
            res.add(u)

    for u in adj.keys():
        if u not in seen:
            dfs(u, None)
    return res

# ------------------------- Eulerian Path/Circuit (UG) -----------------------

def eulerian_undirected_status(adj: Dict[Any, List[Tuple[Any, float]]]) -> str:
    """
    Returns:
        - "circuit" if all vertices have even degree and the graph is connected (on non-zero degree vertices).
        - "path"    if exactly two vertices have odd degree and it's connected.
        - "none"    otherwise.
    """
    degrees = {u: len(adj.get(u, [])) for u in adj}
    nonzero = [u for u, d in degrees.items() if d > 0]
    if not nonzero:
        return "circuit"
    seen: Set[Any] = set()
    q = deque([nonzero[0]])
    seen.add(nonzero[0])
    while q:
        u = q.popleft()
        for v, _ in adj.get(u, []):
            if v not in seen and degrees[v] > 0:
                seen.add(v)
                q.append(v)
    if len(seen) != len(nonzero):
        return "none"
    odd = sum(1 for d in degrees.values() if d % 2 == 1)
    if odd == 0:
        return "circuit"
    if odd == 2:
        return "path"
    return "none"

# ------------------------------ Demo / CLI ----------------------------------

def _demo() -> None:

    undirected_edges = [
        ("A", "B", 4), ("A", "C", 1),
        ("B", "C", 2), ("B", "D", 5),
        ("C", "D", 8), ("C", "E", 10),
        ("D", "E", 2), ("D", "Z", 6),
        ("E", "Z", 3),
    ]
    ug = build_adj(undirected_edges, directed=False)

    print("BFS from A:", bfs(ug, "A"))
    print("DFS (iter) from A:", dfs_iter(ug, "A"))
    print("Unweighted dist from A:", shortest_path_unweighted(ug, "A"))
    print("Dijkstra from A:", dijkstra(ug, "A"))

    mst_k, w_k = kruskal_mst({*ug.keys()}, [Edge(u, v, w) for (u, v, w) in undirected_edges])
    print("Kruskal MST weight:", w_k, "edges:", mst_k)

    mst_p, w_p = prim_mst(ug, "A")
    print("Prim MST weight:", w_p, "edges:", mst_p)

    print("Bridges:", bridges(ug))
    print("Articulation points:", articulation_points(ug))
    print("Eulerian status:", eulerian_undirected_status(ug))
    print("Bipartite:", is_bipartite(ug))

    directed_edges = [
        ("s", "a", 1), ("a", "b", 2), ("b", "c", 3),
        ("c", "a", -6),
        ("b", "t", 1), ("a", "t", 10)
    ]
    dg = build_adj(directed_edges, directed=True)
    nodes = list(dg.keys())
    bf_dist, has_neg = bellman_ford([Edge(u, v, w) for (u, v, w) in directed_edges], nodes, "s")
    print("Bellman–Ford from s:", bf_dist, "neg_cycle:", has_neg)

    fw_dist, fw_neg = floyd_warshall(nodes, dg)
    print("Floyd–Warshall neg_cycle:", fw_neg)

    sccs = kosaraju_scc(dg)
    print("SCCs:", sccs)
    dag = build_adj([("A","B",1),("A","C",1),("B","D",1),("C","D",1)], directed=True)
    print("Topo (Kahn):", topo_kahn(dag))
    print("Topo (DFS):", topo_dfs(dag))


    g_scores, parent = astar(ug, "A", "Z")
    def reconstruct(goal: Any) -> List[Any]:
        path = [goal]
        while path[-1] in parent:
            path.append(parent[path[-1]])
        return list(reversed(path))
    print("A* path A->Z (cost):", g_scores.get("Z"), "path:", reconstruct("Z"))

def main():
    ap = argparse.ArgumentParser(description="Graph Algorithms (Python, single-file).")
    ap.add_argument("--demo", action="store_true", help="Run a quick demonstration of all algorithms.")
    args = ap.parse_args()
    if args.demo:
        _demo()
    else:
        print(__doc__.splitlines()[0])
        print("Run with: python graph_algorithms.py --demo")

if __name__ == "__main__":
    main()