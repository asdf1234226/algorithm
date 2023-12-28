#include<iostream>
#include<mutex>
using namespace std;

class Singleton{
    private:
        static Singleton* instance;
        static mutex mtx;
        Singleton(){cout << "单例对象创建" << endl;};
        Singleton(const Singleton&);//私有化拷贝构造函数
        Singleton& operator=(const Singleton&);//防止赋值
    public:
        static Singleton& getInstance(){
            if (instance==nullptr)//尚未创建
            {
                lock_guard<mutex> lock(mtx);//获得锁
                if (instance==nullptr)//为什么还要再次检查，A和B可能都进入第一个if判断，A先获取锁创建一个新实例
                //A完成后释放锁B获得锁，B又去创建一个新实例，所以要再次判断
                {
                    instance=new Singleton();
                }
            }
            return *instance;
        }
};

// 在类外初始化静态成员变量
Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;

int main(){
    Singleton& t1 = Singleton::getInstance();
    Singleton& t2 = Singleton::getInstance();
    return 0;
}