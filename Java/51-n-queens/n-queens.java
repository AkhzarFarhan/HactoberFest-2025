class Solution {
    public List<List<String>> solveNQueens(int n) {
        // Initialize the board with '.' representing empty spaces
        char[][] board = new char[n][n];
        // Fill the board with '.' to represent empty positions
        for (int i = 0; i < n; i++) {
            Arrays.fill(board[i], '.');
        }

        // List to store all valid solutions
        List<List<String>> result = new ArrayList<>();
        
        // Arrays to track attacked rows and diagonals
        int[] leftRow = new int[n]; // Tracks if a row is occupied
        int[] lowerDiagonal = new int[2 * n - 1]; // Tracks if a lower diagonal is attacked
        int[] upperDiagonal = new int[2 * n - 1]; // Tracks if an upper diagonal is attacked

        // Start the backtracking process from column 0
        backtrack(0, board, result, leftRow, lowerDiagonal, upperDiagonal);
        
        // Return the list of all valid solutions
        return result; 
    }

    // Backtracking function to try placing queens column by column
    private void backtrack(int col, char[][] board, List<List<String>> result, 
                           int[] leftRow, int[] lowerDiagonal, int[] upperDiagonal) {
        
        // If we've placed queens in all columns, we've found a solution
        if (col == board.length) {
            result.add(construct(board)); // Convert the board to a list of strings and add it to result
            return;
        }

        // Try placing a queen in each row of the current column
        for (int row = 0; row < board.length; row++) {
            
            // Check if it's safe to place a queen at position (row, col)
            // A position is safe if:
            // - The row is not already occupied (leftRow[row] == 0)
            // - The lower diagonal is not attacked (lowerDiagonal[row + col] == 0)
            // - The upper diagonal is not attacked (upperDiagonal[board.length - 1 + col - row] == 0)
            if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0
                    && upperDiagonal[board.length - 1 + col - row] == 0) {
                
                // Place the queen on the board at (row, col)
                board[row][col] = 'Q';
                
                // Mark the row and diagonals as attacked
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[board.length - 1 + col - row] = 1;

                // Recursively place queens in the next column
                backtrack(col + 1, board, result, leftRow, lowerDiagonal, upperDiagonal);

                // If placing a queen didn't lead to a solution, backtrack:
                // Remove the queen and unmark the attacked positions
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[board.length - 1 + col - row] = 0;
            }
        }
    }

    // Function to convert the board (a 2D char array) to a List of Strings
    private List<String> construct(char[][] board) {
        List<String> result = new ArrayList<>();
        
        // For each row in the board, convert it to a string and add it to the result list
        for (char[] row : board) {
            result.add(new String(row));
        }
        
        // Return the list of strings representing the board
        return result;
    }
}
