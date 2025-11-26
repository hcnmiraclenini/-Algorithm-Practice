#include <iostream>
using namespace std;
class Complex
{
private:
	double real; // 实部
	double imag; // 虚部
	
public:
	
	Complex();
	Complex(double r, double i);
	// 友元函数，复数c1 + c2(二参数对象相加)
	friend Complex addCom(const Complex& c1, const Complex& c2);
	// 友元函数，输出类对象c的有关数据(c为参数对象)
	friend Complex jianCom(const Complex& c1, const Complex& c2);
	friend void outCom(const Complex& c);
};
Complex::Complex()
{

}
Complex::Complex(double r, double i)
{
	real = r;
	imag = i;
}
Complex addCom(const Complex& c1, const Complex& c2)
{
	Complex c;
     c.real = c1.real + c2.real;
	 c.imag = c1.imag + c2.imag;
	 return c;
	}
Complex jianCom(const Complex& c1, const Complex& c2)
{
	Complex c;
	c.real = c1.real - c2.real;
	c.imag = c1.imag - c2.imag;
	return c;
}

void outCom(const Complex & c)
	{
		cout << "(" << c.real << "," << c.imag << ")"<<endl;
	}

int main()
{
	int real1, imag1, real2, imag2;
	cin >> real1 >> imag1;
	Complex complex1(real1, imag1);

	int t;
	cin >> t;
	while (t--)
	{
		char ch;
		cin >> ch;
		cin >> real2 >> imag2;
		Complex complex2(real2, imag2);
		Complex complex;
		if (ch == '+')
		{
		
			complex=(addCom(complex1, complex2));
			outCom(complex);
		}
		if (ch == '-')
		{
			
			 complex=(jianCom(complex1, complex2));
			outCom(complex);
		}

	}
}