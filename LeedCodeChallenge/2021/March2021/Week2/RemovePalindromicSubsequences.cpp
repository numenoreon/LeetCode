class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.size() == 0){
            return 0;
        }
        if(isPalindrome(s)){
            return 1;      
        }
        return 2;
    }

    bool isPalindrome(string s){
        for(int i=0,j=s.size()-1; i < j ; i++,j--){
            if(s[i] != s[j]){
                return false;
            }
        }
        return true;
    }
};