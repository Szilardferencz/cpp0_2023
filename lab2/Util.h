//
// Created by Szilárd on 10/5/2023.
//
#include "Point.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <bits/stdc++.h>
#include <random>
#ifndef LAB2_UTIL_H
#define LAB2_UTIL_H


double distance(const Point&, const Point&);
bool isSquare(const Point&, const Point&, const Point&, const Point&);
void testIsSquare(const char * filename);
Point* createArray(int numPoints);
void printArray(Point* points, int numPoints);
void sortPoints(Point* points, int numPoints);
void deletePoints(Point* points);


#endif //LAB2_UTIL_H
