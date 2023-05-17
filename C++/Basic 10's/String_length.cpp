#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    int length = str.length();
    cout << "Length: " << length << endl;
    return 0;
}
