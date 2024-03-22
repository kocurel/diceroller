#include "complex.h"
#include <iostream>
#include <ostream>
#include <string>

int Complex::object_count = 0;

std::ostream& operator<<(std::ostream& str, Complex& val) {
	std::string text = std::to_string(val.getRe()) + ", " + std::to_string(val.getIm());
	return str << text;
}

Complex::Complex(const Complex& other) : m_Re(other.m_Re), m_Im(other.m_Im) {
	std::cout << "COPY CONSTRUCTOR CALLED\n";
	object_count++;
}

Complex::Complex(Complex&& other) noexcept : m_Re(other.m_Re), m_Im(other.m_Im) {
	std::cout << "MOVE CONSTRUCTOR CALLED\n";
	object_count++;
}

Complex& Complex::operator=(Complex&& other) noexcept {
	std::cout << "MOVE ASSIGNMENT OPERATOR CALLED\n";
	m_Re = other.m_Re;
	m_Im = other.m_Im;
	return *this;
}

Complex& Complex::operator=(const Complex& other)
{
	m_Re = other.m_Re;
	m_Im = other.m_Im;
	return *this;
}

Complex& Complex::operator+=(const Complex& other)
{
	m_Re += other.m_Re;
	m_Im += other.m_Im;
	return *this;
}

Complex& Complex::operator-=(const Complex& other)
{
	m_Re -= other.m_Re;
	m_Im -= other.m_Im;
	return *this;
}

Complex& Complex::operator++()
{
	++m_Re;
	return *this;
}

Complex Complex::operator++(int)
{
	Complex temp = *this;
	++m_Re;
	return temp;
}

Complex& Complex::operator--()
{
	--m_Re;
	return *this;
}

Complex Complex::operator--(int)
{
	Complex temp = *this;
	--m_Re;
	return temp;
}

Complex& Complex::operator+(const Complex other) 
{
	m_Re += other.m_Re;
	m_Im += other.m_Im;
	return *this;
}

Complex& Complex::operator-(const Complex other)
{
	m_Re -= other.m_Re;
	m_Im -= other.m_Im;
	return *this;
}

double& Complex::operator[](int specifier)
{
	switch (specifier) {
	case 0:
		return m_Re;
	case 1:
		return m_Im;
	default:
		std::cout << "wrong index specifier\n";
		throw;
	}
}

Complex::~Complex() {
	std::cout << "DESTRUCTOR CALLED\n";
	object_count--;
}

Complex::Complex() : m_Re(0), m_Im(0) {
	std::cout << "CONSTRUCTOR CALLED\n";
	object_count++;
}

Complex::Complex(double Re_val) : m_Re(Re_val), m_Im(0) {
	std::cout << "CONSTRUCTOR CALLED\n";
	object_count++;
}

Complex::Complex(double Re_val, double Im_val) : m_Re(Re_val), m_Im(Im_val) {
	std::cout << "CONSTRUCTOR CALLED\n";
	object_count++;
}

void Complex::setRe(double val) {
	m_Re = val;
}

double Complex::getRe() const {
	return m_Re;
}

void Complex::setIm(double val) {
	m_Im = val;
}

double Complex::getIm() const {
	return m_Im;
}

int Complex::getObjCount() {
	return object_count;
}
