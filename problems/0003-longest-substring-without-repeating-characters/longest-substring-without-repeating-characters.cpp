class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) return s.size();

        unordered_map<char, int> map;
        int ptr1 = 0;
        int max_len = 0;

        for (int ptr2 = 0; ptr2 < s.size(); ++ptr2) {
            map[s[ptr2]]++;

            while (map[s[ptr2]] > 1) {
                map[s[ptr1]]--;
                ptr1++;
            }

            max_len = max(max_len, (ptr2 - ptr1) + 1);
        }

        return max_len;
    }
};
