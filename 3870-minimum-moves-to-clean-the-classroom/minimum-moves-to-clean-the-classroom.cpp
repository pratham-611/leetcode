class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = -1, sc = -1;
        vector<pair<int, int>> litter;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (classroom[r][c] == 'S') {
                    sr = r;
                    sc = c;
                } else if (classroom[r][c] == 'L') {
                    litter.push_back({r, c});
                }
            }
        }

        int k = litter.size();

        if (k == 0)
            return 0;

        int fullMask = (1 << k) - 1;

        vector<vector<int>> litterId(m, vector<int>(n, -1));

        for (int i = 0; i < k; i++) {
            auto [r, c] = litter[i];
            litterId[r][c] = i;
        }

        int masks = 1 << k;
        int E = energy + 1;

        auto id = [&](int r, int c, int mask, int e) {
            return (((r * n + c) * masks + mask) * E + e);
        };

        vector<bool> visited(m * n * masks * E, false);

        struct State {
            int r, c;
            int mask;
            int e;
            int dist;
        };

        queue<State> q;

        visited[id(sr, sc, 0, energy)] = true;
        q.push({sr, sc, 0, energy, 0});

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [r, c, mask, e, dist] = q.front();
            q.pop();

            if (mask == fullMask)
                return dist;

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                if (classroom[nr][nc] == 'X')
                    continue;

                if (e == 0)
                    continue;

                int ne = e - 1;
                int nmask = mask;

                if (litterId[nr][nc] != -1) {
                    nmask |= (1 << litterId[nr][nc]);
                }

                if (classroom[nr][nc] == 'R') {
                    ne = energy;
                }

                int stateId = id(nr, nc, nmask, ne);

                if (!visited[stateId]) {
                    visited[stateId] = true;
                    q.push({nr, nc, nmask, ne, dist + 1});
                }
            }
        }

        return -1;
    }
};