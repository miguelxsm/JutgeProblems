#include <iostream>
using namespace std;

// Pre: c is a lowercase letter
// Post: returns  true when c is a vowel,  returns false otherwise
bool es_vocal(char c) {
    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
}

// Pre: a lowercase letter sequence in the input
// Post: in the output appears  first input consonants in the same order,
//       then vowels in reverse order
void consonantes_vocales() {
    char c;
    while (cin >> c) {
        if (not es_vocal(c)) cout << c;
        else {
            consonantes_vocales();
            cout << c;
        }
    }
}

int main() {
    consonantes_vocales();
    cout << endl;
}
