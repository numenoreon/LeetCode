class Solution {
public:
    int countBinarySubstrings(string s) {

	array <int , 2 > counter {0, 0};
	int result = 0, num=0;

    
	for (int i = 0; i < s.length(); ++i) {
	
        num = s[i] - '0';
		if (i == 0 || s[i] != s[i - 1])
            counter[num] = 0;

		++counter[num];
        
		if (counter[num] <= counter[1 - num])
            ++result;

	}

	return result;
    }
};