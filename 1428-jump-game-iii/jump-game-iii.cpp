class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        if (start < 0 || start >= n || arr[start] < 0)
            return false;

        if (arr[start] == 0)
            return true;

        int jump = arr[start];
        arr[start] = -arr[start];

        return canReach(arr, start + jump) ||
               canReach(arr, start - jump);
    }
};