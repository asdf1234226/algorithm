#include<iostream>
using namespace std;


// 基类 鞋子
class Shoes
{
public:
    virtual void Show() = 0;
    virtual ~Shoes() {}
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

// 基类 衣服
class Clothe
{
public:
    virtual void Show() = 0;
    virtual ~Clothe() {}
};

// 优衣库衣服
class UniqloClothe : public Clothe
{
public:
    void Show()
    {
        std::cout << "我是优衣库衣服，我的广告语：I am Uniqlo" << std::endl;
    }
};


// 工厂模板类
template <class TProduct>
class Factory
{
public:
    TProduct* CreateProduct()
    {
        return new TProduct();
    }
};

int main()
{
    // 构造耐克鞋的工厂对象
    Factory<NiKeShoes> nikeShoesFactory;
    // 创建耐克鞋对象
    Shoes* pNiKeShoes = nikeShoesFactory.CreateProduct();
    // 打印耐克鞋广告语
    pNiKeShoes->Show();

    // 构造优衣库衣服的工厂对象
    Factory<UniqloClothe> uniqloClotheFactory;
    // 创建优衣库衣服对象
    Clothe* pUniqloClothe = uniqloClotheFactory.CreateProduct();
    // 显示衣服广告语
    pUniqloClothe->Show();

    // 清理资源
    delete pNiKeShoes;
    pNiKeShoes = NULL;

    delete pUniqloClothe;
    pUniqloClothe = NULL;

    return 0;
}
