class Solution {
public:

    string encode(vector<string>& strs)
    {
        string outStr;
        int vecSize = strs.size();

        for(int i = 0; i < vecSize; i++)
        {
            outStr += to_string(strs[i].size());
            outStr += '|';

            outStr += strs[i];
        }

        return outStr;
    }

    vector<string> decode(string s)
    {
        vector<string> outVec;
        string outStr;

        bool isSizeStr = true;
        string currSize;
        int size = 0;
        int numRuns = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(isSizeStr && (s[i] != '|' ))
            {
                currSize += s[i];
            }
            if(isSizeStr && (s[i] == '|' ))
            {
                isSizeStr = false;
                size = stoi(currSize);
                if(size == 0)
                {
                    outVec.push_back("");
                    currSize = "";
                    isSizeStr = true;
                }
            }
            else if(!isSizeStr)
            {
                outStr.push_back(s[i]);
                numRuns++;

                if(numRuns == size)
                {
                    currSize = "";
                    size = 0;
                    outVec.push_back(outStr);
                    outStr = "";
                    numRuns = 0;
                    isSizeStr = true;
                }
            }
        }

        return outVec;
    }
};
