class Solution {

public:
string largestNumber(vector<int>& nums) {
 
    vector<string> stringTable(nums.size(),"");
    
    for(int i=0;i<nums.size();i++)
    {
        stringTable[i]=to_string(nums[i]);
    }
    
    auto comp = [] (string &s1, string &s2) {
        return (s1+s2) > (s2+s1);
    };
    
    sort(stringTable.begin(), stringTable.end(), comp);
    
    string result="";
    
    for(auto &i : stringTable){
        result+=i;
    }
    
    if(result.size()>1 && result[0]=='0')
        return "0";
    
    return result;
    }

};