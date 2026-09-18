class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();

        vector<vector<char>> ans(n, vector<char>(m));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][m - 1 - i] = box[i][j];
            }
        }

        for (int j = 0; j < m; j++) {
            int empty = n - 1;

            for (int i = n - 1; i >= 0; i--) {

                if (ans[i][j] == '*') {
                    empty = i - 1;
                }
                else if (ans[i][j] == '#') {
                    swap(ans[i][j], ans[empty][j]);
                    empty--;
                }
            }
        }

        return ans;
    }
};