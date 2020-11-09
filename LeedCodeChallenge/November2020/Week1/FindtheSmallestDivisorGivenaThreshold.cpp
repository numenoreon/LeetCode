class Solution {

public:

bool verifyThreshold(vector<int> nums, int threshold, int middle){
    int sum=0;
    for(int i=0; i<nums.size(); ++i){
        sum+=ceil(nums[i]*1.0/middle);
        if(sum>threshold)
            return false;
    }
    
    return true;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    
    int start=1;
    long int end=INT_MAX;
    
    int result=0, middle=0;
    
    while(start<=end){
        
        middle=(start+end)/2;
        
        if(verifyThreshold(nums,threshold,middle)){
            result=middle;
            end=middle-1;
        }
        else{
            start=middle+1;
        }
    }
    
    return result;
}

};