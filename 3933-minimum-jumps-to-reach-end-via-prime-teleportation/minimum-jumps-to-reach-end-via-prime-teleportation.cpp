class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return 0;

        int maxVal = *max_element(nums.begin(), nums.end());

        vector<int> spf(maxVal + 1);

        for (int i = 0; i <= maxVal; i++)
            spf[i] = i;

        for (int i = 2; i * i <= maxVal; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= maxVal; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            while (x > 1) {
                int p = spf[x];

                mp[p].push_back(i);

                while (x % p == 0)
                    x /= p;
            }
        }

        queue<int> q;
        vector<bool> visited(n, false);
        unordered_set<int> usedPrime;

        q.push(0);
        visited[0] = true;

        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int i = q.front();
                q.pop();

                if (i == n - 1)
                    return steps;

                if (i > 0 && !visited[i - 1]) {
                    visited[i - 1] = true;
                    q.push(i - 1);
                }

                if (i + 1 < n && !visited[i + 1]) {
                    visited[i + 1] = true;
                    q.push(i + 1);
                }

                int x = nums[i];

                if (x >= 2 && spf[x] == x &&
                    !usedPrime.count(x)) {

                    usedPrime.insert(x);

                    for (int j : mp[x]) {
                        if (!visited[j]) {
                            visited[j] = true;
                            q.push(j);
                        }
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};