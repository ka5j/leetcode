class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> tracker;
        for(int i = 0; i < nums.size(); i++)
        {
            tracker[nums[i]]++;

            if(tracker[nums[i]] > 1)
            {
                return true;
            }
        }
        return false;
    }
};
