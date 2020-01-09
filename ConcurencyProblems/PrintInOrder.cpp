class Foo {
  std::mutex mtx1;
  std::mutex mtx2;
public:
    Foo() {
    mtx1.lock();
    mtx2.lock();
    }

    void first(function<void()> printFirst) {
        printFirst();
        mtx1.unlock();	
    }

    void second(function<void()> printSecond) {
        std::lock_guard<std::mutex> lock(mtx1);
        printSecond();
        mtx2.unlock();	
    }

    void third(function<void()> printThird) {
        std::lock_guard<std::mutex> lock(mtx2);
        printThird();
    }
};