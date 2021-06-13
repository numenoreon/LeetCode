class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
    deque <int> myDQueue {0};
    for (int i = 1; i < nums.size(); ++i) {
        if (myDQueue.front() + k < i)
            myDQueue.pop_front();        
        nums[i] += nums[myDQueue.front()];
        while (!myDQueue.empty() && nums[myDQueue.back()] <= nums[i])
            myDQueue.pop_back();
        myDQueue.push_back(i);
    }
    return nums.back();
    }
};