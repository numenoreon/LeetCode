class ZeroEvenOdd {
private:
    int n;
    std::atomic <int> count, output;
    std::mutex mtx;
    condition_variable cv;
public:
    ZeroEvenOdd(int n) : n(2*n), count(0), output(1){
    }

    void zero(function<void(int)> printNumber) {
        unique_lock<mutex> lock(mtx);
        while(1)
        {
            cv.wait(lock,[&](){return (count%2 == 0 || count > n-1);});
            if(count > n-1)
                break;
            printNumber(0);
            ++count;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        unique_lock<mutex> lock(mtx);
        while(1)
        {
            cv.wait(lock,[&](){return ((count%2 == 1 && output%2 == 0) || count > n-1);});
            if(count > n-1)
                break;
            printNumber(output);
            ++count;
            ++output;
            cv.notify_all();
        }    
    }

    void odd(function<void(int)> printNumber) {
        unique_lock<mutex> lock(mtx);
        while(1)
        {
            cv.wait(lock,[&](){return ((count%2 == 1 && output%2 == 1) || count > n-1);});
            if(count > n-1)
                break;
            printNumber(output);
            ++count;
            ++output;
            cv.notify_all();
        }   
    }
};