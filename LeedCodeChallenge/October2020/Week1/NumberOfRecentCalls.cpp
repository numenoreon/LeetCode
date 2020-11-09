class RecentCounter {
public:
    RecentCounter() : counter(0), startPos(0) {
        pingRegister.reserve(10000);
    }
    
    int ping(int t) {
        pingRegister.push_back(t);
        while(pingRegister[startPos]<t-3000)
            ++startPos;
        return pingRegister.size()-startPos;
    }
private:
    int counter;
    int startPos;
    vector <int> pingRegister;
};
