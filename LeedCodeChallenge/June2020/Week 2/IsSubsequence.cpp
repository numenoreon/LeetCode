class Solution {
public:
	bool isSubsequence(string s, string t) {
        if(s=="")
            return true;
        if(t.size()<s.size())
            return false;

		for(int i=0; i<=t.size()-s.size(); ++i){
			if(t[i]==s[0]){
				int x = 1;
				for(int j=i+1; j<t.size(); ++j){
                    cout << s[x] << " " << t[j] << endl;
					if(s[x]==t[j])
						++x;
					if(x==s.size())
						return true;
				}
			}
		}
		return false;
	}
};
