class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);
        vector<int> preMax(n);

        preMax[0] = nums[0];

        for (int i = 1; i < n; i++) {
            preMax[i] = max(preMax[i - 1], nums[i]);
        }

        int suffixMin = INT_MAX;

        for (int i = n - 1; i >= 0; i--) {

            if (preMax[i] > suffixMin) {
                ans[i] = ans[i + 1];
            } else {
                ans[i] = preMax[i];
            }

            suffixMin = min(suffixMin, nums[i]);
        }

        return ans;
    }
};