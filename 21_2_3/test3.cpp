#include<iostream>
class Hospital
{
public:
    Hospital()
        :_price(100){}
    void Registration() {
        std::cout <<"ҽԺ�Һż۸�:" << _price << std::endl;
    }
private:
    int _price;// ��ţ�Һż۸�
    friend class Scalper;  //���� Scalper Ϊ��Ԫ��
};
class Scalper
{
public:
    Hospital h1;
    void Registration()  //��ţ�Һ�
    {
        h1._price -= 50;  //��Scalper��Hospital����Ԫ�࣬�ʴ˴����Է�����˽�г�Ա
        std::cout <<"��ţ�Һż۸�:" << h1._price << std::endl;
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


