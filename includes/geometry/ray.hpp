#ifndef RAY_H
#define RAY_H

#include <geometry/vector.hpp>

class Ray {
    public:
        Ray();
        Ray(const Vector3& origin, const Vector3& direction);

        const Vector3& origin() const;
        const Vector3& direction() const;
        Vector3 at(double t) const;

    private:
        Vector3 _origin;
        Vector3 _direction;
};

#endif
