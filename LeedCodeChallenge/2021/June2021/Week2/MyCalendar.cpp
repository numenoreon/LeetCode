class MyCalendar {
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        auto it = mapsMe.lower_bound(end);
        if (it != mapsMe.begin() && (--it)->second > start)
            return false; 
        
        mapsMe.insert(make_pair(start,end));
        return true;
    }
private:
    map <int,int> mapsMe;
};