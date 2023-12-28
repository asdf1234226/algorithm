//要求： 设计一个类，只生成该类的一个实例
// 全局或静态变量也能实现类似的功能，但封装性不好

// 设计思想： 为了只生成一个实例，可以将构造函数声明为private级别，同时提供public static 方法获得唯一实例化对象
// 饿汉式：  类产生的时候就创建好实例对象
// 懒汉式：  需要的时候才创建对象

#include<iostream>
using namespace std;

class Singleton{
    private: 
        static Singleton instance; //单例对象
        Singleton(){cout << "单例对象创建" << endl;};
        Singleton(const Singleton&);//禁止拷贝
        Singleton& operator=(const Singleton&);//禁止赋值
        //将拷贝构造函数和赋值构造函数设置为私有（private） 
        //或者可以构造方法在public中加delete
    public:
        static Singleton& getInstance(){
            return instance;
        }
};
//类外初始化静态成员变量
Singleton Singleton::instance;

int main(){
    Singleton& t1 = Singleton::getInstance();
    Singleton& t2 = Singleton::getInstance();
    return 0;
}