class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector <string> results;
        for(int i=0; i<logs.size(); i++){
            if(isdigit(logs[i][logs[i].length()-1])==0)
                results.push_back(logs[i]);
        }
        
        sort(results.begin(), results.end(), [](const string &a, const string &b){
            stringstream s1, s2;
            s1 << a;
            s2 << b;
            string temp1, temp2, last1, last2;
            getline(s1,last1,' ');
            getline(s2,last2,' ');
            while(getline(s1,temp1,' ') && getline(s2,temp2,' ')){
                if(temp1==temp2)
                    continue;
                else if(temp1>temp2)
                    return false;
                else if (temp1<temp2)
                    return true;
            }
            if(a.length()!=b.length())    
                return a.length() < b.length();    
            return last1 < last2;
        });
        
        for(int i=0; i<logs.size(); i++){
            if(isdigit(logs[i][logs[i].length()-1]))
                results.push_back(logs[i]);
        }
        
        return results;
    }
};