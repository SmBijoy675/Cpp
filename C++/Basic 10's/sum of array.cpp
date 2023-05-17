
#include <iostream>
using namespace std;

int main() {
    const int SIZE = 5;
    int arr[SIZE];
    int sum = 0;
    cout << "Enter " << SIZE << " numbers: ";
    for (int i = 0; i < SIZE; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    cout << "Sum: " << sum << endl;
    return 0;
}
