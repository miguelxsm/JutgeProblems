#include <iostream>
using namespace std;

bool vowel(char c) {
    if ((c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U')) return true;
    else return false;
}

void print_line(char c, string s, bool b) {

        cout << s << "('" << c << "') = ";
        if (b) cout << "true" << endl;
        else cout << "false" << endl;
    }

int main() {
    char c;
    string s;
    bool b;
    cin >> c;

    if ('0' <= c and c <= '9')  {
        b = false;
        s = "letter"; print_line(c, s, b);
        s = "vowel"; print_line(c, s, b);
        s = "consonant"; print_line(c, s, b);
        s = "uppercase"; print_line(c, s, b);
        s = "lowercase"; print_line(c, s, b);
        b = true;
        s = "digit";

        print_line(c, s, b);
        }
    else if ((c >= 'A' and c <= 'Z') or (c >= 'a' and c <= 'z')) {

                s = "letter";
                b = true;
                print_line(c, s, b);
                if (vowel(c)) {
                    s = "vowel";
                    b = true;
                    print_line(c, s, b);
                    s = "consonant";
                    b = false;
                    print_line(c, s, b);
                }
                else if (not vowel(c)) {
                    s = "vowel";
                    b = false;
                    print_line(c, s, b);
                    s = "consonant";
                    b = true;
                    print_line(c, s, b);
                }
            if (c >= 'A' and c <= 'Z') {
                s = "uppercase";
                b = true;
                print_line(c,s,b);
                s = "lowercase";
                b = false;
                print_line(c,s,b);
            }
            else if (c >= 'a' and c <= 'z') {
                s = "uppercase";
                b = false;
                print_line(c,s,b);
                s = "lowercase";
                b = true;
                print_line(c,s,b);
            }
            s = "digit";
            b = false;
            print_line(c, s, b);

        }

    else {
        b = false;
        s = "letter"; print_line(c,s,b);
        s = "vowel"; print_line(c,s,b);
        s = "consonant"; print_line(c,s,b);
        s = "uppercase"; print_line(c,s,b);
        s = "lowercase"; print_line(c,s,b);
        s = "digit"; print_line(c,s,b);
    }
}
