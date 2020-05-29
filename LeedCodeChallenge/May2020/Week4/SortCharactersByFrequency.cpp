class Solution {
public:
    string frequencySort(string s) {
        
    std::map <char, int> mapsMeChar;
    std::multimap <int, char, std::greater<int> > mapsMeInt;

    for (unsigned int i = 0; i < s.length(); ++i) {
        ++mapsMeChar[s[i]];
    }

    for (auto &i : mapsMeChar) {
        mapsMeInt.insert({i.second, i.first});
    }

    string data = "";

    for (auto& i : mapsMeInt)
            for(int j=0; j<i.first; ++j)
                data += i.second; 
        
    return data;
        
    }
};