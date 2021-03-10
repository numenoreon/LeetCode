class Solution {
public:
    string intToRoman(int num) {
        
        vector <int> numbers {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        vector <string> signs {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};

        string result = "";
        int temp=0;
        
        for(int i=12; i>=0; --i){
            if(num<numbers[i])
                continue;
            temp=num/numbers[i];
            //cout << temp;
            while(temp--){
                result+=signs[i];
            }
            num=num%numbers[i];
        }
        
        return result;
    }
};
