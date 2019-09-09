#include <iostream>
#include <thread>
#include <algorithm>
#include <vector>
#include <mutex>    //互斥锁
#include <condition_variable>   //条件锁

class Wallet {
    int mMoney;
    std::mutex mutex;
public:
    Wallet() : mMoney(0) { }
    int getMoney() { return mMoney; }
    void addMoney(int money) {
        //互斥锁，构造时请求上锁，释放时解锁，性能耗费较低。适用区域的多线程互斥操作。

        //在std::lock_guard对象构造时，传入的mutex对象(即它所管理的mutex对象)会被当前线程锁住。
        //在lock_guard对象被析构时，它所管理的mutex对象会自动解锁，只是简化了mutex对象的上锁和解锁操作。
        //std::lock_guard<std::mutex> lockGuard(mutex);

        //unique_lock：
        //通用互斥包装器，允许延迟锁定、锁定的有时限尝试、递归锁定、所有权转移和与条件变量一同使用。
        //unique_lock比lock_guard使用更加灵活，功能更加强大；
        //使用unique_lock需要付出更多的时间、性能成本。
        //std::unique_lock<std::mutex> my_lock (mutex, std::defer_lock);    //std::defer_lock不设置锁状态

        //mutex.lock(); 
        for (int i = 0; i < money; i++) {
            mMoney++;
        }
        //mutex.unlock();
    }
};

int testMultithreadWallet() {
    Wallet walletObject;
    std::vector<std::thread> threads;
    for (int i = 0; i < 5; i++) {   //启动5个线程
        threads.push_back(std::thread(&Wallet::addMoney, &walletObject, 100));
    }

    for (int i = 0; i < 5; i++) {
        threads.at(i).join();   //等待线程结束(加入式)
        //threads.at(i).detach(); //自主运行(分离式)
    }

    return walletObject.getMoney();
}

int main() {
    int val = 0;
    for (int k = 0; k < 100; k++) {
        if ((val = testMultithreadWallet()) != 500) {
            std::cout << "Error at count = " << k << " Money in Wallet = " << val << std::endl;
        }
        else 
            std::cout << "Right! Money in Wallet = " << val << std::endl;
    }
    system("pause");
    return 0;
}