class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        
        if(paragraph.size()==0)
            return "";
        
        for(int i=0;i<paragraph.size();i++)
        {
            if(paragraph[i]=='.' || paragraph[i]=='"' || paragraph[i]==',' || paragraph[i]=='!' || paragraph[i]=='?' 
                                 || paragraph[i]==';' || paragraph[i]=='\'')
                paragraph[i]=' ';
        }
        
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower); 

        unordered_map <string, int> mapsMe;
        set <string> ban;
        int maxOccurence=0;
        string result;
        
        for(int i=0; i<banned.size(); ++i)
            ban.insert(banned[i]);
        
        stringstream ss;
        ss << paragraph;
        
        while(getline (ss, result, ' ')){
            if(result!="")
                ++mapsMe[result];
        }
            
        for(auto &i : mapsMe){
            if(!ban.count(i.first) && i.second>maxOccurence){
                maxOccurence=i.second;
                result=i.first;
            }
        }
        
        return result;
    }
};