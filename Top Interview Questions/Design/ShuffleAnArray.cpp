class Solution {
    
    vector <int> primal;
    
public:
        
    Solution(vector<int>& nums) {
        swap(nums, primal);
    }
    
    vector<int> reset() {
        return primal;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        //srand(time(NULL));
        vector <int> shuffled = primal;
        
        for(int i=0; i<shuffled.size(); i++){
            int j = rand() % shuffled.size();
            swap(shuffled[i],shuffled[j]);
        }
        
        return shuffled;
    }
};
