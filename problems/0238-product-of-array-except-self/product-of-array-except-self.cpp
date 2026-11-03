class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size());

        if(nums.size() == 2)
        {
            answer[0] = nums[1];
            answer[1] = nums[0];

            return answer;
        }

        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());

        int prefixI = 1;
        int prefixPrev = 0;
        prefix[0] = nums[0];

        int suffixI = nums.size() - 2;
        int suffixPrev = nums.size() - 1;
        suffix[suffixPrev] = nums[suffixPrev];


        while((prefixI < nums.size()) && (suffixI >= 0))
        {
            prefix[prefixI] = prefix[prefixPrev] * nums[prefixI];
            prefixI++;
            prefixPrev++;

            suffix[suffixI] = suffix[suffixPrev] * nums[suffixI];
            suffixI--;
            suffixPrev--;
        }

        int prefixProduct = 1;
        int suffixProduct = suffix[1];
        answer[0] = prefixProduct * suffixProduct;

        int prefixTrack = 0;
        int suffixTrack = 2;

        for(int i = 1; i < nums.size(); i++)
        {
            prefixProduct = prefix[prefixTrack];

            if(suffixTrack == nums.size())
            {
                suffixProduct = 1;
            }
            else
            {
                suffixProduct = suffix[suffixTrack];
            }

            answer[i] = prefixProduct * suffixProduct;

            prefixTrack++;
            suffixTrack++;
        }
        return answer;
    }
};
