#ifndef POINT_HPP
#define POINT_HPP

#include <cmath>
#include <iostream>

#include <utils/point.hpp>

class Point3 {
    public:
        Point3();
        Point3(double e0, double e1, double e2);

        double operator[](int i) const;
        double& operator[](int i);

        double x() const;
        double y() const;
        double z() const;

    protected:
        double e[3];
};

std::ostream& operator<<(std::ostream& out, const Point3& v);

#endif
