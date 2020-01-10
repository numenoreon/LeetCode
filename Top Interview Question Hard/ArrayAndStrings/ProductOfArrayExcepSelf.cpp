class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int counter = count(nums.begin(),nums.end(),0);
        if(counter>1)
            return vector <int> (nums.size(),0);
        else if(counter==1){
        	auto it = find(nums.begin(),nums.end(),0);
        	if(it!=nums.end()){
            		int product1=std::accumulate(nums.begin(), it, 1, std::multiplies<int>());
            		int product2=std::accumulate(it+1, nums.end(), 1, std::multiplies<int>());
            		vector <int> result (nums.size(),0);
            		result[it-nums.begin()]=product1*product2;
            		return result;
        	}
        }
        int product = std::accumulate(nums.begin(), nums.end(), 1, std::multiplies<int>());
        vector <int> result (nums.size());
        for(int i=0; i<nums.size(); i++){
            result[i]=product/nums[i];
        }
    return result;
    }
};