class Solution {
public:
    int largestOverlap(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size(), ans = 0;

        for (int dx = -n + 1; dx < n; dx++) {
            for (int dy = -n + 1; dy < n; dy++) {
                int cnt = 0;

                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        int x = i + dx, y = j + dy;

                        if (x >= 0 && x < n && y >= 0 && y < n &&
                            a[i][j] && b[x][y])
                            cnt++;
                    }
                }

                ans = max(ans, cnt);
            }
        }

        return ans;
    }
};