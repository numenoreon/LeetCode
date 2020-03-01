class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int counter = 0;
        
        int i = g.size()-1;
        int j = s.size()-1;
        
        while(i >= 0 && j >= 0){
            if(g[i] <= s[j]){
                ++counter, --j, --i;
            }
            else if(g[i]>s[j]){
                --i;
            }
        }
        
        return counter;
    }
};