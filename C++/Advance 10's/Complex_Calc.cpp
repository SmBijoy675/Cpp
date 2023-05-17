#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imaginary;
public:
    Complex(double real, double imaginary) {
        this->real = real;
        this->imaginary = imaginary;
    }
    Complex operator+(const Complex& other) {
        double sumReal = real + other.real;
        double sumImaginary = imaginary + other.imaginary;
        return Complex(sumReal, sumImaginary);
    }
    Complex operator-(const Complex& other) {
        double diffReal = real - other.real;
        double diffImaginary = imaginary - other.imaginary;
        return Complex(diffReal, diffImaginary);
    }
    Complex operator*(const Complex& other) {
        double mulReal = (real * other.real) - (imaginary * other.imaginary);
        double mulImaginary = (real * other.imaginary) + (imaginary * other.real);
        return Complex(mulReal, mulImaginary);
    }
    Complex operator/(const Complex& other) {
        double divisor = (other.real * other.real) + (other.imaginary * other.imaginary);
        if (divisor == 0) {
            cerr << "Division by zero is not allowed." << endl;
            exit(1);
        }
        double divReal = ((real * other.real) + (imaginary * other.imaginary)) / divisor;
        double divImaginary = ((imaginary * other.real) - (real * other.imaginary)) / divisor;
        return Complex(divReal, divImaginary);
    }
    void display() {
        cout << real << " + " << imaginary << "i" << endl;
    }
};

int main() {
    Complex complex1(2.0, 3.0);
    Complex complex2(1.0, -2.0);

    Complex sum = complex1 + complex2;
    Complex difference = complex1 - complex2;
    Complex product = complex1 * complex2;
    Complex quotient = complex1 / complex2;

    cout << "Sum: ";
    sum.display();

    cout << "Difference: ";
    difference.display();

    cout << "Product: ";
    product.display();

    cout << "Quotient: ";
    quotient.display();

    return 0;
}
