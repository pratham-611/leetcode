class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        
        int ans = INT_MAX;

        for (int i = 0; i < landStartTime.size(); i++) {
            int landEnd = landStartTime[i] + landDuration[i];

            for (int j = 0; j < waterStartTime.size(); j++) {
                int waterStart = max(landEnd, waterStartTime[j]);
                int finish = waterStart + waterDuration[j];

                ans = min(ans, finish);
            }
        }

        for (int i = 0; i < waterStartTime.size(); i++) {
            int waterEnd = waterStartTime[i] + waterDuration[i];

            for (int j = 0; j < landStartTime.size(); j++) {
                int landStart = max(waterEnd, landStartTime[j]);
                int finish = landStart + landDuration[j];

                ans = min(ans, finish);
            }
        }

        return ans;
    }
};