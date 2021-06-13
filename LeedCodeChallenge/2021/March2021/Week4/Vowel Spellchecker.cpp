class Solution {
public:
    vector<string> spellchecker(const vector<string>& wordlist, const vector<string>& queries) {
        unordered_map<string, string> rule1, rule2, rule3;
        const int N = wordlist.size();
        for (int i = 0; i < N; ++i) {
            rule1.emplace(wordlist[i], "");
            rule2.emplace(tolower(wordlist[i]), wordlist[i]);
            rule3.emplace(dvowel(wordlist[i]), wordlist[i]);
        }
        vector <string> result;
        result.reserve(queries.size());
        for (const string& q : queries) {
            if (rule1.count(q)) result.push_back(q);
            else if (rule2.count(tolower(q))) result.push_back(rule2.at(tolower(q)));
            else if (rule3.count(dvowel(q))) result.push_back(rule3.at(dvowel(q)));
            else result.push_back("");
        }
        return result;
    }

    string tolower(const string& s) {
        string result(s.size(), ' ');
        transform(s.begin(), s.end(), result.begin(), ::tolower);
        return result;
    }

    string dvowel(const string& s) {
        static unordered_set<char> mySet = {'a', 'e', 'i', 'o', 'u'};
        string result = "";
        for (const char &c : s) {
            if (mySet.count(::tolower(c))) result.push_back('0');
            else result.push_back(::tolower(c));
        }
        return result;
    }
};