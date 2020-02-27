class Solution {
public:
    
    void sortColors(vector<int>& nums) {
        vector <int> colorTable(3);
        for(int i=0; i<nums.size();++i){
            ++colorTable[nums[i]];
        }
        int j=0;
        for(int i=0; i<3; ++i){
            while(colorTable[i]){
                nums[j]=i;
                --colorTable[i];
                ++j;
            }
        }
    }

};