class Solution {
public:
    string removeKdigits(string num, int k) {
        
        string result = "";
        
        for(auto &ch : num)
        {
            while(!result.empty() && ch < result.back() && k > 0)
            {
                result.pop_back();
                --k;
            }
            
            if(!result.empty() || ch != '0')
                result.push_back(ch);
        }
        
        while(!result.empty() && k--)
            result.pop_back();
        
        return result.empty() ? "0" : result;
    }
};