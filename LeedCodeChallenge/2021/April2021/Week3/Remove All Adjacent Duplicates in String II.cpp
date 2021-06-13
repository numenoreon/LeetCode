class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector <pair<char,int>> v;

        for(char ch : s){
           if(v.empty() || v.back().first != ch)
               v.push_back(make_pair(ch,1));
            
            else{
                v.back().second++;
                if(v.back().second == k)
                    v.pop_back();
            }
        }
        
        string ans = "";
        for(auto p :v){
            ans.append(p.second,p.first);
        }
        
        return ans;
    }
};