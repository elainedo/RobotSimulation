#ifndef COLOR_H
#define COLOR_H

struct Color {
    public:
        Color(void) : r(0), g(0), b(0), a(255) {}
        Color(int in_r, int in_g, int in_b, int in_a)
            : r(in_r), g(in_g), b(in_b), a(in_a) { }
    int r;
    int g;
    int b;
    int a;
};

#endif