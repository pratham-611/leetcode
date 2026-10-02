class Solution {
public:
    int calc(vector<int>& start1, vector<int>& duration1,
             vector<int>& start2, vector<int>& duration2) {

        int minEnd = INT_MAX;

        for (int i = 0; i < start1.size(); i++) {
            minEnd = min(minEnd, start1[i] + duration1[i]);
        }

        int ans = INT_MAX;

        for (int i = 0; i < start2.size(); i++) {
            int start = max(minEnd, start2[i]);
            int finish = start + duration2[i];

            ans = min(ans, finish);
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int landFirst = calc(
            landStartTime, landDuration,
            waterStartTime, waterDuration
        );

        int waterFirst = calc(
            waterStartTime, waterDuration,
            landStartTime, landDuration
        );

        return min(landFirst, waterFirst);
    }
};