class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return 0;
        }

        unordered_set<int> set;
        for(int i = 0; i < nums.size(); i++)
        {
            set.insert(nums[i]);
        }

        int longestSeq = 1;
        int currSeq = 1;

        for(int num : set)
        {
            int target = num;

            if(!(set.contains(target - 1)))
            {
                currSeq = 1;
                bool runLoop = true;
                while(runLoop)
                {
                    if(set.contains(target + 1))
                    {
                        currSeq++;
                        target = target + 1;
                    }
                    else
                    {
                        runLoop = false;
                    }
                }

                if(currSeq > longestSeq)
                {
                    longestSeq = currSeq;
                }
            }

        }
        return longestSeq;
    }
};
