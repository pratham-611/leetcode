class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        for (int layer = 0; layer < min(m, n) / 2; layer++) {

            int top = layer;
            int left = layer;
            int bottom = m - 1 - layer;
            int right = n - 1 - layer;

            vector<int> v;

            for (int j = left; j < right; j++)
                v.push_back(grid[top][j]);

            for (int i = top; i < bottom; i++)
                v.push_back(grid[i][right]);

            for (int j = right; j > left; j--)
                v.push_back(grid[bottom][j]);

            for (int i = bottom; i > top; i--)
                v.push_back(grid[i][left]);

            int len = v.size();
            int shift = k % len;

            int idx = shift;

            for (int j = left; j < right; j++)
                grid[top][j] = v[idx++ % len];

            for (int i = top; i < bottom; i++)
                grid[i][right] = v[idx++ % len];

            for (int j = right; j > left; j--)
                grid[bottom][j] = v[idx++ % len];

            for (int i = bottom; i > top; i--)
                grid[i][left] = v[idx++ % len];
        }

        return grid;
    }
};