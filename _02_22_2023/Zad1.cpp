//
// Created by MILEN_PC on 2/22/2023.
//
#include "iostream"
using std::cout;
using std::cin;
using std::endl;

struct Complex {
    double real;
    double imaginary;
};

void print(Complex c) {
    cout << c.real << ((c.imaginary < 0) ? " " : " + ") << c.imaginary << "i" << endl;
}

Complex add(const Complex& c1, const Complex& c2) {
    Complex result = {c1.real + c2.real, c1.imaginary + c2.imaginary};
    return result;
}

Complex sub(const Complex& c1, const Complex& c2) {
    Complex result = {c1.real - c2.real, c1.imaginary - c2.imaginary};
    return result;
}

Complex mult(const Complex& c1, const Complex& c2) {
    Complex result = {c1.real * c2.real - c1.imaginary * c2.imaginary, c1.real * c2.imaginary + c1.imaginary * c2.real};
    return result;
}

int main(){
    Complex c1{2, 3}, c2{4, 5};
    print(add(c1, c2));
    print(sub(c1, c2));
    print(mult(c1, c2));
    return 0;
}

