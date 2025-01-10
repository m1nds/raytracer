#include <geometry/ray.hpp>
#include <geometry/vector.hpp>

Ray::Ray() {}
Ray::Ray(const Vector3& origin, const Vector3& direction) : _origin(origin), _direction(direction) {}

const Vector3& Ray::origin() const  {
    return this->_origin;
}

const Vector3& Ray::direction() const {
    return this->_direction;
}

Vector3 Ray::at(double t) const {
    return this->_origin + t * this->_direction;
}
