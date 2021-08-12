//#include <iostream>
//#include <memory>
//using namespace std;
//double Division(int a, int b)
//{
//    // 当b == 0时抛出异常
//    if (b == 0)
//        throw "Division by zero condition!";
//    else
//        return ((double)a / (double)b);
//}
//void Func()
//{
//    int len, time;
//    len = 10;
//    time = 0;
//    cout << Division(len, time) << endl;
//}
//void test() {
//    try {
//        Func();
//    }
//    catch (const char* errmsg) {
//        cout << errmsg << endl;
//    }
//    catch (...) {
//        cout << "unknown exception" << endl;
//    }
//}
////class Mytest {
////public:
////    Mytest(const string& str)
////        :_str(str) {}
////    ~Mytest() {
////        std::cout << _str << "destory" << std::endl;
////    }
////private:
////    string _str;
////};
//class Mytest:public enable_shared_from_this<Mytest> {
//public:
//    Mytest(const string& str)
//        :_str(str) {}
//    ~Mytest() {
//        std::cout << _str << "destory" << std::endl;
//    }
//    shared_ptr<Mytest> GetSharedptr() {
//        return shared_from_this();
//    }
//private:
//    string _str;
//};
//
//void delFun(string* p) {
//    std::cout << "Fun delete " << *p << endl;
//    delete p;
//}
//int main() {
//
//    std::cout << "begin" << std::endl;
//    shared_ptr<string> p1;
//    {
//        shared_ptr<string> p2(new string("p1"), [](string* p) {
//            std::cout << "Lamda delete " << *p << std::endl;
//            delete p;
//        });
//        p1 = p2;
//        shared_ptr<string> p3(new string("p3"), delFun);
//    }
//    std::cout << "end" << std::endl;
//    //test();
//   /* shared_ptr<int> ptr{ new int(3) };
//    shared_ptr<int> ptr1;
//    ptr1.reset(new int(3));
//    shared_ptr<int> ptr2 = make_shared<int>(3);*/
//    /*shared_ptr<int> p1 = make_shared<int>(1);
//    shared_ptr<int> p2 = make_shared<int>(2);
//    shared_ptr<int> p3;
//    shared_ptr<double> p4 = make_shared<double>(1);
//
//    bool b1 = p1 < p2;
//    bool b2 = p1 > p3;
//    bool b3 = p3 == p3;*/
//   // bool b4 = p4 < p2;
//
//    //Mytest* p = new Mytest("shared_test");
//    //shared_ptr<Mytest> p1(p);
//    //shared_ptr<Mytest> p2(p); // 
//    //Mytest* p = new Mytest("shared_test");
//    //shared_ptr<Mytest> p1(p);
//    //shared_ptr<Mytest> p2 = p->GetSharedptr(); // 正确做法
//    
//
//    return 0;
//}
//
///*
//class Solution {
//public:
//    int tribonacci(int n) {
//        if (n == 0)
//            return 0;
//        if (n == 1 || n == 2)
//            return 1;
//        vector<int> res(n + 1);
//        res[0] = 0;
//        res[1] = 1;
//        res[2] = 1;
//
//        for (int i = 3; i <= n; ++i) {
//            res[i] = res[i - 1] + res[i - 2] + res[i - 3];
//        }
//        return res[n];
//    }
//};
//*/