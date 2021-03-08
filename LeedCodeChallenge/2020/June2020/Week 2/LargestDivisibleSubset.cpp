class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int maxn = 0;
        int maxlen = 1;
        vector <int> result;
        
        if (nums.size()==0)
            return nums;
        vector <int> divCounter (nums.size(), 1);
        vector <int> addTo (nums.size(), -1);
        sort (nums.begin(), nums.end());
        
        for (int i=0; i<nums.size(); i++) {
            int div = nums[i];
            int newLen = divCounter[i]+1;
            for (int j=i+1; j<nums.size(); j++) {
                int temp = nums[j];
                if (temp%div==0) {
                    if (divCounter[j]<newLen) {
                        divCounter[j]=newLen;
                        addTo[j]=i;
                        if (newLen>maxlen) {
                            maxn = j;
                            maxlen = newLen;
                        }
                    }            
                }
            }
        }
        
        while (addTo[maxn]!=-1) {
            result.push_back(nums[maxn]);
            maxn = addTo[maxn];
        }
        result.push_back(nums[maxn]);
        
        return result;
    }
};