class Solution {
public:
    int romanToInt(string s) {
        int tab[89]; // bigest ASCII code is for X = 88, we are implicit casting char to int
        tab['I'] = 1;
        tab['V'] = 5;
        tab['X'] = 10;
        tab['L'] = 50;
        tab['C'] = 100;
        tab['D'] = 500;
        tab['M'] = 1000;
        int result = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(i + 1 < s.size() && tab[s[i+1]] > tab[s[i]])
                result -=  tab[s[i]]; 
            else
                result += tab[s[i]];
        }
        return result;
    }
};