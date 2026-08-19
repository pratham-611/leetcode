class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];

        int product = 1;

        for (int i = 0; i < n; i++) {
            product *= nums[i];
            ans = max(ans, product);

            if (product == 0)
                product = 1;
        }

        product = 1;

        for (int i = n - 1; i >= 0; i--) {
            product *= nums[i];
            ans = max(ans, product);

            if (product == 0)
                product = 1;
        }

        return ans;
    }
};