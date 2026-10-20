class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> returnIndex = {};
        unordered_map<int, int> numsHash = {};

        for(int i = 0; i < nums.size(); i++)
        {
            numsHash.insert({nums[i], i});
        }

        for(int i = 0; i < nums.size(); i++)
        {
            int need = target - nums[i];
            if((numsHash.contains(need)))
            {
                if(i != numsHash[need])
                {
                    returnIndex.push_back(i);
                    returnIndex.push_back(numsHash[need]);
                    break;
                }
            }
        }
        return returnIndex;
    }
};
