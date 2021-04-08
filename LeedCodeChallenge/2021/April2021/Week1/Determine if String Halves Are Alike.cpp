class Solution {
public:
    bool halvesAreAlike(string s) {
        std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){
            return std::tolower(c);
        });
        
        int half = s.size()/2;
        
        int counterA = 0, counterB = 0;
        
        for(int i=0; i<half; ++i){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                ++counterA;
        }
        
        for(int i=half; i<s.size(); ++i){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                ++counterB;
        }
        
        return counterA==counterB;
    }
};