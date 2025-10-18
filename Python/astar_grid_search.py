import heapq

# A* Algorithm for shortest path in a grid
class AStar:
    def __init__(self, grid):
        self.grid = grid
        self.rows = len(grid)
        self.cols = len(grid[0])
        self.directions = [(0,1),(1,0),(0,-1),(-1,0)]  # Right, Down, Left, Up

    def heuristic(self, a, b):
        # Manhattan distance
        return abs(a[0] - b[0]) + abs(a[1] - b[1])

    def in_bounds(self, pos):
        r, c = pos
        return 0 <= r < self.rows and 0 <= c < self.cols

    def passable(self, pos):
        r, c = pos
        return self.grid[r][c] == 0  # 0 means free cell

    def neighbors(self, pos):
        return [ (r,c) for dr,dc in self.directions if self.in_bounds((r := pos[0]+dr, c := pos[1]+dc)) and self.passable((r,c)) ]

    def search(self, start, goal):
        open_set = []
        heapq.heappush(open_set, (0, start))
        came_from = {}
        g_score = {start:0}

        while open_set:
            _, current = heapq.heappop(open_set)

            if current == goal:
                path = []
                while current in came_from:
                    path.append(current)
                    current = came_from[current]
                path.append(start)
                return path[::-1]  # reverse path

            for neighbor in self.neighbors(current):
                tentative_g = g_score[current] + 1  # cost = 1 for each move
                if neighbor not in g_score or tentative_g < g_score[neighbor]:
                    g_score[neighbor] = tentative_g
                    f_score = tentative_g + self.heuristic(neighbor, goal)
                    heapq.heappush(open_set, (f_score, neighbor))
                    came_from[neighbor] = current

        return None  # no path found

if __name__ == "__main__":
    # Example grid: 0 = free, 1 = obstacle
    grid = [
        [0,0,0,0,1],
        [1,1,0,1,0],
        [0,0,0,0,0],
        [0,1,1,1,0],
        [0,0,0,0,0]
    ]

    start = (0,0)
    goal = (4,4)

    astar = AStar(grid)
    path = astar.search(start, goal)

    if path:
        print("Path found:", path)
    else:
        print("No path exists")
