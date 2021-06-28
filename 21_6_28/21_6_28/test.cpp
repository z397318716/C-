#include <semaphore.h>
class Foo {
protected:
    mutex mtx1, mtx2;
    sem_t sem_1, sem_2;
    std::atomic<bool> a{ false };
    std::atomic<bool> b{ false };
public:
    Foo() {
        /*
        mtx1.lock();
        mtx2.lock();
        */
        /*
        sem_init(&sem_1, 0, 0);
        sem_init(&sem_2, 0, 0);
        */
    }

    void first(function<void()> printFirst) {

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        //mtx1.unlock();
        //sem_post(&sem_1);
        a = true;
    }

    void second(function<void()> printSecond) {
        //mtx1.lock();
        //sem_wait(&sem_1);
        // printSecond() outputs "second". Do not change or remove this line.
        while (!a) {
            this_thread::sleep_for(chrono::milliseconds(1));
        }
        printSecond();
        //mtx1.unlock();
        //mtx2.unlock();
        //sem_post(&sem_2);
        b = true;
    }

    void third(function<void()> printThird) {
        //mtx2.lock();
        //sem_wait(&sem_2);
        // printThird() outputs "third". Do not change or remove this line.
        while (!b) {
            this_thread::sleep_for(chrono::milliseconds(1));
        }
        printThird();
        //mtx2.unlock();

    }
};