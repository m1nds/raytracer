#include <geometry/vector.hpp>

Vector3::Vector3() : Point3(0, 0, 0) {}

Vector3::Vector3(double e0, double e1, double e2) : Point3(e0, e1, e2) {}

Vector3 Vector3::operator-() const {
    return Vector3(-e[0], -e[1], -e[2]);
}

Vector3& Vector3::operator+=(const Vector3& v) {
    e[0] += v.x();
    e[1] += v.y();
    e[2] += v.z();
    return *this;
}

Vector3& Vector3::operator*=(double t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

Vector3& Vector3::operator/=(double t) {
    return *this *= 1 / t;
}

double Vector3::length() const {
    return std::sqrt(length_squared());
}

double Vector3::length_squared() const {
    return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}

Vector3 operator+(const Vector3& u, const Vector3& v) {
    return Vector3(u.x() + v.x(), u.y() + v.y(), u.z() + v.z());
}

Vector3 operator-(const Vector3& u, const Vector3& v) {
    return Vector3(u.x() - v.x(), u.y() - v.y(), u.z() - v.z());
}

Vector3 operator*(const Vector3& u, const Vector3& v) {
    return Vector3(u.x() * v.x(), u.y() * v.y(), u.z() * v.z());
}

Vector3 operator*(double t, const Vector3& v) {
    return Vector3(t * v.x(), t * v.y(), t * v.z());
}

Vector3 operator*(const Vector3& v, double t) {
    return t * v;
}

Vector3 operator/(const Vector3& v, double t) {
    return (1 / t) * v;
}

double dot(const Vector3& u, const Vector3& v) {
    return u.x() * v.x() + u.y() * v.y() + u.z() * v.z();
}

Vector3 cross(const Vector3& u, const Vector3& v) {
    return Vector3(u.y() * v.z() - u.z() * v.y(),
                   u.z() * v.x() - u.x() * v.z(),
                   u.x() * v.y() - u.y() * v.x());
}

Vector3 unit_vector(const Vector3& v) {
    return v / v.length();
}
