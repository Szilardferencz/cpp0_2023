#include <iostream>
#include "stdio.h"
#include "functions.h"
#include <cmath>
using namespace std;

int main() {
    for (int i = 0; i <= 127; i++) {
        int bitCount = countBits(i);
        cout << "Szam: " << i << ", Egyes bit-ek szama: " << bitCount << std::endl;
    }

    for (int i = 0; i < 35; ++i) {
        int n = 0;
        if(setBit(n, i)){
            cout<<i<<" ---> " << n <<endl;
        }else{
            cout<<"Impossible operation!" << endl;
        }
    }

    double values[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int numElements = sizeof(values) / sizeof(values[0]);

    double average = mean(values, numElements);

    if (std::isnan(average)) {
        std::cout << "A tomb ures, NAN erteket kaptunk." << std::endl;
    } else {
        std::cout << "A tomb atlaga: " << average << std::endl;
    }
    double stdev = stddev(values, numElements);
    if (std::isnan(stdev)) {
        std::cout << "A tomb ures, NAN erteket kaptunk." << std::endl;
    } else {
        std::cout << "A tomb szorasa: " << stdev << std::endl;
    }
    std::pair<double, double> result = max2(values, numElements);
    std::cout << "A ket legnagyobb elem: " << result.first << "," << result.second << std::endl;

}