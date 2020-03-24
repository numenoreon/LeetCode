class Solution {
public:
    
    struct trans{
        string name, time, amount, city;
        bool probablyInvalid=false;
    };
    
    string to_string(const trans& a){
        return a.name+","+a.time+","+a.amount+","+a.city;
    }
    
    void zeroing(vector <string> &transactions){
        for(auto &i: transactions){
            for(auto &j: i)
                if(j==',')
                    j=' ';
        }
    }
    
    void fill(vector <trans> &vec, vector <string> &transactions){
        stringstream ss;
        for(int i=0; i<transactions.size(); i++){
            trans temp;
            ss.clear();
            ss.str (transactions[i]);
            ss >> temp.name;
            ss >> temp.time;
            ss >> temp.amount;
            ss >> temp.city;
            vec.push_back(temp);
        }
    }
    
    vector<string> invalidTransactions(vector<string>& transactions) {
        
        vector <string> result;
        vector <trans> vec;
        
        zeroing(transactions);
        fill(vec, transactions);
        
        sort(vec.begin(),vec.end(),[](const trans &a, const trans &b){
            return (a.name < b.name) || (a.name == b.name && stoi(a.time)<stoi(b.time)); 
        });

        //for(auto &temp: vec)
        //    cout << temp.name << " " << temp.time << " " << temp.amount << " " << temp.city << endl;
        
        for(int i=0; i<vec.size(); ++i){
            if(stoi(vec[i].amount)>1000){
                    vec[i].probablyInvalid=true;   
                }
            
            for(int j=i+1; j<vec.size() && vec[i].name == vec[j].name
					&& stoi(vec[j].time)-stoi(vec[i].time)<=60; ++j)
                    if(vec[i].city!=vec[j].city)
                        vec[i].probablyInvalid=vec[j].probablyInvalid=true;
            
            if(vec[i].probablyInvalid)
                 result.emplace_back(to_string(vec[i]));
        }
        
        return result;
    }
};
