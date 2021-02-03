class Solution {
private:
    unordered_map<string, priority_queue<string,vector<string>, greater<string> >> mapsMe;
    vector<string> result;

public:
    void topSort(string &source)
    {
        while(!mapsMe[source].empty())
        {
            string temp=mapsMe[source].top();
            mapsMe[source].pop();
            topSort(temp);
        }
        result.push_back(source);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        if(tickets.empty())
        {
            return {};
        }
        for(auto &ticket : tickets)
        {
            mapsMe[ticket[0]].push(ticket[1]);
        }
	string startPos = "JFK";
        topSort(startPos);
        reverse(result.begin(),result.end());
        return result;
    }
};