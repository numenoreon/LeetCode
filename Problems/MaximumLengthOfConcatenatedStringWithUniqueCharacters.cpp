class Solution {
public:
    int checkString(string temp, vector <string> &arr, int index){
        vector <int> myVec(26);
        
        for(int i=0; i<temp.length();++i){
            if(++myVec[temp[i]-'a']>1)
                return 0;
        }
        
        int result = temp.length();
        
        for (int i = index; i < arr.size(); ++i)
            result = max(result, checkString(temp+arr[i], arr, i+1));

        return result;
    }
    
    int maxLength(vector<string>& arr) {
        int finalLength = 0;
        string temp="";
        
        for(int i=0; i<arr.size(); ++i)
            finalLength=max(finalLength,checkString(temp, arr, i));
        
        return finalLength;
    }
};