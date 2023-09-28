//
// Created by Szilárd on 9/28/2023.
//

#include "functions.h"
#include <cmath>
using namespace std;

int countBits(int number) {
    int count = 0;
    while (number > 0) {
        if (number & 1) {
            count++;
        }
        number >>= 1;
    }
    return count;
}

bool setBit(int& number, int order) {
    if (order < 0 || order > 31) {
        return false;
    }

    number |= (1 << order);
    return true;
}
double mean(double array[], int numElements) {
    if (numElements == 0) {
        return NAN;
    }

    double sum = 0.0;
    for (int i = 0; i < numElements; i++) {
        sum += array[i];
    }

    return sum / numElements;
}
double stddev(double array[], int numElements) {

    double meanValue = mean(array, numElements);

    double variance = 0.0;
    for (int i = 0; i < numElements; i++) {
        variance += (array[i] - meanValue) * (array[i] - meanValue);
    }
    variance /= numElements;

    double standardDeviation = std::sqrt(variance);
    return standardDeviation;
}
std::pair<double, double> max2(double array[], int numElements) {
    if (numElements == 0) {
        return std::make_pair(NAN, NAN);
    } else if (numElements == 1) {
        return std::make_pair(array[0], array[0]);
    }

    double largest = std::max(array[0], array[1]);
    double secondLargest = std::min(array[0], array[1]);

    for (int i = 2; i < numElements; i++) {
        if (array[i] > largest) {
            secondLargest = largest;
            largest = array[i];
        } else if (array[i] > secondLargest) {
            secondLargest = array[i];
        }
    }

    return std::make_pair(secondLargest, largest);
}
