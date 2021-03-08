class StockSpanner {
public:
    StockSpanner() {  
    }
    
    int next(int price) {
        while(myStack.size() && myStack.top().first <= price)
            myStack.pop();
        
        if(myStack.size()){
            int result = count - myStack.top().second;
            myStack.push({price, count});
            count++;
            return result;
        }
        myStack.push({price, count}), count++;
        return count;
    }
private:
    stack< pair<int,int> > myStack;
    int count = 0;
};