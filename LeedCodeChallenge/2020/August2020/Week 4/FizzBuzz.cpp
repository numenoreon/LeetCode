class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector <string> result;
        
        for(int i=1; i<n+1; ++i){
            string temp="";
            if(i%3!=0 && i%5!=0)
                temp+=to_string(i);
            if(i%3==0)
                temp+="Fizz";
            if(i%5==0)
                temp+="Buzz";
            result.push_back(temp);
        }
        
        return result;
    }
};