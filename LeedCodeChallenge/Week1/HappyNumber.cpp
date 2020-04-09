class Solution {
public:

int sumDigitSquare(int n) { 
    int sq = 0; 
    while (n) { 
        int digit = n % 10; 
        sq += digit * digit; 
        n = n / 10; 
    } 
    return sq; 
} 

bool isHappy(int n) { 

    set<int> mySet; 
    mySet.insert(n); 

    while (true) { 
        if (n == 1) 
            return true; 

        n = sumDigitSquare(n); 

        if (mySet.find(n) != mySet.end()) 
            return false; 

        mySet.insert(n); 
    } 
  
    return false; 
    } 
};