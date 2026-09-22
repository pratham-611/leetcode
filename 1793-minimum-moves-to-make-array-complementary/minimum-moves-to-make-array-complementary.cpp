class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0, j = n - 1; i < j; i++, j--) {
            int a = nums[i];
            int b = nums[j];

            int low = min(a, b) + 1;
            int high = max(a, b) + limit;

            int sum = a + b;

            diff[2] += 2;
            diff[2 * limit + 1] -= 2;

            diff[low]--;
            diff[high + 1]++;

            diff[sum]--;
            diff[sum + 1]++;
        }

        int ans = INT_MAX;
        int moves = 0;

        for (int sum = 2; sum <= 2 * limit; sum++) {
            moves += diff[sum];
            ans = min(ans, moves);
        }

        return ans;
    }
};