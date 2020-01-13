class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.size()) return 0;
        map <char, int> mapping;
        int max=0, counter=0;
        for(int i=0; i<s.length();++i){
            ++mapping[s[i]];
            counter=1;
            for(int j=i+1;j<s.length();++j){
                if(++mapping[s[j]]>1){
                    if(counter>max){
                        max=counter;
                    }
                    mapping.clear();
                    break;
                }
                else{
                    ++counter;
                    if(counter>max){
                        max=counter;
                    }
                }
            }
        }
        return max>counter ? max : counter;
    }
};