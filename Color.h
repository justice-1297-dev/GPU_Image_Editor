#ifndef COLOR_H_
#define COLOR_H_

#include <string>
using namespace std;

namespace csci3081 {

class Color {
public:
    Color(int r, int g, int b, int a) {
        color[0] = r;
        color[1] = g;
        color[2] = b;
        color[3] = a;
    }

    int red() const { return color[0]; }
    int green() const { return color[1]; }
    int blue() const { return color[2]; }
    int alpha() const { return color[3]; }

    void setRed(int val) { color[0] = val; }
    void setGreen(int val) { color[1] = val; }
    void setBlue(int val) { color[2] = val; }
    void setAlpha(int val) { color[3] = val; }

    const unsigned char operator[](int index) const {
        // Creates a segfault in the code
        // int* a = nullptr; int b = *a; // Delete this line
        return color[index];
    }

private:
    unsigned char color[4];

};

}

#endif