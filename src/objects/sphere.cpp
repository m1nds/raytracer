#include <geometry/vector.hpp>
#include <geometry/ray.hpp>
#include <objects/hittable.hpp>
#include <objects/sphere.hpp>
#include <materials/material.hpp>

Sphere::Sphere(const Vector3& center, double radius, std::shared_ptr<Material> material) : Hittable(material), _center(center), _radius(std::fmax(0,radius)) {}

bool Sphere::hit(const Ray& r, Interval in, HitRecord& rec) const {
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
    if (!in.surrounds(root)) {
        root = (h + sqrtd) / a;
        if (!in.surrounds(root)) {
            return false;
        }
    }

    rec.t = root;
    rec.p = r.at(rec.t);

    Vector3 outward_normal = (rec.p - this->_center) / this->_radius;
    rec.set_face_normal(r, outward_normal);
    rec.material = this->_material;

    return true;
}
