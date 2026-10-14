class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mn = nums[0], mx = nums[0];

        for (int x : nums) {
            mn = min(mn, (long long)x);
            mx = max(mx, (long long)x);
        }

        return (mx - mn) * k;
    }
};