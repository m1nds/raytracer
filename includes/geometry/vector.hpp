#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cmath>
#include <iostream>

#include <utils/point.hpp>

class Vector3 : public Point3 {
    public:
        Vector3();
        Vector3(double e0, double e1, double e2);

        Vector3 operator-() const;
        Vector3& operator+=(const Vector3& v);
        Vector3& operator*=(double t);
        Vector3& operator/=(double t);

        double length() const;
        double length_squared() const;
        bool near_zero() const;
        static Vector3 random();
        static Vector3 random(double min, double max);
};


Vector3 operator+(const Vector3& u, const Vector3& v);

Vector3 operator-(const Vector3& u, const Vector3& v);

Vector3 operator*(const Vector3& u, const Vector3& v);

Vector3 operator*(double t, const Vector3& v);

Vector3 operator*(const Vector3& v, double t);

Vector3 operator/(const Vector3& v, double t);

double dot(const Vector3& u, const Vector3& v);

Vector3 cross(const Vector3& u, const Vector3& v);

Vector3 unit_vector(const Vector3& v);
Vector3 random_unit_vector();
Vector3 random_on_hemisphere(const Vector3& v);
Vector3 reflect(const Vector3& v, const Vector3& n);
#endif
