//#include<iostream>
//#include<cmath>
//using namespace std;
//class Position
//{
//public:
//    Position(double xx = 0, double yy = 0)
//        :_x(xx), _y(yy){};
//    void Show() {
//        cout << "(" << _x << "," << _y << ")" << endl;
//    }
//    friend double Distance(Position a, Position b);
//private:
//    double _x, _y;
//};
//
//double Distance(Position a, Position b)
//{
//    double dx = a._x - b._x;
//    double dy = a._y - b._y;
//    return sqrt(dx * dx + dy * dy);
//}
//int main(void)
//{
//    Position p1(3.0, 4.0), p2(6.0, 8.0);
//    p1.Show();
//    p2.Show();
//    double d = Distance(p1, p2);
//    cout << "Á½µã¼ä¾àÀë:" << d << endl;
//    return 0;
//}