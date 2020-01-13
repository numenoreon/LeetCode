class H2O {
    mutex mtx;
    condition_variable cv;
    atomic <int> numberH, numberO;
public:
    H2O() : numberH(0), numberO(0){
        
    }

    void check(){
        if(numberH==2 && numberO==1){
            numberH=0;
            numberO=0;
        }
    }
    
    void hydrogen(function<void()> releaseHydrogen) {
        
        unique_lock <mutex> lock(mtx);
        cv.wait(lock,[&](){return numberH<2;});
        numberH++;
        releaseHydrogen(); 
        check();
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        unique_lock <mutex> lock(mtx);
        cv.wait(lock,[&](){return numberO<1;});
        numberO++;
        releaseOxygen();
        check();
        cv.notify_all();
        
    }
};