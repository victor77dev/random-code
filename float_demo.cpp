#include <string>
#include <bitset>
#include <iostream>

using namespace std;

class float_demo_8 {
    char num[2];
    bool sign; // 1 bit
    int exp; // 5 bits
    int frac; // 11 bits

    void setExpFrac(string input) {
        exp = 0;
        frac = 0;

        for (int i = 0; i < input.length(); i++) {
            char c = input[i];
            if (i == 0 && c == '-') {
                sign = true;
            } else {
                sign = false;
            }

        }
    }

    public:
    float_demo_8(string input) {
    }
    float_demo_8(): float_demo_8(""){}

    float_demo_8& operator=(string input) {

        return *this;
    }

    char firstChar() {
        return num[0];
    }

    char secondChar() {
        return num[1];
    }

    string getBits() {
        bitset<8> first(num[0]);
        bitset<8> second(num[1]);

        return first.to_string() + second.to_string();
    }
};


int main() {
    float_demo_8 f;
    f = "0.1";
    printf("%c%c\n", f.firstChar(), f.secondChar());
    cout << f.getBits() << endl;
}