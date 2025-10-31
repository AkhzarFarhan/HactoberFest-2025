function longestIncreasingPath(matrix) {
    const m = matrix.length;
    const n = matrix[0].length;
    const dirs = [[0, 1], [1, 0], [0, -1], [-1, 0]];
    const memo = Array.from({ length: m }, () => Array(n).fill(0));
    
    function dfs(x, y) {
        if (memo[x][y] !== 0) return memo[x][y];
        let max = 1;
        for (const [dx, dy] of dirs) {
            const nx = x + dx, ny = y + dy;
            if (
                nx >= 0 && nx < m &&
                ny >= 0 && ny < n &&
                matrix[nx][ny] > matrix[x][y]
            ) {
                max = Math.max(max, 1 + dfs(nx, ny));
            }
        }
        memo[x][y] = max;
        return max;
    }

    let result = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            result = Math.max(result, dfs(i, j));
        }
    }
    return result;
}
