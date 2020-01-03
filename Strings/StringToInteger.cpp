class Solution {
public:
    int myAtoi(string str) {
        stringstream ss(str);
        int x=0;
        ss>>x;
        return x;
    }
};