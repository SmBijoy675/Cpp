#include <iostream>
#include <string>
using namespace std;

bool isVowel(char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

void countVowelsAndConsonants(string sentence) {
    int vowels = 0;
    int consonants = 0;
    for (char ch : sentence) {
        if (isalpha(ch)) {
            if (isVowel(ch)) {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;
}

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    countVowelsAndConsonants(sentence);
    return 0;
}
