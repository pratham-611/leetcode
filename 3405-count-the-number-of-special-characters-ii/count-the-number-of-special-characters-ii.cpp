class Solution {
public:
    int numberOfSpecialChars(string word) {
        int firstUpper[26];
        int lastLower[26];

        for (int i = 0; i < 26; i++) {
            firstUpper[i] = -1;
            lastLower[i] = -1;
        }

        for (int i = 0; i < word.size(); i++) {
            char c = word[i];

            if (c >= 'a' && c <= 'z') {
                lastLower[c - 'a'] = i;
            }
            else {
                if (firstUpper[c - 'A'] == -1)
                    firstUpper[c - 'A'] = i;
            }
        }

        int ans = 0;

        for (int i = 0; i < 26; i++) {
            if (lastLower[i] != -1 &&
                firstUpper[i] != -1 &&
                lastLower[i] < firstUpper[i]) {
                ans++;
            }
        }

        return ans;
    }
};