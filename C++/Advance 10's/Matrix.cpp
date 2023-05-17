#include <iostream>
using namespace std;

class Matrix {
private:
    int rows;
    int columns;
    int** data;
public:
    Matrix(int rows, int columns) {
        this->rows = rows;
        this->columns = columns;
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[columns];
        }
    }
    void input() {
        cout << "Enter the elements of the matrix:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cin >> data[i][j];
            }
        }
    }
    Matrix operator+(const Matrix& other) {
        if (rows != other.rows || columns != other.columns) {
            cerr << "Matrix dimensions are not compatible for addition." << endl;
            exit(1);
        }
        Matrix result(rows, columns);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    Matrix operator-(const Matrix& other) {
        if (rows != other.rows || columns != other.columns) {
            cerr << "Matrix dimensions are not compatible for subtraction." << endl;
            exit(1);
        }
        Matrix result(rows, columns);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }
    Matrix operator*(const Matrix& other) {
        if (columns != other.rows) {
            cerr << "Matrix dimensions are not compatible for multiplication." << endl;
            exit(1);
        }
        Matrix result(rows, other.columns);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.columns; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < columns; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
    void display() {
        cout << "Matrix:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Matrix matrix1(2, 2);
    Matrix matrix2(2, 2);

    cout << "Matrix 1" << endl;
    matrix1.input();

    cout << "Matrix 2" << endl;
    matrix2.input();

    Matrix sum = matrix1 + matrix2;
    Matrix difference = matrix1 - matrix2;
    Matrix product = matrix1 * matrix2;

    cout << "Sum" << endl;
    sum.display();

    cout << "Difference" << endl;
    difference.display();

    cout << "Product" << endl;
    product.display();

    return 0;
}

