//
// Created by Szilárd on 10/19/2023.
//

#include "PointSet.h"
#include <algorithm>
#include <iostream>
#include <random>

PointSet::PointSet(int n) : n(n) {
    random_device rd; // seed the random number generator named rd
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, M); // return a number in the given range
    int x;
    int y;
    for (int i = 0; i < n; i++) {
        x = dist(mt);
        y = dist(mt);
        points.push_back(Point(x, y));
    }

    computeDistances();
}

void PointSet::computeDistances() {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dist = points[i].distanceTo(points[j]);
            distances.push_back(dist);
        }
    }
}

double PointSet::maxDistance() const {
    return *max_element(distances.begin(), distances.end());
}

double PointSet::minDistance() const {
    return *min_element(distances.begin(), distances.end());
}

int PointSet::numDistances() const {
    return distances.size();
}

void PointSet::printPoints() const {
    for (const Point& p : points) {
        std::cout << "(" << p.getX() << ", " << p.getY() << ")" << std::endl;
    }
}

void PointSet::printDistances() const {
    for (double dist : distances) {
        std::cout << dist << std::endl;
    }
}

void PointSet::sortPointsX() {
    std::sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        return a.getX() < b.getX();
    });
}

void PointSet::sortPointsY() {
    std::sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        return a.getY() < b.getY();
    });
}

void PointSet::sortDistances() {
    std::sort(distances.begin(), distances.end());
}

int PointSet::numDistinctDistances() {
    std::sort(distances.begin(), distances.end());
    auto last = std::unique(distances.begin(), distances.end());
    return std::distance(distances.begin(), last);
}

