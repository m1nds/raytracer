#include <geometry/vector.hpp>
#include <geometry/ray.hpp>
#include <objects/sphere.hpp>

Sphere::Sphere(const Vector3& center, double radius) : _center(center), _radius(std::fmax(0,radius)) {}

bool Sphere::hit(const Ray& r, double ray_tmin, double ray_tmax, HitRecord& rec) const {
    Vector3 oc = this->_center - r.origin();

    auto a = r.direction().length_squared();
    auto h = dot(r.direction(), oc);
    auto c = oc.length_squared() - this->_radius * this->_radius;

    auto discriminant = h*h - a*c;
    if (discriminant < 0) {
        return false;
    }

    auto sqrtd = std::sqrt(discriminant);

    auto root = (h - sqrtd) / a;
    if (root <= ray_tmin || ray_tmax <= root) {
        root = (h + sqrtd) / a;
        if (root <= ray_tmin || ray_tmax <= root)
            return false;
    }

    rec.t = root;
    rec.p = r.at(rec.t);
    rec.normal = (rec.p - this->_center) / this->_radius;

    return true;
}
