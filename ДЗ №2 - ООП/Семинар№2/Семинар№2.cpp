#include <iostream>
#include <vector>
using namespace std;

struct Leaks
{
    ~Leaks() { _CrtDumpMemoryLeaks(); }
};
Leaks _l;

class Parent
{
    float* ch1;
public:
    Parent()
    {
        ch1 = new float;
        *ch1 = 0.0;
    }
    Parent(float* ch_1)
    {
        ch1 = new float;
        *ch1 = *ch_1;
        cout << *ch1 << endl;
    }
    Parent(const Parent& obj)
    {
        ch1 = new float;
        *ch1 = *obj.ch1;
    }
    virtual ~Parent()
    {
        delete ch1;
    }
    virtual Parent* Copy()
    {
        Parent* new_obj = new Parent(*this);
        return new_obj;
    }
    virtual void print()
    {
        cout << *ch1 << endl;
    }
};

class Child :public Parent
{
    int ch2;
public:
    Child()
    {
        ch2 = 0;
    }
    Child(int ch_2)
    {
        ch2 = ch_2;
        cout << ch2 << endl;
    }
    Child(const Child& obj)
    {
        ch2 = obj.ch2;
    }
    ~Child() {}
    virtual Child* Copy()
    {
        Child* new_obj = new Child(*this);
        return new_obj;
    }
    void print()
    {
        cout << ch2 << endl;
    }
};

vector <Parent*> v(7);
vector <Parent*> v1;

void fill()
{
    float ch1 = 13.5;
    int ch2 = 5;
    for (int i = 0; i < v.size(); i++)
    {
        if (i % 2 == 0)
        {
            v[i] = new Parent(&ch1);
        }
        else
        {
            v[i] = new Child(ch2);
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        Parent* a = v[i]->Copy();
        v1.push_back(a);
    }

}

int main()
{
    fill();
    cout << endl;
    for (int i = 0; i < v.size(); i++)
    {
        v[i]->print();
    }
    for (int i = 0; i < v.size(); i++)
    {
        delete v[i];
        delete v1[i];
    }
}