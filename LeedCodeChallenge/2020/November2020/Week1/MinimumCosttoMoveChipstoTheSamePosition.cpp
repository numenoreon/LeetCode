class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd=0, even=0;
        for(int i=0;i<position.size();i++){
            position[i]%2 ? ++odd : ++even;
        }
        return min(odd,even);
    }
};