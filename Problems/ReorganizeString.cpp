class Solution
{
public:
	string reorganizeString(string S)
	{
		vector<pair<char, int>> hashmap(128);
		
        for (int i = 0; i < 128; ++i)
			hashmap[i] = pair<char, int>(i, 0);

		for (char &c : S)
			hashmap[c].second++;

		auto comp = [](const pair<char, int>& num1, const pair<char, int>& num2) {return num1.second > num2.second; };
		sort(hashmap.begin(), hashmap.end(), comp);

		string sortedLetter = "";
		for (int i = 0; i < 128; ++i)
        {
            if (hashmap[i].second != 0)
            {
                if (hashmap[i].second > ((S.length() + 1) / 2))
                    return "";
                sortedLetter += string(hashmap[i].second, hashmap[i].first);
            }
        }

		string result = "";

        int leftPtr=0, rightPtr= (sortedLetter.length() - 1) / 2 + 1;
        
        while(leftPtr<(sortedLetter.length() - 1) / 2 + 1)
		{
			result += sortedLetter[leftPtr++];
			result += sortedLetter[rightPtr++];
		}
        
		return result;
	}
};