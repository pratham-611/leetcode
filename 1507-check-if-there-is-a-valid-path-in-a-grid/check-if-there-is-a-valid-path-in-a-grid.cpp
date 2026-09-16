class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        vector<vector<int>> dir = {
            {},
            {1, 3}, // 1: left, right
            {0, 2}, // 2: up, down
            {3, 2}, // 3: left, down
            {1, 2}, // 4: right, down
            {3, 0}, // 5: left, up
            {1, 0}  // 6: right, up
        };

        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        q.push({0, 0});
        vis[0][0] = true;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == n - 1 && y == m - 1)
                return true;

            for (int d : dir[grid[x][y]]) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;

                if (vis[nx][ny])
                    continue;
               int opposite = (d + 2) % 4;

                bool connected = false;

                for (int nd : dir[grid[nx][ny]]) {
                    if (nd == opposite) {
                        connected = true;
                        break;
                    }
                }

                if (connected) {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }
};