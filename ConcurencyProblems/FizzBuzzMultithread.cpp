class FizzBuzz {
private:
    int n;
    std::mutex mtx;
    std::atomic <int> count;
    std::condition_variable cv;

public:
    FizzBuzz(int n) : n(n), count(1){
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        unique_lock<mutex> lock(mtx);
        while(1){
        cv.wait(lock,[&](){return ((count%3==0 && count%5!=0) || count > n) ;});
        if(count > n)
            break;
        printFizz();
        ++count;
        cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        unique_lock<mutex> lock(mtx);
        while(1){
        cv.wait(lock,[&](){return ((count%5==0 && count%3!=0) || count > n);});
        if(count > n)
            break;
        printBuzz();
        ++count;
        cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    
    void fizzbuzz(function<void()> printFizzBuzz) {
        unique_lock<mutex> lock(mtx);
        while(1){
        cv.wait(lock,[&](){return ((count%5==0 && count%3==0) || count > n);});
        if(count > n)
            break;
        printFizzBuzz();
        ++count;
        cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        unique_lock<mutex> lock(mtx);
        while(1){
        cv.wait(lock,[&](){return ((count%5!=0 && count%3!=0) || count > n);});
        if(count > n)
            break;
        printNumber(count);
        ++count;
        cv.notify_all();
        }
    }
};