class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k + 1, -1))
        );

        dp[0][0][0] = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

                int value = grid[i][j];

                int cost = (value == 0) ? 0 : 1;
                int score = value;

                for (int c = cost; c <= k; c++) {

                    if (i > 0 && dp[i - 1][j][c - cost] != -1) {
                        dp[i][j][c] = max(
                            dp[i][j][c],
                            dp[i - 1][j][c - cost] + score
                        );
                    }

                    if (j > 0 && dp[i][j - 1][c - cost] != -1) {
                        dp[i][j][c] = max(
                            dp[i][j][c],
                            dp[i][j - 1][c - cost] + score
                        );
                    }
                }
            }
        }

        int ans = -1;

        for (int c = 0; c <= k; c++) {
            ans = max(ans, dp[m - 1][n - 1][c]);
        }

        return ans;
    }
};