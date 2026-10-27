class Solution {
public:
    bool isPalindrome(string s) {
        if(s == " ")
        {
            return true;
        }

        string newS = cleanAndLowercase(s);
        if(newS == "")
        {
            return true;
        }
        int ptr1 = 0;
        int ptr2 = newS.size() - 1;

        while(ptr1 < ptr2)
        {
            if(newS[ptr1] != newS[ptr2])
            {
                return false;
            }
            ptr1++;
            ptr2--;
        }
        return true;
    }

    string cleanAndLowercase(const string& s) {
        string result = "";
        for (unsigned char c : s) {
            if (isalnum(c)) {
                result += tolower(c);
            }
        }
        return result;
    }
};
