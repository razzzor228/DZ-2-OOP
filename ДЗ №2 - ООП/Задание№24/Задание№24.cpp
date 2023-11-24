#include <iostream>

using namespace std;

template <class T>
class Base {
public:
    Base(T a) { p = a; }
    void print() { cout << p << endl; }
private:
    T p;
};

int main()
{
    Base <int> bi(22);
    Base <double> bd(22.84);
    Base <string> bs("test");
    bi.print();
    bd.print();
    bs.print();
}
