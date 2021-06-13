class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if(find(deadends.begin(), deadends.end(), "0000") != deadends.end())
            return -1;
        if(target == "0000")
            return 0;
        
        queue <string> myQueue;
        set <string> mySet;
        int steps = -1;
        myQueue.push("0000");
        mySet.emplace("0000");
    
        while(!myQueue.empty()){
            ++steps;
            int size = myQueue.size();
            for(int i = 0 ; i<size; i++){
                string current = myQueue.front();
                myQueue.pop();
                if(find(deadends.begin(), deadends.end(), current) == deadends.end()){
                    if(current == target)
                        return steps;
                    
                    for(int i=0;i<4;i++){
                        for(int j = -1; j<2;j+=2){
                            string change = to_string(((current[i]-'0') + j + 10) % 10);
                            string newCurrent = current.substr(0,i) +change+ current.substr(i+1);
                            if(mySet.count(newCurrent) == 0){
                                mySet.emplace(newCurrent);
                                myQueue.push(newCurrent);
                            }
                        }
                    }
                }
            }
        }
        
        return -1;
        
    }
};