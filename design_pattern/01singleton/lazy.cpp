// 需要时才被创建 
//只是声明了一个指向实例的指针 static Singleton* instance;，并在第一次调用 getInstance() 方法时才创建实例

#include<iostream>
using namespace std;

class Singleton {
private:
    static Singleton* instance;//只声明指针
    Singleton() {cout << "单例对象创建" << endl;}
    //Singleton(const Singleton&); //防复制
    Singleton& operator=(const Singleton&); //防赋值
    //这两个函数也可以放在public，加上=delete
public:
    Singleton(const Singleton&)=delete;

    static Singleton& getInstance(){
        if(instance==nullptr){//如果还没初始化
            instance=new Singleton();
        }
        return *instance;
    }
};

// 在类外初始化静态成员变量
Singleton* Singleton::instance = nullptr;

int main(){
    Singleton& t1 = Singleton::getInstance();
    Singleton& t2 = Singleton::getInstance();
    return 0;
}