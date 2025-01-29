#ifndef HITTABLE_HPP
#define HITTABLE_HPP

#include <utils/interval.hpp>

#include <geometry/vector.hpp>
#include <geometry/ray.hpp>

#include <materials/material.hpp>

#include <memory>

class HitRecord {
    public:
        Vector3 p;
        Vector3 normal;
        std::shared_ptr<Material> material;
        double t;
        bool front_face;

        void set_face_normal(const Ray& r, const Vector3& outward_normal) {
            front_face = dot(r.direction(), outward_normal) < 0;
            normal = front_face ? outward_normal : -outward_normal;
        }
};

class Hittable {
    public:
        Hittable(std::shared_ptr<Material> material) : _material(material) {}
        virtual ~Hittable() = default;
        virtual bool hit(const Ray& r, Interval in, HitRecord& rec) const = 0;
    protected:
        std::shared_ptr<Material> _material;

};

#endif
