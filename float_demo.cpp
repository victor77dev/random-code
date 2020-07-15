#include <string>
#include <bitset>
#include <iostream>

using namespace std;

class float_demo_16 {
    char num[2];
    bool sign; // 1 bit
    int exp; // 5 bits
    int frac; // 11 bits

    void decTobin(int num, int base) {
        string digits = "";
        while (num > 0) {
            num = num << 2;
            if (num > base) {
                num -= base;
                digits += '1';
            } else {
                digits += '0';
            }
        }
        printf("bin: %s", digits);
    }

    void setSignExpFrac(string input) {
        exp = 0;
        frac = 0;

        const int len = input.length();
        for (int i = 0; i < len; i++) {
            char c = input[i];
            if (i == 0 && c == '-') {
                sign = true;
            } else {
                sign = false;
            }
        }
    }

    void setBinaryNum() {
        exp << 2;
        num[0] = exp & 0b01111100;
        if (sign) num[0] = num[0] | 0b10000000;
        num[1] = frac & 0b11111111;
        frac >> 8;
        num[0] = frac & 0b00000111;
    }

    public:
    float_demo_16(string input) {
    }
    float_demo_16(): float_demo_16("") {}

    float_demo_16& operator=(string input) {
        setSignExpFrac(input);
        setBinaryNum();
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
    float_demo_16 f;
    f = "0.1";
    printf("%c%c\n", f.firstChar(), f.secondChar());
    cout << f.getBits() << endl;
}
