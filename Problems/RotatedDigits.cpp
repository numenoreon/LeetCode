class Solution {
public:
    int rotatedDigits(int N) {
        int counter = 0;
        for(int i = 2; i <= N; ++i){
            counter += isValid(i);
        }
        return counter;
    }
    
    bool isValid(int i){
        bool isGood = false;
        while(i > 0){
            int rem = i % 10;
            if(rem == 2 || rem == 5 || rem == 6 || rem == 9) isGood = true;
            if(rem == 3 || rem == 4 || rem == 7) return false;
            i /= 10;
        }
        return isGood;
    }
};