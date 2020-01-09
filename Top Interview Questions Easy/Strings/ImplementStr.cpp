class Solution {
public:
    int strStr(string haystack, string needle) {

        if (needle == "")
            return 0;
        auto it = haystack.find(needle);
        if (it == std::string::npos)
            return -1;
        return it;
    
	}
};