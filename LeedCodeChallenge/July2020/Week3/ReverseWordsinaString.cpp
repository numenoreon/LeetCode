class Solution {
public:
    string reverseWords(string s) {
        if(s.empty())
            return s;
        stringstream ss (s);
        string temp = "";
        vector <string> tempVec;
        while( getline(ss, temp, ' ')){
            if(temp=="")
                continue;
            tempVec.push_back(temp);
        }
        if(tempVec.empty())
            return "";
        string result="";
        for(int i=tempVec.size()-1; i>-1; --i){
            result+=tempVec[i];
            result+=" ";
        }
        result.pop_back();
        return result;
    }
};