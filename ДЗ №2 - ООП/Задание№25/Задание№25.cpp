#include <iostream>
#include <vector>

using namespace std;

struct Leaks
{
	~Leaks() { _CrtDumpMemoryLeaks(); }
};

Leaks _l;

class Shape {
protected:
	double p = 0;
public:
	virtual ~Shape() = default;
	virtual void Param() {  }
	void get() { cout << p << endl; }
};

class Circle :public Shape {
public:
	double r = 0;
	Circle(double R) { r = R; }
	~Circle(){}
	void Param() { p = 2 * 3.14 * r; }
};

class Square :public Shape {
public:
	double a = 0.0;
	Square(double A) { a = A; }
	~Square(){}
	void Param() { p = 4 * a; }
};
int main()
{
	vector <Shape*> v;
	Shape* a1 = new Circle(3.5);
	Shape* a2 = new Square(2.4);
	Shape* a3 = new Circle(5.5);
	Shape* a4 = new Square(4.5);
	v.push_back(a1);
	v.push_back(a2);
	v.push_back(a3);
	v.push_back(a4);
	for (int i = 0; i < v.size(); i++)
	{
		v[i]->Param();
		v[i]->get();
	}
	for (int i = 0; i < v.size(); i++)
	{
		delete v[i];
	}
}