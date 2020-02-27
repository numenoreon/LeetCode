class Solution {
public:
    string reverseOnlyLetters(string S) {
        int front=0, last=S.length()-1;
        
        while (front<last){
            if(isalpha(S[front]) && isalpha(S[last])){
                swap(S[front],S[last]);
                ++front,--last;
            }
            else{
                if(!isalpha(S[front]))
                    ++front;
                if(!isalpha(S[last]))
                    --last;
            }
        }
        return S;
    }
};