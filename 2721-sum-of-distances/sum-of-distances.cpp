class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        for (auto& [value, indices] : mp) {
            long long total = 0;

            for (int idx : indices)
                total += idx;

            long long prefix = 0;

            for (int j = 0; j < indices.size(); j++) {
                long long idx = indices[j];

                long long left = idx * j - prefix;

                long long right =
                    (total - prefix - idx)
                    - idx * (indices.size() - j - 1);

                ans[idx] = left + right;

                prefix += idx;
            }
        }
        return ans;
    }
};