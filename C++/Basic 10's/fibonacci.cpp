#include <iostream>
using namespace std;

void fibonacci(int n) {
    int first = 0;
    int second = 1;
    cout << "Fibonacci sequence up to " << n << ": ";
    cout << first << " " << second << " ";
    int next;
    for (int i = 2; i < n; i++) {
        next = first + second;
        cout << next << " ";
        first = second;
        second = next;
    }
    cout << endl;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    fibonacci(num);
    return 0;
}
