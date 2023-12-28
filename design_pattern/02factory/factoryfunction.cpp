#include<iostream>
using namespace std;

//了大量生产每种类型的鞋子，则要针对不同品牌的鞋子开设独立的生产线，那么每个生产线就只能生产同类型品牌的鞋
//之前简单工厂是一条生产线可以生产不同类型品牌的鞋子
//工厂方法模式把具体产品的创建放在具体工厂类
//以下面代码为例： ShoesFactory抽象工厂类，提供了创建具体鞋子产品的纯虚函数。
//               NiKeProducer、AdidasProducer`具体工厂类，继承抽象工厂类，实现对应具体鞋子产品对象的创建。 



//缺陷： 每增加一个产品要增加对应的具体工厂类



// 鞋子抽象类
class Shoes
{
public:
    virtual ~Shoes() {}
    virtual void Show() = 0;
};
// 耐克鞋子
class NiKeShoes : public Shoes
{
public:
    void Show()
    {
        std::cout << "我是耐克球鞋，我的广告语：Just do it" << std::endl;
    }
};

// 阿迪达斯鞋子
class AdidasShoes : public Shoes
{
public:
    void Show()
    {
        std::cout << "我是阿迪达斯球鞋，我的广告语:Impossible is nothing" << std::endl;
    }
};


// 总鞋厂
class ShoesFactory
{
public:
    virtual Shoes *CreateShoes() = 0;
    virtual ~ShoesFactory() {}
};

// 耐克生产者/生产链
class NiKeProducer : public ShoesFactory
{
public:
    Shoes *CreateShoes()
    {
        return new NiKeShoes();
    }
};

// 阿迪达斯生产者/生产链
class AdidasProducer : public ShoesFactory
{
public:
    Shoes *CreateShoes()
    {
        return new AdidasShoes();
    }
};


int main()
{
    // ================ 生产耐克流程 ==================== //
    // 鞋厂开设耐克生产线
    ShoesFactory *niKeProducer = new NiKeProducer();
    // 耐克生产线产出球鞋
    Shoes *nikeShoes = niKeProducer->CreateShoes();
    // 耐克球鞋广告喊起
    nikeShoes->Show();
    // 释放资源
    delete nikeShoes;
    delete niKeProducer;

    // ================ 生产阿迪达斯流程 ==================== //
    // 鞋厂开设阿迪达斯生产者
    ShoesFactory *adidasProducer = new AdidasProducer();
    // 阿迪达斯生产线产出球鞋
    Shoes *adidasShoes = adidasProducer->CreateShoes();
    // 阿迪达斯球鞋广喊起
    adidasShoes->Show();
    // 释放资源
    delete adidasShoes;
    delete adidasProducer;

    return 0;
}