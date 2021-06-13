class UndergroundSystem {
public:
    unordered_map<int, pair<int, string>> checkin;
    unordered_map<string, pair<double, double>> ans;

    void checkIn(int id, string stationName, int t) {
        checkin[id] = {t, stationName};
    }
    
    void checkOut(int id, string stationName, int t) {
        string temp = checkin[id].second;
        temp += stationName;
        ans[temp].first += (t - checkin[id].first);
        ans[temp].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string temp = startStation + endStation;
        return (ans[temp].first) / (ans[temp].second); 
    }
};