#pragma once
#include <ostream>

enum ComplexPart : int {
	Re = 0,
	Im = 1
};

class Complex {
private:
	static int object_count;
	double m_Re = 0;
	double m_Im = 0;
public:
	friend std::ostream& operator<<(std::ostream& str, Complex& val);
	Complex();
	Complex(double Re_val);
	Complex(double Re_val, double Im_val);
	Complex(const Complex& other);
	Complex(Complex&& other) noexcept;
	~Complex();
	Complex& operator=(Complex&& other) noexcept;
	Complex& operator=(const Complex& other);
	Complex& operator+=(const Complex& other);
	Complex& operator-=(const Complex& other);
	Complex& operator++();
	Complex operator++(int);
	Complex& operator--();
	Complex operator--(int);
	Complex& operator+(const Complex other);
	Complex& operator-(const Complex other);
	double& operator[](int specifier);
	void setRe(double val);
	double getRe() const;
	void setIm(double val);
	double getIm() const;
	static int getObjCount();
};
