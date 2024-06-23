// 326627635 | adi.peisach@gmail.com

#ifndef TREE_ITERATORS_GUI_COMPLEX_HPP
#define TREE_ITERATORS_GUI_COMPLEX_HPP
#include <string>

using std::string;

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

    double getReal() const {
        return real;
    }

    double getImaginary() const {
        return imaginary;
    }

    double getNorm() const {
        return real*real + imaginary*imaginary;
    }

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imaginary * other.imaginary,
                       real * other.imaginary + imaginary * other.real);
    }

    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imaginary * other.imaginary;
        return Complex((real * other.real + imaginary * other.imaginary) / denominator,
                       (imaginary * other.real - real * other.imaginary) / denominator);
    }

    bool operator<(const Complex& other) const {
        return getNorm() < other.getNorm();
    }

    bool operator>(const Complex& other) const {
        return other < *this;
    }

    bool operator==(const Complex& other) const {
        return real == other.real && imaginary == other.imaginary;
    }

    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    bool operator<=(const Complex& other) const {
        return *this == other || *this < other;
    }

    bool operator>=(const Complex& other) const {
        return *this == other || *this > other;
    }

    string toString() const {
        string ans = "(" + doubleString(getReal());
        ans.append(",").append(doubleString(getImaginary()));
        ans.append(")");
        return ans;
    }

private:
    string doubleString(double d) const {
        string ans = std::to_string(d);
        while (ans.back() == '0') {
            ans.pop_back();
        }
        return ans;
    }

};


#endif //TREE_ITERATORS_GUI_COMPLEX_HPP
