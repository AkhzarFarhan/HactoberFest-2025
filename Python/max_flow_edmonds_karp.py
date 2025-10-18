# max_flow_edmonds_karp.py
# Edmonds-Karp algorithm (BFS-based Ford-Fulkerson) for Maximum Flow

from collections import deque, defaultdict

class MaxFlow:
    def __init__(self, n):
        self.n = n  # number of nodes
        self.graph = defaultdict(dict)  # adjacency list with capacities

    def add_edge(self, u, v, capacity):
        self.graph[u][v] = capacity
        self.graph[v].setdefault(u, 0)  # reverse edge initially 0

    def bfs(self, source, sink, parent):
        visited = [False] * self.n
        queue = deque([source])
        visited[source] = True

        while queue:
            u = queue.popleft()
            for v, cap in self.graph[u].items():
                if not visited[v] and cap > 0:
                    visited[v] = True
                    parent[v] = u
                    if v == sink:
                        return True
                    queue.append(v)
        return False

    def edmonds_karp(self, source, sink):
        parent = [-1] * self.n
        max_flow = 0

        while self.bfs(source, sink, parent):
            # find minimum residual capacity along the path
            path_flow = float('inf')
            s = sink
            while s != source:
                path_flow = min(path_flow, self.graph[parent[s]][s])
                s = parent[s]

            # update capacities along the path
            v = sink
            while v != source:
                u = parent[v]
                self.graph[u][v] -= path_flow
                self.graph[v][u] += path_flow
                v = parent[v]

            max_flow += path_flow

        return max_flow

if __name__ == "__main__":
    n = 6  # number of nodes
    mf = MaxFlow(n)
    
    # Example graph (node 0 = source, node 5 = sink)
    mf.add_edge(0, 1, 16)
    mf.add_edge(0, 2, 13)
    mf.add_edge(1, 2, 10)
    mf.add_edge(1, 3, 12)
    mf.add_edge(2, 1, 4)
    mf.add_edge(2, 4, 14)
    mf.add_edge(3, 2, 9)
    mf.add_edge(3, 5, 20)
    mf.add_edge(4, 3, 7)
    mf.add_edge(4, 5, 4)

    maxflow = mf.edmonds_karp(0, 5)
    print("Maximum Flow from source to sink:", maxflow)
