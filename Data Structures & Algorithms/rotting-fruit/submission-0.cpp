class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;

        int fresh = 0;

        // Find rotten and fresh oranges
        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {

                if (grid[i][j] == 2) {
                    q.push({i, j});
                }

                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int minutes = 0;

        // BFS
        while (!q.empty() && fresh > 0) {

            int size = q.size();

            // Process one minute
            for (int i = 0; i < size; i++) {

                auto [row, col] = q.front();
                q.pop();

                // UP
                if (row - 1 >= 0 && grid[row - 1][col] == 1) {
                    grid[row - 1][col] = 2;
                    fresh--;
                    q.push({row - 1, col});
                }

                // DOWN
                if (row + 1 < rows && grid[row + 1][col] == 1) {
                    grid[row + 1][col] = 2;
                    fresh--;
                    q.push({row + 1, col});
                }

                // LEFT
                if (col - 1 >= 0 && grid[row][col - 1] == 1) {
                    grid[row][col - 1] = 2;
                    fresh--;
                    q.push({row, col - 1});
                }

                // RIGHT
                if (col + 1 < cols && grid[row][col + 1] == 1) {
                    grid[row][col + 1] = 2;
                    fresh--;
                    q.push({row, col + 1});
                }
            }

            minutes++;
        }

        // Fresh oranges still exist
        if (fresh > 0) {
            return -1;
        }

        return minutes;
    }
};