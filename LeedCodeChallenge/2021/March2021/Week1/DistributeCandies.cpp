class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int ans = 0, n = candyType.size(), i = 0;
        unordered_set<int>s;
        
        while(i < n && ans < (n / 2)){
            if(s.find(candyType[i]) == s.end())
                s.insert(candyType[i]), ans++;
            i++;
        }
        return ans;
    }
};