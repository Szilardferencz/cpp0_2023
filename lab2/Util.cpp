//
// Created by Szilárd on 10/5/2023.
//
#include <fstream>
#include "cmath"
#include "Util.h"
#include <iostream>
using namespace std;

double distance(const Point& a, const Point& b)
{
    return sqrt(((b.getX()-a.getX()) * (b.getX()-a.getX())) + ((b.getY()-a.getY()) * (b.getY()-a.getY())));
}
bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d) {
    double ab = distance(a, b);
    double bc = distance(b, c);
    double cd = distance(c, d);
    double da = distance(d, a);
    double ac = distance(a, c);

    if (ab == bc && bc == cd && cd == da) {
        if (ac == ab * sqrt(2)) {
            return true;
        }
    }
    return false;
}
void testIsSquare(const char * filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Fail" << std::endl;
        return;
    }

    Point a, b, c, d;
    int testNumber = 1;

    while (!file.eof()) {
        std::cout << "Teszt #" << testNumber << ": Pontok: "
                  << "(" << a.getX() << "," << a.getY()<< ") "
                  << "(" << b.getX()<< "," << b.getY() << ") "
                  << "(" << c.getX() << "," << c.getY() << ") "
                  << "(" << d.getX() << "," << d.getY() << ") ";

        if (isSquare(a, b, c, d)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }

        testNumber++;
    }

    file.close();
}

