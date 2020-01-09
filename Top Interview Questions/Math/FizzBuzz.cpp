class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector <string> result (n);
        for(int i=0; i<result.size(); i++){
            if((i+1)%3 ==0 && (i+1)%5==0)
                result[i]="FizzBuzz";
            else if ((i+1)%3==0)
                result[i]="Fizz";
            else if ((i+1)%5==0)
                result[i]="Buzz";
            else
                result[i]=to_string(i+1);
        }
        return result;
    }
};