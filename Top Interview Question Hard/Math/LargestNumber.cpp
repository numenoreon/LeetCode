class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strings;
        strings.reserve(nums.size());
        
        for(auto &i : nums)
            strings.push_back(to_string(i));

        auto cmp = [](const string &a,const string &b) {
            return a + b > b + a;
        };
        
        sort(strings.begin(),strings.end(), cmp);
            
        if(strings.empty() || strings[0]=="0")
            return "0";
        
        string result;
        for(auto &i : strings)
            result+=i;

        return result;
    }
};