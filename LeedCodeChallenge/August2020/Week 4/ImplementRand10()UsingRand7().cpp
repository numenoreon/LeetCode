class Solution {
public:
    int rand10() {
        int random = 7*rand7()+rand7()-7;
        if(random>40)
            return rand10();
        else
            return random%10+1;
    }
};