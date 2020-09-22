class Solution {
public:
    bool isPalindrome(string s){
        int left = 0, right = s.length()-1;
        
        while (left < right) {
            while (left < right && !std::isalnum(s[left]))
                ++left;
            while (right > left && !std::isalnum(s[right]))
                --right;

            if(tolower(s[left]) != tolower(s[right]))
                return false;

            ++left,--right;
        }
        return true;
    }
};