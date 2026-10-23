class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
        {
            return false;
        }

        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;

        for(int i = 0; i < s.size(); i++)
        {
            sMap[s[i]]++;
            tMap[t[i]]++;
        }

        for(int i = 0; i < t.size(); i++)
        {
            if(!sMap.contains(t[i]))
            {
                return false;
            }
            else
            {
                if(sMap[t[i]] != tMap[t[i]])
                {
                    return false;
                }
            }
        }

        return true;

    }
};
