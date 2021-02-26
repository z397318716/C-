#include<iostream>
class Hospital
{
public:
    Hospital()
        :_price(100){}
    void Registration() {
        std::cout <<"医院挂号价格:" << _price << std::endl;
    }
private:
    int _price;// 黄牛挂号价格
    friend class Scalper;  //声明 Scalper 为友元类
};
class Scalper
{
public:
    Hospital h1;
    void Registration()  //黄牛挂号
    {
        h1._price -= 50;  //因Scalper是Hospital的友元类，故此处可以访问其私有成员
        std::cout <<"黄牛挂号价格:" << h1._price << std::endl;
    }
};
int main()
{
    Hospital h1;
    Scalper s1;
    h1.Registration();
    s1.Registration();
    return 0;
}


