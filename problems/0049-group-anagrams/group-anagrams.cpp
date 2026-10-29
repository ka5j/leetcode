class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;

        vector<string> strsCpy = strs;
        unordered_map<string, vector<int>> map;



        for(int i = 0; i < strsCpy.size(); i++)
        {
            sort(strsCpy[i].begin(), strsCpy[i].end());
            map[strsCpy[i]].push_back(i);
        }

        for (auto it = map.begin(); it != map.end(); ++it)
        {
            vector<string> group;

            for (int i = 0; i < it->second.size(); i++)
            {
                int idx = it->second[i];
                group.push_back(strs[idx]);
            }
            result.push_back(group);
        }
        return result;
    }
};
