class FooBar {
private:
    int n;
    std::mutex mtx;
    std::condition_variable cv; 
    std::atomic <int> times=0;
public:
    FooBar(int n) : n(n){        
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait( lock, [&]() { return times % 2 == 0; } );
            printFoo();
            ++times;
            lock.unlock();
            cv.notify_all();
        }
        
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait( lock, [&]() { return times % 2 == 1; } );
            printBar();
            ++times;
            lock.unlock();
            cv.notify_all();
        }
    }
};