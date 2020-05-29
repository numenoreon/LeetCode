class Solution {
public:
     vector<int> findAnagrams(string s, string p) {
        if (s.length () < p.length())
        {
            return {};
        }
         
        vector <int> pCount(26);
        vector <int> sCount(26);
        vector <int> result;
         
        for(int i=0; i<p.length(); ++i){
            ++pCount[p[i]-'a'];
            ++sCount[s[i]-'a'];
        }
         
        for(int i=p.length(); i<s.length(); ++i){
            if(sCount==pCount)
                result.push_back(i-p.length());

            --sCount[s[i-p.length()]-'a'];
            ++sCount[s[i]-'a'];
        }
         
         if(sCount==pCount)
             result.push_back(s.length()-p.length());

         
        return result;
    }
};