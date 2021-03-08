class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> occurence(26);
        
        for(int i=0; i<tasks.size(); ++i){
            ++occurence[tasks[i]-'A'];
        }
        
        sort(occurence.begin(),occurence.end(), [](int &a, int &b){return a<b;});
        
        int max_val = occurence[25]-1;
        int idle_slots = max_val*n;
        
        for(int i=24; i>=0; --i){
            idle_slots -= min(occurence[i],max_val);
        }
        
        return idle_slots > 0 ? idle_slots+tasks.size() : tasks.size();
    }
};
