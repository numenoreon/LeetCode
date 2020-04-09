class FreqStack {
public:
    FreqStack() {
    }
    
    void push(int x) {
        maxFreq=max(maxFreq,++frequency[x]);
        mapStack[frequency[x]].push(x);
    }
    
    int pop() {
        int result = mapStack[maxFreq].top();
        mapStack[maxFreq].pop();
        --frequency[result];
        if (mapStack[maxFreq].empty())
            --maxFreq;
    
		return result;
    }
    
private:
    int maxFreq=0;
    map <int, int> frequency;
    map <int, stack <int> > mapStack;
};
