#include <iostream>
#include <thread>
#include <algorithm>
#include <vector>
#include <mutex>    //������
#include <condition_variable>   //������

class Wallet {
    int mMoney;
    std::mutex mutex;
public:
    Wallet() : mMoney(0) { }
    int getMoney() { return mMoney; }
    void addMoney(int money) {
        //������������ʱ�����������ͷ�ʱ���������ܺķѽϵ͡���������Ķ��̻߳��������

        //��std::lock_guard������ʱ�������mutex����(�����������mutex����)�ᱻ��ǰ�߳���ס��
        //��lock_guard��������ʱ�����������mutex������Զ�������ֻ�Ǽ���mutex����������ͽ���������
        //std::lock_guard<std::mutex> lockGuard(mutex);

        //unique_lock��
        //ͨ�û����װ���������ӳ���������������ʱ�޳��ԡ��ݹ�����������Ȩת�ƺ�����������һͬʹ�á�
        //unique_lock��lock_guardʹ�ø��������ܸ���ǿ��
        //ʹ��unique_lock��Ҫ���������ʱ�䡢���ܳɱ���
        //std::unique_lock<std::mutex> my_lock (mutex, std::defer_lock);    //std::defer_lock��������״̬

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
    for (int i = 0; i < 5; i++) {   //����5���߳�
        threads.push_back(std::thread(&Wallet::addMoney, &walletObject, 100));
    }

    for (int i = 0; i < 5; i++) {
        threads.at(i).join();   //�ȴ��߳̽���(����ʽ)
        //threads.at(i).detach(); //��������(����ʽ)
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