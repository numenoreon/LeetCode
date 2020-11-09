class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.empty())
            return {};
        vector <string> result;
        int i=1;
        int firstNumber=nums[0];
        string temp = to_string(nums[0]);
        
        while(i<nums.size()){
            if(nums[i]==nums[i-1]+1){
                ++i;
                continue;
            }
            else if(nums[i]>nums[i-1]+1){
                
                if(nums[i-1]==firstNumber){
                    result.push_back(temp);
                    temp=to_string(nums[i]);
                    firstNumber=nums[i];
                }
                else{
                    temp+="->";
                    temp+=to_string(nums[i-1]);
                    result.push_back(temp);
                    temp=to_string(nums[i]);
                    firstNumber=nums[i];
                }
            }
            ++i;
        }
        string cmp = to_string(nums[nums.size()-1]);
        if(temp==cmp)
            result.push_back(temp);
        else{
            temp=temp+"->"+cmp;
            result.push_back(temp);
        }
        
        return result;
    }
};