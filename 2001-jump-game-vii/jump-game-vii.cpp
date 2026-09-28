class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        vector<int> dp(n, 0);
        dp[0] = 1;

        int reachable = 0;

        for (int i = minJump; i < n; i++) {

            if (dp[i - minJump])
                reachable++;

            if (i - maxJump - 1 >= 0 && dp[i - maxJump - 1])
                reachable--;

            if (s[i] == '0' && reachable > 0)
                dp[i] = 1;
        }

        return dp[n - 1];
    }
};