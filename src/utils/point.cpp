#include <utils/point.hpp>

Point3::Point3() : e{0, 0, 0} {}

Point3::Point3(double e0, double e1, double e2) : e{e0, e1, e2} {}

double Point3::x() const {
    return e[0];
}

double Point3::y() const {
    return e[1];
}

double Point3::z() const {
    return e[2];
}

double Point3::operator[](int i) const {
    return e[i];
}

double& Point3::operator[](int i) {
    return e[i];
}

std::ostream& operator<<(std::ostream& out, const Point3& p) {
    return out << p.x() << ' ' << p.y() << ' ' << p.z();
}
