class Solution {
public:
    static bool compareCounts(std::pair<int, int> a, std::pair<int, int> b) {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;

        if(nums.size() == 1)
        {
            result.push_back(nums[0]);
            return result;
        }

        unordered_map<int, int> map;

        for(int i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++;
        }

        vector<pair<int, int>> vec(map.begin(), map.end());

        sort(vec.begin(), vec.end(), this->compareCounts);

        for(int i = 0; i < k; i++)
        {
            result.push_back(vec[i].first);
        }

        return result;
    }
};
