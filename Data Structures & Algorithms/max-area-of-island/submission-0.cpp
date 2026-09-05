class Solution {
public:

    int dfs(vector<vector<int>>& grid, int row, int col) {

        // Out of bounds
        if (row < 0 || row >= grid.size() ||
            col < 0 || col >= grid[0].size()) {
            return 0;
        }

        // Water
        if (grid[row][col] == 0) {
            return 0;
        }

        // Mark visited
        grid[row][col] = 0;

        int up = dfs(grid, row - 1, col);
        int down = dfs(grid, row + 1, col);
        int left = dfs(grid, row, col - 1);
        int right = dfs(grid, row, col + 1);

        return 1 + up + down + left + right;
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int maxArea = 0;

        for (int row = 0; row < grid.size(); row++) {

            for (int col = 0; col < grid[0].size(); col++) {

                if (grid[row][col] == 1) {

                    int area = dfs(grid, row, col);

                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};